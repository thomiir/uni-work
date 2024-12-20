bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    a db 20
    b db 30 
    c db 40
    d db 50

; our code starts here
segment code use32 class=code
    start:
        ; (b + c) + (a + b - d) = (30 + 40) + (20 + 30 - 50) = 70 + 0 = 70
        mov al, [b] ; al = b
        add al, [c] ; al = al + c = b + c
        
        mov bl, [a] ; bl = a
        add bl, [b] ; bl = bl + b = a + b
        sub bl, [d] ; bl = bl - d = a + b - d
        
        add al, bl ; al = al + bl = (b + c) + (a + b - d)
    
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
