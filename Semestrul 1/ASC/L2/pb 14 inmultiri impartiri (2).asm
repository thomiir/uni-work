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
    d db 20
    e dw 30
    f dw 15

; our code starts here
segment code use32 class=code
    start:
        ; a * d * e / (f - 5) = 10 * 20 * 30 / (15 - 5) = 6000 / 10 = 600
        mov al, [a]  ; al = a
        mul byte [d] ; ax = al * d = a * d
        mul word [e] ; dx : ax = a * d * e
        
        mov bx, [f]  ; bx = f
        sub bx, 5    ; bx = bx - 5 = f - 5
        
        div word bx  ; dx : ax = dx : ax / bx -> ax = a * d * e / (f - 5)
        
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
