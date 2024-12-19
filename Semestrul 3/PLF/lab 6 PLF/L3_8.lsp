; 8. Sa se construiasca o functie care intoarce maximul atomilor numerici
; dintr-o lista, de la orice nivel. 
; lista : lista de atomi
; model matematic recursiv : 
; maxim(L) = L, daca lista este atom
;		   = max(maxim(L1), maxim(L2), .., maxim(Ln)), unde L = (L1, L2, .., Ln)
; cazuri de testare : 
; (maxim '(1 2 (a b (3 (5) 6) -1) c d)) =  6
; (maxim '(1 2 6)) = 6
; (maxim '(a (b (c)))) = 0

(defun maxim (L)
	(cond 
		((numberp L) L)
		((listp L) (apply #'max (mapcar #'maxim L)))
		(t 0)
	)
)