bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    a db 1
    b dw 2
    c dd 3

; our code starts here
segment code use32 class=code
    start:
        ;c - b - (a + a) - b = 3 - 2 - (1 + 1) - 2 = 1 - 2 - 2 = -3
        mov ax, [b]
        cwde ; eax = b
        mov ebx, [c]
        sub ebx, eax ; ebx = ebx - eax = c - b
        
        mov al, [a]
        add al, [a]  ; al = a + a
        
        cbw
        cwde ; eax = a + a
        
        sub ebx, eax ; ebx = c - b - (a + a)
        
        mov eax, 0
        mov ax, [b] ; eax = b
        
        sub ebx, eax ; ebx = c - b - (a + a) - b

        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
