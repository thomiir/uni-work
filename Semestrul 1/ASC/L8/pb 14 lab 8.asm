bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit, printf, scanf               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
import printf msvcrt.dll  ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions
import scanf msvcrt.dll
; our data is declared here (the variables needed by our program)
segment data use32 class=data
    a dd 0
    b dd 0
    message db "a + b (in baza 10) = %d", 0
    read_a db "a = ", 0
    read_b db "b = ", 0
    format db "%x", 0

; our code starts here
segment code use32 class=code
    start:
        
        push dword read_a   ; punem in stiva adresa mesajului "a = "
        call [printf]       ; apelam functia printf pentru a afisa mesajul
        add esp, 4          ; mutam pointerul esp cu 4 pozitii 
        
        push dword a        ; punem in stiva adresa variabilei a
        push dword format   ; punem in stiva formatul "%x" (hex)
        call [scanf]        ; apelam functia scanf pentru a citi variabila a
        add esp, 4 * 2      ; mutam pointerul esp cu 8 pozitii 
        
        mov eax, [a]        ; punem in eax valoarea variabilei a
        push eax            ; punem eax in stiva deoarece functia scanf ii modifica valoarea
        
        push dword read_b   ; punem in stiva mesajul "b = "
        call [printf]       ; afisam mesajul
        add esp, 4          ; mutam pointerul esp cu 4 pozitii 
        
        push dword b        ; punem in stiva adresa variabilei b
        push dword format   ; punem in stiva formatul "%x" (hex)
        call [scanf]        ; apelam functia scanf pentru a citi variabila a
        add esp, 4 * 2      ; mutam pointerul esp cu 8 pozitii 
        
        mov ebx, [b]        ; punem in ebx valoarea variabilei b
        pop eax             ; il scoatem pe eax din stiva
        add eax, ebx        ; la eax adunam ebx, eax = a + b (hex)
        
        push eax            ; punem in stiva registrul eax
        push dword message  ; punem in stiva adresa mesajului message
        call [printf]       ; apelam functia printf pentru a afisa mesajul 
        add esp, 4 * 2      ; mutam pointerul esp cu 8 pozitii 
        
        
        push    dword 0     ; push the parameter for exit onto the stack
        call    [exit]      ; call exit to terminate the program
