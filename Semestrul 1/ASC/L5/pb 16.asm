bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    S1 db 'a', 'b', 'c', 'b', 'e', 'f'
    lungime_S1 equ $-S1
    S2 db '1', '2', '3', '4', '5'
    lungime_S2 equ $-S2
    D times lungime_S1+lungime_S2 db 0
    
; our code starts here
segment code use32 class=code
    start:
        mov ecx, lungime_S2
        mov eax, 0  ; cu eax ne deplasam in S2
        mov esi, 0  ; cu esi ne deplasam in D
        jecxz sfarsit_repeta1
        repeta_1:
            mov dl, [S2+eax] ; punem in registrul dl valorile S2[0], S2[2]... care corespund S2[1], S2[3].. din cerinta
            mov [D+esi], dl    ; punem in D[0], D[1]... valoarea din registrul dl 
            add eax, 2         ; ne mutam la urmatorul element din S2
            inc esi            ; crestem lungimea lui D
        loop repeta_1 ; am mutat in D toate elementele de pe pozitii impare din S2

        sfarsit_repeta1:
        mov ecx, lungime_S1
        mov eax, 0  ; cu eax ne deplasam in S1
                    ; esi ramane la aceeasi valoare din bucla trecuta
        jecxz sfarsit_repeta2
        repeta_2:
            mov dl, [S1+1+eax] ; punem in registrul dl valorile S1[1], S1[3]... care corespund S1[2], S1[4].. din cerinta
            mov [D+esi], dl      ; punem in D[esi] ramas din bucla trecuta valoarea din registrul dl
            add eax, 2           ; ne mutam la urmatorul element din S1
            inc esi              ; crestem lungimea lui D
         loop repeta_2 ; am concatenat la D toate elementele de pe pozitii pare din S1
        
        sfarsit_repeta2:
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
