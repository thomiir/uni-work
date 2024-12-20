bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    A dw 0001101011000101b
    B dw 1100111110010100b
    C dw 0111001101011101b
    D resb 1
    E resb 1
    F resb 1

; our code starts here
segment code use32 class=code
    start:
        mov ax, 0000000000011111b
        and ax, [A] ; ax = 0000000000000101b (pastram bitii 0-4)
                    ; al = 00000101b

            
        mov bx, 0000000000011111b
        mov cx, [B] ; cx = 1100111110010100b (mutam in cx variabila B)
        ror cx, 5   ; cx = 1010011001111100b (rotim la dreapta cu 5 pozitii)
        and bx, cx  ; bx = 0000000000011100b (pastram bitii 0-4)
        add al, bl  ; al = 00000101b + 00011100b = 00100001b (adunam la al pe bl)
        mov [D], al ; D = 00100001b = 21h (mutam in D rezultatul din al)

        mov bx, 0000000000011111b
        mov cx, [C] ; cx = 0111001101011101b (punem 
        ror cx, 10  ; cx = 1101011101011100b (rotim la dreapta cu 10 biti)
        and bx, cx  ; bx = 0000000000011100b (pastram bitii 0-4)
                    ; bl = 00011100b
        mov [E], bl ; E = 00011100b = 1Ch (mutam in E continutul registrului bl)
        
        mov al, [D] ; al = 21h (mutam in al variabila D)
        sub al, [E] ; al = al - E = 00100001b - 00011100b = 00000101b = 5h (din al scadem variabila E)
        mov [F], al ; F = 00000101b = 5h (F = D - E)
        
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
