global isr0
global isr1
global isr2
global isr3
global isr4
global isr5
global isr6
global isr7
global isr8
global isr9
global isr10
global isr11
global isr12
global isr13
global isr14
global isr15
global isr16
global isr17
global isr18
global isr19
global isr20
global isr21
global isr22
global isr23
global isr24
global isr25
global isr26
global isr27
global isr28
global isr29
global isr30
global isr31
global isr32
global isr33
global isr34
global isr35
global isr36
global isr37
global isr38
global isr39
global isr40
global isr41
global isr42
global isr43
global isr44
global isr45
global isr46
global isr47
global isr48
global isr49
global isr50





extern irq_handler

isr0:
    cli
    push byte 0
    push byte 0
    jmp irq_stub

isr1:
    cli
    push byte 0
    push byte 1
    jmp irq_stub


isr2:
    cli
    push byte 0
    push byte 2
    jmp irq_stub


isr3:
    cli
    push byte 0
    push byte 3
    jmp irq_stub


isr4:
    cli
    push byte 0
    push byte 4
    jmp irq_stub


isr5:
    cli
    push byte 0
    push byte 5
    jmp irq_stub


isr6:
    cli
    push byte 0
    push byte 6
    jmp irq_stub


isr7:
    cli
    push byte 0
    push byte 7
    jmp irq_stub


isr8:
    cli
    push byte 0
    push byte 8
    jmp irq_stub


isr9:
    cli
    push byte 0
    push byte 9
    jmp irq_stub

isr10:
    cli
    push byte 0
    push byte 10
    jmp irq_stub


isr11:
    cli
    push byte 0
    push byte 11
    jmp irq_stub


isr12:
    cli
    push byte 0
    push byte 12
    jmp irq_stub


isr13:
    cli
    push byte 0
    push byte 13
    jmp irq_stub


isr14:
    cli
    push byte 0
    push byte 14
    jmp irq_stub


isr15:
    cli
    push byte 0
    push byte 15
    jmp irq_stub


isr16:
    cli
    push byte 0
    push byte 16
    jmp irq_stub

isr17:
    cli
    push byte 0
    push byte 17
    jmp irq_stub

isr18:
    cli
    push byte 0
    push byte 18
    jmp irq_stub

isr19:
    cli
    push byte 0
    push byte 19
    jmp irq_stub

isr20:
    cli
    push byte 0
    push byte 20
    jmp irq_stub

isr21:
    cli
    push byte 0
    push byte 21
    jmp irq_stub

isr22:
    cli
    push byte 0
    push byte 22
    jmp irq_stub

isr23:
    cli
    push byte 0
    push byte 23
    jmp irq_stub

isr24:
    cli
    push byte 0
    push byte 24
    jmp irq_stub

isr25:
    cli
    push byte 0
    push byte 25
    jmp irq_stub

isr26:
    cli
    push byte 0
    push byte 26
    jmp irq_stub

isr27:
    cli
    push byte 0
    push byte 27
    jmp irq_stub

isr28:
    cli
    push byte 0
    push byte 28
    jmp irq_stub

isr29:
    cli
    push byte 0
    push byte 29
    jmp irq_stub

isr30:
    cli
    push byte 0
    push byte 30
    jmp irq_stub

isr31:
    cli
    push byte 0
    push byte 31
    jmp irq_stub

isr32:
    cli
    push byte 0
    push byte 32
    jmp irq_stub

isr33:
    cli
    push byte 0
    push byte 33
    jmp irq_stub

isr34:
    cli
    push byte 0
    push byte 34
    jmp irq_stub

isr35:
    cli
    push byte 0
    push byte 35
    jmp irq_stub

isr36:
    cli
    push byte 0
    push byte 36
    jmp irq_stub

isr37:
    cli
    push byte 0
    push byte 37
    jmp irq_stub

isr38:
    cli
    push byte 0
    push byte 38
    jmp irq_stub

isr39:
    cli
    push byte 0
    push byte 39
    jmp irq_stub

isr40:
    cli
    push byte 0
    push byte 40
    jmp irq_stub

isr41:
    cli
    push byte 0
    push byte 41
    jmp irq_stub

isr42:
    cli
    push byte 0
    push byte 42
    jmp irq_stub

isr43:
    cli
    push byte 0
    push byte 43
    jmp irq_stub

isr44:
    cli
    push byte 0
    push byte 44
    jmp irq_stub

isr45:
    cli
    push byte 0
    push byte 45
    jmp irq_stub

isr46:
    cli
    push byte 0
    push byte 46
    jmp irq_stub

isr47:
    cli
    push byte 0
    push byte 47
    jmp irq_stub

isr48:
    cli
    push byte 0
    push byte 48
    jmp irq_stub

isr49:
    cli
    push byte 0
    push byte 49
    jmp irq_stub

isr50:
    cli
    push byte 0
    push byte 50
    jmp irq_stub

irq_stub:
    pusha
    push ds
    push es
    push fs
    push gs
    mov ax, 0x10
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    mov eax, esp
    push eax
    mov eax, irq_handler
    call eax
    pop eax
    pop gs
    pop fs
    pop es
    pop ds
    popa
    add esp, 8
    iret
