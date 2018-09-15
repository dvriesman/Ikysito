#include <gdt.h>


struct gdt_entry gdt[3];
struct gdt_ptr gp;

void gdt_load() {

      __asm__ __volatile__ ("cli");

      __asm__ __volatile__ ("lgdtl %0           \n"
        /* Reload DATA segment */
        "movw %1,   %%ax    \n"
        "movw %%ax, %%ds    \n"
        "movw %%ax, %%es    \n"
        "movw %%ax, %%fs    \n"
        "movw %%ax, %%gs    \n"
        "movw %%ax, %%ss    \n"
        /* Reload CODE segment */
        "ljmp %2, $reloadCS \n"
        "reloadCS:            "
            : : "m" (gp), "I" (0x10), "I" (0x08) : "eax");

}

void gdt_set_entry(int num, unsigned long base, unsigned long limit, unsigned char access, unsigned char gran)
{
    /* Setup the descriptor base address */
    gdt[num].base_low = (base & 0xFFFF);
    gdt[num].base_middle = (base >> 16) & 0xFF;
    gdt[num].base_high = (base >> 24) & 0xFF;

    /* Setup the descriptor limits */
    gdt[num].limit_low = (limit & 0xFFFF);
    gdt[num].granularity = ((limit >> 16) & 0x0F);

    /* Finally, set up the granularity and access flags */
    gdt[num].granularity |= (gran & 0xF0);
    gdt[num].access = access;
}

void gdt_install()
{
    gp.limit = (sizeof(struct gdt_entry) * 3) - 1;
    gp.base = (unsigned int) &gdt;
    gdt_set_entry(0, 0, 0, 0, 0);
    gdt_set_entry(1, 0, 0xFFFFFFFF, 0x9A, 0xCF);
    gdt_set_entry(2, 0, 0xFFFFFFFF, 0x92, 0xCF);

    gdt_load();
}

