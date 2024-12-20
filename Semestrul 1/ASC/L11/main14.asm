bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit, printf, scanf, modul14
import printf msvcrt.dll    ; tell the assembler that function printf is found in msvcrt.dll library
import scanf msvcrt.dll     ; similar for scanf
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

segment data use32 class=data
	numar resb 32
	format_citire db "%s", 0
	format_afisare db "%o", 10, 13, 0
; Se citesc mai multe numere de la tastatura, in baza 2. Sa se afiseze aceste numere in baza 8.
segment code use32 class=code
    start:
			push numar           ; punem pe stiva adresa variabilei numar - in care se va citi de la tastatura 
			push format_citire   ; punem pe stiva adresa formatului de citire - tip string
			call [scanf]         ; apelam functia de citire
			add esp, 4 * 2       ; refacem pointerul esp
			
			push numar           ; punem pe stiva adresa variabilei numar (parametrul)
			call modul14         ; apelam modulul extern
            
            cmp edx, 0           ; comparam registrul edx - in care este salvat rezultatul - cu 0
            jz final             ; daca este egal, sarim la eticheta final
			
			push edx             ; punem pe stiva valoarea registrului edx
			push format_afisare  ; punem pe stiva adresa formatului de afisare - tip octal
			call [printf]        ; apelam functia de afisare
			add esp, 4 * 2       ; refacem pointerul esp
			jmp start            ; ne intoarcem la eticheta start si repetam citirea
	
        
    final:                       ; oprim executia programului
            push    dword 0      ; push the parameter for exit onto the stack
            call    [exit]       ; call exit to terminate the program
