bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    a db 01101010b 
    b db 00011000b 
    c db 11110101b 
    d db 10010100b 
    ;bits76543210

; our code starts here
segment code use32 class=code
    start:
    
        mov al, 01110000b
        and al, [a]      ; al = 01100000b = 60h (pastram doar bitii 4-6 ai lui a) 
        mov ah, 0        ; ax = 00000000 01100000b = 60h
        
        mov bl, 01110000b
        and bl, [b]      ; bl = 00010000b = 10h (pastram doar bitii 4-6 ai lui b)
        mov bh, 0        ; bx = 00000000 00010000b = 10h (zerorizam bh ca sa putem sa adunam la ax)
        add ax, bx       ; ax = ax + bx = 00000000 01110000b = 70h (la ax il adunam pe bx)

        mov bl, 01110000b
        and bl, [c]      ; bl = 01110000b = 7h (pastram doar bitii 4-6 ai lui c)
        mov bh, 0        ; bx = 00000000 01110000b = 7h (zerorizam bh ca sa putem sa adunam la ax) 
        add ax, bx       ; ax = ax + bx = 00000000 01110000b + 00000000 01110000b = 00000000 11100000b = E0h (la ax il adunam pe bx)
        
        mov bl, 01110000b
        and bl, [d]      ; bl = 00010000b = 10h (pastram doar bitii 4-6 ai lui d)
        mov bh, 0        ; bx = 00000000 00010000b = 10h (zerorizam bh ca sa putem sa adunam la ax)
        add ax, bx       ; ax = ax + bx = 00000000 11100000 + 00000000 00010000 = 00000000 11110000b = F0h (la ax il adunam pe bx)

        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
