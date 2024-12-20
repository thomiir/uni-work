bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    s dd 12345607h, 1A2B3C15h
    len equ $-s 
    d times len resb 0
   
segment code use32 class=code
    start:
    mov eax, 1                ; folosim registrul eax pe post de variabila logica
    
    mov ecx, len-1            ; folosim registrul ecx pe post de contor pentru parcurgerea, 
                              ; compararea si interschimbarea elementelor
                              
    mov ebx, 0                ; folosim registrul ebx pe post de index in sirul s
    
    jecxz sfarsit             ; sarim la sfarsit daca ecx = 0
    
    compara:

        mov dh, [s+ebx]       ; in dh punem octetul de la adresa s+ebx
        
        mov dl, [s+ebx+1]     ; in dl punem octetul de la adresa s+ebx+1 (urmatorul dupa cel din dh) 
        
        cmp dh,dl             ; efectuam scaderea fictiva dh - dl
        
        jna nu_mai_mare       ; sarim peste daca dh<dl
        
            mov [s+ebx], dl   ; altfel, facem interschimbarea dh <-> dl
            mov [s+ebx+1], dh
            
            mov eax, 0        ; eax = 0 (am efectuat o interschimbare)
        
        nu_mai_mare:
        inc ebx               ; crestem indexul din sirul s
        
    loop compara              ; executam de ecx ori
    
    cmp eax, 0                ; verificam daca eax = 0 (s-a efectuat o interschimbare la ultima iteratie,
    je start                  ; in caz afirmativ, o luam de la inceput, altfel programul se opreste)
                              
    
    mov ecx, len              ; mutam in ecx lungimea sirului
    
    mov ebx, 0                ; mutam in ebx index-ul cu care pargurgem sirurile s si d
    
    jecxz sfarsit             ; sarim la sfarsit daca ecx = 0
    
    repeta:
    
        mov al, [s+ebx]       ; mutam in al octetul de la adresa s+ebx
        
        mov [d+ebx], al       ; mutam in octetul de la adresa d+ebx octetul din al
        
        inc ebx               ; crestem index-ul cu care parcurgem sirurile
   
    loop repeta
    
    sfarsit:
    push    dword 0      ; push the parameter for exit onto the stack
    call    [exit]       ; call exit to terminate the program
