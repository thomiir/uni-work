; 10. Se da un arbore de tipul (2). Sa se precizeze nivelul pe care apare un nod
;     x in arbore. Nivelul radacinii se considera a fi 0.


; L : reprezentarea arborelui sub forma de lista
; NIV : nivelul curent pe care ne regasim
; E : elementul cautat
; model matematic : 
; cauta_h(L1..Ln, NIV, E) = -1, daca n = 0
;						  = NIV, daca L1 = E
;                         = cauta_h(L2..Ln, NIV + 1, E), 
;						    daca cauta_h(L2..Ln, NIV + 1, E) != -1
;                         = cauta_h(L3..Ln, NIV + 1, E), altfel

(defun cauta_h (L NIV E)
  (cond
    ((null L) -1)
    ((eq E (car L)) NIV)
    (t
     (cond
       ((not (= (cauta_h (cadr L) (+ NIV 1) E) -1))
        (cauta_h (cadr L) (+ NIV 1) E))
       (t
        (cauta_h (caddr L) (+ NIV 1) E))
	 )
	)
  )
)

; L : reprezentarea arborelui sub forma de lista
; E : elementul cautat
; model matematic : 
; cauta(L, E) = cauta_h(L, 0, E)
; cazuri de testare : 
; (cauta '(A (B) (C (D) (E))) 'E) = 2
; (cauta '(A (B) (C (D) (E))) 'A) = 0
; (cauta '(A (B) (C (D) (E))) 'F) = -1
; (cauta '(A (B () (F)) (D (E () (K)) (L))) 'K) = 3
; (cauta '(A (B (D (G)) (E (H (L (M) (N))) (I))) (C (F (J) (K (Q (P (R) (S))))))) 'S) = 6
(defun cauta (L E)
  (cauta_h L 0 E))

; (A (B) (C (D) (E)))
;        A
;      /   \
;     B     C
;         /   \
;        D     E

; (A (B () (F)) (D (E () (K)) (L))) = 
;       A
;     /   \
;    B     D
;    \    /  \
;     F   E   L
;          \
;           K 