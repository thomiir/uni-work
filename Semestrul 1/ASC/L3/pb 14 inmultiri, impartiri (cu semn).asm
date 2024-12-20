bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    a db -1
    b dw 4
    c dd 4 
    x dq 10
; our code starts here
segment code use32 class=code
    start:
        ; rezultat = x + (2 - a * b) / (a * 3) - a + c = 
        ; rezultat = 10 + (2 - (-1) * 4) / ((-1) * 3)) - (-1) + 4 = 10 + 6/(-3) + 1 + 4 = 10 - 2 + 1 + 4 = 13
        
        mov al, [a]     ; al = a
        cbw             ; ax = a
        imul word [b]   ; dx : ax = a * b = (-1) * 4 = -4
        
        mov cx, 0    
        mov bx, 2       ; cx : bx = 2
        sub bx, ax      ; bx = bx - ax
        sbb cx, dx      ; cx : bx = dx : ax - cx : bx = 2 - a * b = 2 - (-4) = 6
        
        mov al, [a]     ; al = a
        mov dl, 3       ; dl = 3
        imul dl         ; ax = al * dl = a * 3 = -1 * 3 = -3
        push ax
         
        mov dx, cx      ; dx = dx - cx
        mov ax, bx      ; dx : ax = cx : bx = 2 - a * b = 6
        pop cx
        idiv cx         ; ax = dx : ax / cx = 6 / (-3) = -2
        mov cx, ax      ; cx = -2
        
        mov al, [a]     ; al = a
        cbw             ; ax = a
        sub cx, ax      ; cx = cx - a = -2 - (-1) = -1
        mov ax, cx      ; ax = -1
        cwd             ; eax = -1
        mov ebx, [c]    
        add eax, ebx    ; eax = eax + ebx = -1 + 4 = 3
        
        cdq             ; edx : eax = 3
        
        push dword [x]
        push dword [x+4]
        pop ebx
        pop ecx         ; ebx : ecx = x = 10
        
        add eax, ecx
        adc edx, ebx    ; edx : eax = edx : eax + ebx : ecx = 3 + 10 = 13
        
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
