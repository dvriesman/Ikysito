#include <idt.h>

struct idt_entry idt[256];
struct idt_prt idtp;

void idt_set_entry(unsigned char num, unsigned long base, unsigned short sel, unsigned char flags) {

    idt[num].base_lo = (base & 0xFFFF);
    idt[num].base_hi = (base >> 16) & 0xFFFF;
    idt[num].sel = sel;
    idt[num].always0 = 0;
    idt[num].flags = flags;

}

void idt_load() {
    __asm__ __volatile__ ("cli");
    __asm__ __volatile__ ("lidtl %0" : : "m" (idtp));
}

void idt_install() {

    idtp.limit = (sizeof(struct idt_entry) * 256) -1;
    idtp.base = ( unsigned int) &idt;

    memsetA(&idt, 0, sizeof(struct idt_entry) * 256);

    //use aqui os set_entry
    //Originalmente a IRQ 0 a 7 é mapeada na IDT 8 a 15.
    //IRQ 1 é o teclado, então queremos setar a IDT 9 ok !

    idt_set_entry(0, (unsigned) isr0, 0x08, 0x8E);
    idt_set_entry(1, (unsigned) isr1, 0x08, 0x8E);
    idt_set_entry(2, (unsigned) isr2, 0x08, 0x8E);
    idt_set_entry(3, (unsigned) isr3, 0x08, 0x8E);
    idt_set_entry(4, (unsigned) isr4, 0x08, 0x8E);
    idt_set_entry(5, (unsigned) isr5, 0x08, 0x8E);
    idt_set_entry(6, (unsigned) isr6, 0x08, 0x8E);
    idt_set_entry(7, (unsigned) isr7, 0x08, 0x8E);
    idt_set_entry(8, (unsigned) isr8, 0x08, 0x8E);
    idt_set_entry(9, (unsigned) isr9, 0x08, 0x8E);
    idt_set_entry(10, (unsigned) isr10, 0x08, 0x8E);
    idt_set_entry(11, (unsigned) isr11, 0x08, 0x8E);
    idt_set_entry(12, (unsigned) isr12, 0x08, 0x8E);
    idt_set_entry(13, (unsigned) isr13, 0x08, 0x8E);
    idt_set_entry(14, (unsigned) isr14, 0x08, 0x8E);
    idt_set_entry(15, (unsigned) isr15, 0x08, 0x8E);
    idt_set_entry(16, (unsigned) isr16, 0x08, 0x8E);
    idt_set_entry(17, (unsigned) isr17, 0x08, 0x8E);
    idt_set_entry(18, (unsigned) isr18, 0x08, 0x8E);
    idt_set_entry(19, (unsigned) isr19, 0x08, 0x8E);
    idt_set_entry(20, (unsigned) isr20, 0x08, 0x8E);
    idt_set_entry(21, (unsigned) isr21, 0x08, 0x8E);
    idt_set_entry(22, (unsigned) isr22, 0x08, 0x8E);
    idt_set_entry(23, (unsigned) isr23, 0x08, 0x8E);
    idt_set_entry(24, (unsigned) isr24, 0x08, 0x8E);
    idt_set_entry(25, (unsigned) isr25, 0x08, 0x8E);
    idt_set_entry(26, (unsigned) isr26, 0x08, 0x8E);
    idt_set_entry(27, (unsigned) isr27, 0x08, 0x8E);
    idt_set_entry(28, (unsigned) isr28, 0x08, 0x8E);
    idt_set_entry(29, (unsigned) isr29, 0x08, 0x8E);
    idt_set_entry(30, (unsigned) isr30, 0x08, 0x8E);
    idt_set_entry(31, (unsigned) isr31, 0x08, 0x8E);
    idt_set_entry(32, (unsigned) isr32, 0x08, 0x8E);
    idt_set_entry(33, (unsigned) isr33, 0x08, 0x8E);
    idt_set_entry(34, (unsigned) isr34, 0x08, 0x8E);
    idt_set_entry(35, (unsigned) isr35, 0x08, 0x8E);
    idt_set_entry(36, (unsigned) isr36, 0x08, 0x8E);
    idt_set_entry(37, (unsigned) isr37, 0x08, 0x8E);
    idt_set_entry(38, (unsigned) isr38, 0x08, 0x8E);
    idt_set_entry(39, (unsigned) isr39, 0x08, 0x8E);
    idt_set_entry(40, (unsigned) isr40, 0x08, 0x8E);
    idt_set_entry(41, (unsigned) isr41, 0x08, 0x8E);
    idt_set_entry(42, (unsigned) isr42, 0x08, 0x8E);
    idt_set_entry(43, (unsigned) isr43, 0x08, 0x8E);
    idt_set_entry(44, (unsigned) isr44, 0x08, 0x8E);
    idt_set_entry(45, (unsigned) isr45, 0x08, 0x8E);
    idt_set_entry(46, (unsigned) isr46, 0x08, 0x8E);
    idt_set_entry(47, (unsigned) isr47, 0x08, 0x8E);
    idt_set_entry(48, (unsigned) isr48, 0x08, 0x8E);
    idt_set_entry(49, (unsigned) isr49, 0x08, 0x8E);
    idt_set_entry(50, (unsigned) isr50, 0x08, 0x8E);


    //puts ((unsigned char*)"\nLendo IDT...");

    idt_load();

    //puts ((unsigned char*)"\nIDT Lido com sucesso...");

}

void irq_handler(struct regs *r) {


    //A IRQ1 que é do teclado estah mapeada para ISR 9.
    if (r->int_no == 9) {
        keyboard_handler();
    }

    //Informa para a PIC que terminou o processamento da interrupcao
    if (r->int_no >= 8) {
        outportb(0xA0, 0x20);
    }
    outportb(0x20, 0x20);

}

