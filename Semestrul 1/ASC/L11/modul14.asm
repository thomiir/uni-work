bits 32
segment code use32 public code
global modul14        

modul14:
	mov esi, [esp + 4]    ; punem in esi adresa de inceput a sirului pe care il parcurgem
	cld                   ; setam df la 0 ca sa parcurgem sirul de la adrese mici spre adrese mari
	mov edx, 0            ; initializam edx cu 0
	mov eax, 0            ; initializam eax cu 0
    
	repeta:
		LODSB         ; incarcam in al un element din sir
        
		cmp al, 0     ; comparam al cu 0 
		jz final      ; sarim la eticheta final daca s-a terminat numarul
        
		sub al, '0'   ; scadem caracterul '0' pentru a obtine valoarea cifrei respective
		shl edx, 1    ; shiftam la stanga cu o pozitie bitii lui edx ca sa facem loc unui nou bit
		add edx, eax  ; adaugam bitul obtinut in eax la edx
        
		jmp repeta    ; sarim la eticheta repeta pentru a reexecuta continutul buclei		
	
    final:
	ret               ; ne intoarcem in programul principal