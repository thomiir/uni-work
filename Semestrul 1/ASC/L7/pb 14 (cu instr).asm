bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    s dd 12345607h, 1A2B3CF5h
    len equ $-s 
    d times len resb 0

segment code use32 class=code
    start:
    cld                       ; setam direction flag la 0 ca sa parcurgem s de la 0 la len(s) - 1
    
    mov eax, 1                ; folosim registrul eax pe post de variabila logica
    
    mov ecx, len-1            ; folosim registrul ecx pe post de contor pentru parcurgerea, 
                              ; compararea si interschimbarea elementelor
    
    mov esi, s                ; punem in registrul esi adresa primului element din s
    
    mov edi, s+1              ; punem in registrul edi adresa celui de-al doilea element din s
    
    jecxz sfarsit             ; sarim la sfarsit daca ecx = 0
   
    compara: 
        cmpsb                 ; comparam elementele de la adresele ds : esi, es : edi
        
        jna nu_mai_mare       ; sarim peste daca valoarea de la adresa ds : esi este mai mica 
                              ; decat valoarea de la adresa es : edi
            
            dec esi           ; scadem esi cu o unitate deoarece instructiunea cmpsb a modificat pointer-ul
            
            dec edi           ; scadem edi cu o unitate deoarece instructiunea cmpsb a modificat pointer-ul
            
            push eax          ; il punem pe eax pe stiva
            
            mov al, [edi]     ; in al punem valoarea de la adresa es : edi 
            
            movsb             ; la adresa es : edi incarcam octetul de la adresa ds : esi
            
            dec esi           ; mutam pointer-ul esi la loc
            
            sub edi, 2        ; mutam pointer-ul edi la loc
            
            stosb             ; la adresa es : edi incarcam octetul din al; deoarece pe edi l-am scazut cu doua unitati,
                              ; el practic a devenit esi (esi = edi + 1)
                              ; tot in stosb, esi = esi + 1, edi = edi + 1 si trecem la urmatoarea comparatie
            
            pop eax           ; il scoatem pe eax de pe stiva
            
            mov eax, 0        ; eax = 0 (am efectuat o interschimbare)
            
        nu_mai_mare:          ; daca s-a efectuat jump-ul, trecem la urmatoarea iteratie
        
    loop compara              ; executam de ecx ori
    
    cmp eax, 0                ; verificam daca eax = 0 (s-a efectuat o interschimbare la ultima iteratie, 
                              ; in caz afirmativ, o luam de la inceput, altfel programul se opreste)
    je start                  
     
    
    mov ecx, len              ; mutam in ecx lungimea sirului d
    
    mov esi, s                ; mutam in esi adresa primului element din s
    
    mov edi, d                ; mutam in edi adresa primului element din d
    
    repnz movsb               ; cat timp mai avem elemente de mutat, la adresa ds : esi mutam octetul 
                              ; de la adresa es : edi 
                               


     
    sfarsit:
    push    dword 0      ; push the parameter for exit onto the stack
    call    [exit]       ; call exit to terminate the program
