CFLAGS  := -m32 -fno-stack-protector -fno-builtin -nostdinc -O -g -Wall -I.
LDFLAGS := -nostdlib -Wl,-N -Wl,-Ttext -Wl,100000

all:	Release

Release:	start.o	main.o gdt.o util.o crt.o idt.o isr.o keyboard.o
	ld -melf_i386 -T link.ld -o ../bin/kernel.bin start.o gdt.o main.o util.o crt.o idt.o isr.o keyboard.o
	@echo Done!

start.o: start.asm
	nasm  -f elf -o start.o start.asm

isr.o: isr.asm
	nasm -f elf -o isr.o isr.asm

main.o: main.c crt.h
	gcc $(CFLAGS) -c -o main.o main.c

util.o: util.c util.h
	gcc  $(CFLAGS) -c -o util.o util.c

crt.o: crt.c crt.h
	 gcc $(CFLAGS) -c -o crt.o crt.c

idt.o: idt.c idt.h
	gcc  $(CFLAGS) -c -o idt.o idt.c

keyboard.o: keyboard.c keyboard.h
	gcc  $(CFLAGS) -c -o keyboard.o keyboard.c

gdt.o: gdt.c gdt.h
	gcc  $(CFLAGS) -c -o gdt.o gdt.c


clean:
	rm -f *.o *.bin
