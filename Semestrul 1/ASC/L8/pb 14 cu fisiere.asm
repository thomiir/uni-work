bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit, fopen, fclose, fprintf; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
import fopen msvcrt.dll   ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions
import fclose msvcrt.dll
import fprintf msvcrt.dll
; our data is declared here (the variables needed by our program)
segment data use32 class=data
    nume_fisier db "problema14.txt", 0
    mod_acces db "w", 0
    descriptor_fisier dd -1
    text db "abcdeABCDe12?!", 0
    len equ $-text

; our code starts here
segment code use32 class=code
    start:
        mov ecx, len                   ; punem in ecx lungimea textului
        mov ebx, 0                     ; punem in ebx index-ul pe care il folosim pentru text
        mov al, 'A' - 'a'              ; punem in al diferenta 'A' - 'a'
        jecxz final                    ; sarim la final daca ecx = 0
        repeta:
            cmp byte [text + ebx], 'A' ; comparam la nivel de octet caracterul curent de la adresa [text + ebx]
            jnae fin                   ; daca [text + ebx] < 'A' inseamna ca nu este litera mare 
            cmp byte [text + ebx], 'Z' ; comparam la nivel de octet elementul curent de la adresa [text + ebx]
            jnbe fin                   ; daca [text + ebx] > 'Z' inseamna ca nu este litera mare
            sub [text + ebx], al       ; daca este litera mare, scadem 'A' - 'a'
            fin:
                inc ebx                ; crestem ebx ca sa trecem la urmatorul caracter din text
        loop repeta                    ; repetam loop-ul pana cand ecx = 0 (am terminat toate caracterele din text)
         
        push dword mod_acces           ; punem pe stiva modul de acces
        push dword nume_fisier         ; punem pe stiva numele fisierului
        call [fopen]                   ; deschidem fisierul
        add esp, 4 * 2                 ; mutam pointerul esp cu 8 pozitii
        
        mov [descriptor_fisier], eax   ; mutam in descriptorul fisierului valoarea din registrul eax
        cmp eax, 0                     ; comparam eax cu 0
        je final                       ; daca este 0, inseamna ca fisierul nu s-a deschis cum trebuie si sarim la final
        push dword text                ; punem pe stiva adresa textului care trebuie afisat
        push dword [descriptor_fisier] ; punem pe stiva descriptorul fisierului
        call [fprintf]                 ; scriem in fisier textul
        add esp, 4 * 2                 ; mutam pointerul esp cu 8 pozitii 
        
        push dword [descriptor_fisier] ; punem pe stiva descriptorul fisierului
        call [fclose]                  ; inchidem fisierul
        add esp, 4 * 2                 ; mutam pointerul esp cu 8 pozitii
        
        final:
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
