bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    a db 3
    b db 5
    c db 3
    d dw 8
; our code starts here
segment code use32 class=code
    start:
        ; (d - b * c + b * 2) / a = (8 - 5 * 3 + 5 * 2) / 3 = (8 - 15 + 10) / 3 = 3 / 3 = 1
        mov bx, [d]  ; bx = d
        
        mov al, [b]  ; al = b
        mul byte [c] ; ax = al * c = b * c
        
        sub bx, ax   ; bx = bx - ax = d - b * c
        
        mov al, [b]  ; al = b
        mov cl, 2
        mul cl   ; ax = b * 2
        
        add bx, ax   ; bx = bx + ax = d - b * c + b * 2
        
        mov ax, bx   ; ax = bx = d - b * c + b * 2
        
        mov bl, [a]  ; bl = a

        div bl  ; al = ax / bl =  (d - b * c + b * 2) / a
        
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
