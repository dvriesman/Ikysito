[BITS 16]       ; 16 bit instructions
[ORG 0x07C0]

jmp start

gdt:                    ; address for the GDT
        dd 0
        dd 0


;gdt_code:               ; code segment, read/execute, nonconforming
        dw 0xFFFF
        dw 0
        db 0
        db 0x9A
        db 0xCF
        db 0

;gdt_data:               ; data segment, read/write, expand down
        dw 0xFFFF
        dw 0
        db 0
        db 0x92
        db 0xCF
        db 0

gdt_end: 

gdt_desc: 
        dw gdt_end - gdt - 1    ; limit (size)
        dd gdt                  ; address of the GDT


start:

	mov ax, 0X0000
        mov ds, ax
        mov es, ax	

load:

	mov ax, 0           ;
        mov dl, 0           ; Drive=0 (=A)
        int 0x13            ;
        jc load             ; ERROR => reset again        



read:
            mov ax, 0x1000      ; ES:BX = 1000:0000
            mov es, ax          ;
            mov bx, 0           ;

            mov ah, 2           ; Load disk data to ES:BX
            mov al, 2           ; Load 5 sectors
            mov ch, 0           ; Cylinder=0
            mov cl, 2           ; Sector=2
            mov dh, 0           ; Head=0
            mov dl, 0           ; Drive=0
            int 0x13            ; Read!

            jc read             ; ERROR => Try again

	    cli                     ; Disable interrupts

            xor ax, ax
            mov ds, ax              ; Set DS-register to 0 - used by lgdt

            lgdt [gdt_desc]         ; Load the GDT descriptor


            mov eax, cr0               ; Copy the contents of CR0 into EAX
            or eax, 1                  ;  Set bit 0
            mov cr0, eax               ; Copy the contents of EAX into CR0


            jmp 0x8:kernel_seg		
	

bits 32

kernel_seg:

        mov ax, 0x10                     ; Save data segment identifyer
        mov ds, ax                      ; Move a valid data segment into the data segment register
        mov ss, ax                      ; Move a valid data segment into the stack segment register
        mov esp, 090000h                ; Move the stack pointer to 090000h




	jmp 0x8:0x1000                  ; jump to our kernel



times 510-($-$$) db 0           ; fill up the file with zeros

        dw 0AA55h               ; boot sector identifier
