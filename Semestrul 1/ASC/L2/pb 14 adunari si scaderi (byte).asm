bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    a db 10
    b db 20
    c db 40
    d db 30

; our code starts here
segment code use32 class=code
    start:
        ;(a + d - c) - (b + b) = (10 + 30 - 40) - (20 + 20) = 0 - 40 = -40
        mov al, [a] ; al = a
        add al, [d] ; al = al + d = a + d  
        sub al, [c] ; al = al - c = a + d - c
        
        mov bl, [b] ; bl = b
        add bl, [b] ; bl = bl + b = b + b
        
        sub al, bl ; al = al - bl = (a + d - c) - (b + b) 
        
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
