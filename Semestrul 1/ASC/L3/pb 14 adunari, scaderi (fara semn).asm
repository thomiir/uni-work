bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    a db 1
    b dw 2
    c dd 3
    d dq 4

; our code starts here
segment code use32 class=code
    start:
        ;edx : eax = d
        ;ecx : ebx = a
        ; (a + d) - (c - b) + c = (1 + 4) - (3 - 2) + 3 = 5 - 1 + 3 = 7
        mov eax, dword [d]
        mov edx, dword [d+4]; edx : eax = d
        
        mov ecx, 0
        mov ebx, 0
        mov bl, [a] ; ecx : ebx = a
        
        add ebx, eax
        adc ecx, edx ; ecx : ebx = (a + d)
        
        mov eax, [c] ; eax = c
        
        mov edx, 0  
        mov dx, [b]  ; edx = b
        
        sub eax, edx ; eax = eax - edx = (c - b)
        
        mov edx, 0   ; edx : eax = (c - b)
                     ; ecx : ebx = (a + d)
        sub ebx, eax
        sbb ecx, edx ; ecx : ebx = (a + d) - (c - b)
        
        mov edx, 0
        mov eax, [c] ; edx : eax = c
        
        add ebx, eax
        adc ecx, edx ; ecx : ebx = (a + d) - (c - b) + c      
        
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
