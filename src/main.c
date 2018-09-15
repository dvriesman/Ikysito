#include <crt.h>
#include <idt.h>
#include <gdt.h>
#include <keyboard.h>


void cmain (unsigned long magic, unsigned long addr)
{

  gdt_install();
  init_video();
  puts ((unsigned char*)"Ikysito OS (Iva) - Denny R S Vriesman\n");

  init_keyboard();
  puts ((unsigned char*)"Teclado ABNT-2 Carregado\n");


  idt_install();

  puts ((unsigned char*)"IDT Instalado- OK\n\n");

  __asm__ __volatile__ ("sti");

  while (1) {

    puts ((unsigned char*)"Ikysito:$> ");
    unsigned char *line = readLine();

    if (strcmp(line, "ver") == 0) {
        puts ((unsigned char*)"Ikysito OS - Versao 0.1\n");
        puts ((unsigned char*)"Desevolvido por Denny Richard San Vriesman\n\n");
    } else {
        if (strcmp(line, "cls") == 0) {
            cls();
        } else {

            if (strcmp(line, "info") == 0) {
                puts ((unsigned char*)"Kernel info:\n");
                puts ((unsigned char*)"Endereco de main:\n");
                puts ((unsigned char*)"Endereco de cmain:\n");
                puts ((unsigned char*)"Memoria total:\n\n");


            }
        }
    }

  }

}

