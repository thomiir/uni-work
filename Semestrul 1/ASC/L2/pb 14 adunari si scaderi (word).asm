bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    a dw 20
    b dw 30
    c dw 40
    d dw 50

; our code starts here
segment code use32 class=code
    start:
        ; (c + d) + (a - b) + a = (40 + 50) + (20 - 30) + 20 = 90 - 10 + 20 = 100
        mov ax, [c] ; ax = c
        add ax, [d] ; ax = ax + d = c + d
        
        mov bx, [a] ; bx = a
        sub bx, [b] ; bx = a - b
        
        add ax, bx  ; ax = ax + bx = (c + d) + (a - b)
        
        add ax, [c] ; ax = ax + c = (c + d) + (a - b) + c
        
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
