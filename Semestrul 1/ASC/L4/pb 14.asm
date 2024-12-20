bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    A dd 11110010100001010010010001011100b
    B resd 1
    C resd 1
    n resb 1

; our code starts here
segment code use32 class=code
    start:
    mov eax, [A] ; eax = 11110010100001010010010001011100b (mutam in eax variabila A)
    ror eax, 14  ; eax = 10010001011100111100101000010100b (rotim bitii lui A cu 14 pozitii)
    and al, 00001111b ; al = 00000100b = 4h (pastram doar cei mai putin semnificativi 4 biti)
    mov [n], al ; n = 00000100b = 4h (mutam in n valoarea obtinuta)
    
    mov eax, [A] ; eax = 11110010100001010010010001011100b (
    mov cl, [n]
    rol eax, cl ; eax = 00101000010100100100010111001111b (rotim eax cu cl pozitii spre stanga) 
    mov [B], eax ; B = 00101000010100100100010111001111b (mutam in B continutul registrului eax)
    
    mov eax, [B]      ; eax = 00101000010100100100010111001111b (mutam in eax variabila B)
    ror eax, 1        ; eax = 10010100001010010010001011100111b (rotim la dreapta cu o pozitie)
    and al, 00111111b ; al = 00100111b = 27h = 39 (pastram bitii 0-5)
    mov ebx, [B]
    ror ebx, 17       ; ebx = 00100010111001111001010000101001b (mutam in ebx variabila B)
    and bl, 11000000b ; bl = 00000000b (pastram bitii 6-7)
    add al, bl        ; al = 00100111b = 27h = 39 (adunam la al pe bl)
    mov [C], al       ; (mutam in C pe al)
    
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
