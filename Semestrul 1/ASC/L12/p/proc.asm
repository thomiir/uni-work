bits 32
global _base10
segment data public data use32
segment code public code use32

_base10:
    ; base10(sir)
    ; codul de intrare
    push ebp             ; il punem pe ebp pe stiva
    mov ebp, esp         ; definim un cadru de stiva cu ebp ca referinta
    sub esp, 4 * 1       ; alocam spatiu pe stiva pentru parametru
    push eax             ; salvam eax pentru a-l putea restaura (salvam registrul volatil in uz)
    push edx             ; salvam edx pentru a-l putea restaura (salvam registrul volatil in uz)
    
    mov esi, [ebp + 8]   ; punem in esi adresa de inceput a sirului pe care il parcurgem
	cld                  ; setam df la 0 ca sa parcurgem sirul de la adrese mici spre adrese mari
	mov edx, 0           ; initializam edx cu 0
	mov eax, 0           ; initializam eax cu 0
    
	repeta:
		LODSB            ; incarcam in al un element din sir
		
        cmp al, 0        ; comparam al cu 0
		jz final         ; sarim la eticheta final daca s-a terminat numarul
        
		sub al, '0'      ; scadem caracterul '0' pentru a obtine valoarea cifrei respective
		shl edx, 1       ; shiftam la stanga cu o pozitie bitii lui edx ca sa facem loc 
                         ; unui nou  bit
		add edx, eax     ; adaugam bitul obtinut in eax la edx
        
		jmp repeta		 ; sarim la eticheta repeta pentru a reexecuta continutul buclei
	
    final:
	mov eax, edx         ; eax ia valoarea lui edx (functia returneaza un intreg, a carui 
                         ; valoare trebuie pusa in eax)
	
    ; codul de iesire           
    mov esp, ebp         ; esp ia valoarea lui ebp
    pop ebp              ; il scoatem pe ebp inapoi din stiva
    
    ret                  ; ne intoarcem in programul C
    