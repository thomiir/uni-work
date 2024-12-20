bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    S db 1, 3, -2, -5, 3 ,-8, 5, 0
    lungime equ $-S
    D1 times lungime db 0
    D2 times lungime db 0

; our code starts here
segment code use32 class=code
    start:
        mov ecx, lungime
        mov esi, 0
        mov eax, 0   ; lungimea sirului D1 - contine numerele pozitive (si 0)
        mov ebx, 0   ; lungimea sirului D2 - contine numerele negative
        jecxz sfarsit
        repeta:
            mov dl, [S+esi]
            cmp dl, 0             ; scadere fictiva dl - 0, daca dl>=0 atunci punem valoarea in D1, altfel o punem in D2
            jge muta_D1           ; (mai mare sau egal decat 0)
                
                ;daca este mai mic decat 0
            mov [D2+ebx], dl   ; punem in D2 valoarea din dl
            inc ebx            ; crestem lungimea lui D2
            jmp mai_departe    ; sarim peste instructiunile din D1
            
                muta_D1:
            mov [D1+eax], dl   ; punem in D1 valoarea din dl
            inc eax            ; crestem lungimea lui D1
            
            mai_departe:
            inc esi
            loop repeta               ; cat timp ecx != 0
        
        sfarsit:
        
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
