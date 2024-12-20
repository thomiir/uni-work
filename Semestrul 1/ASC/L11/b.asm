bits 32
global procedura
extern printf
import printf msvcrt.dll
segment data use32 public data
    format db "%x", 0
segment code use32 public code
    procedura:
    
        mov esi, [esp + 4] ; adresa sirului dat ca parametru
        mov ecx, [esp + 8] ; lungimea sirului dat ca parametru
        lea ecx, [ecx*4]
        
        repeta:
            lodsd ; incarcam in eax un element din sirul dat
            push ecx
            mov ecx, 4
            repeta2:
                push ecx
                mov ecx, 8
                clc
                mov ebx, 0
                repeta3:
                    rcr eax, 1
                    adc ebx, 0
                    sal ebx, 1
                loop repeta3
                sar ebx, 1
                pop ecx
                push ebx
                push format
                call [printf]
                add esp, 8
            loop repeta2
            pop ecx
       loop repeta

       ret