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
    b dw 8
    c dd 3 
    x dq 4
; our code starts here
segment code use32 class=code
    start:
        ; rezultat = x + (2 - a * b) / (a * 3) - a + c = 4 + (2 - 1 * 8) / (1 * 3) - 1 + 3 =  
        ;         = 4 + (2 - 8) / 3 + 2 = 4 + (-6)/3 + 2 = 4 - 2 + 2 = 4
        
        mov al, [a]
        mov ah, 0     ; ax = a
        mov bx, [b]   ; bx = b
        mul bx        ; dx : ax = ax * bx = a * b = 1 * 8 = 8 = 8h
        
        mov cx, 0     
        mov bx, 2     ; cx : bx = 2
        sub bx, ax
        sbb cx, dx    ; cx : bx = cx : bx - dx : ax = 2 - a * b = 2 - 8 = - 6 = FAh

        mov al, [a]   ; al = a
        mov dl, 3     ; dl = 3
        mul dl        ; ax = al * dl = a * 3 = 3
        
        push ax
        
        mov dx, cx
        mov ax, bx    ; dx : ax = cx : bx = 2 - a * b = -6 = FAh
        
        pop cx
        
        idiv cx       ; ax = dx : ax / cx = (2 - a * b) / (a * 3) 
        
        mov bl, [a]
        mov bh, 0     ; bx = a
        
        sub ax, bx    ; ax = ax - bx = (2 - a * b) / (a * 3) - a = -2 -1 = -3
        
        mov cx, 0
        push cx
        push ax
        pop eax       ; eax = -3 
        
        add eax, [c]  ; eax = eax + bx = (2 - a * b) / (a * 3) - a + c = -3 + 3 = 0
        
        push dword [x]
        push dword [x+4]
        pop ebx
        pop ecx       ; ebx : ecx = x
        
        mov edx, 0
        add eax, ecx
        adc edx, ebx  ; edx : eax = edx : eax + ebx : ecx = x + (2 - a * b) / (a * 3) - a + c = 0 + 4 = 4 

        
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
