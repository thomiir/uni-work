bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    a dw 50
    b dw 60
    c dw 70
    d dw 80
; our code starts here
segment code use32 class=code
    start:
        ; (d - a) + (b + b + c) = (80 - 50) + (60 + 60 + 70) = 30 + 190 = 220
        mov ax, [d] ; ax = d
        sub ax, [a] ; ax = ax - a = d - a
        
        mov bx, [b] ; bx = b
        add bx, [b] ; bx = bx + b = b + b
        add bx, [c] ; bx = bx - c = b + b + c
        
        add ax, bx ; ax = ax + bx = (d - a) + (b + b + c) 
    
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
