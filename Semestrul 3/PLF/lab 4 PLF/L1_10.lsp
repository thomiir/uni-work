; a) Sa se construiasca o functie care intoarce produsul atomilor numerici
; dintr - o lista, de la nivelul superficial.
; model matematic :
; L : lista
; produs(L1..Ln) = 1, daca n = 0
; 				 = L1 * produs(L2..Ln), daca L1 este numar
; 				 = produs(L2..Ln), altfel
; cazuri de testare :
; (produs '(1 2 3)) = 6
; (produs '(1 2 (3))) = 2
; (produs '(1 (2 3))) = 1

(defun produs(lista)
	(cond
		((null lista) 1)
		((numberp(car lista)) (* (car lista) (produs(cdr lista))))
		(t(produs(cdr lista)))
	)
)



; b) Sa se scrie o functie care, primind o lista, intoarce multimea tuturor
; perechilor din lista. De exemplu : (a b c d) -- > ((a b) (a c) (a d) (b c)
; (b d) (c d))
; model matematic :
; L este o lista de perechi de forma(A, B)
; perechi_h(E, L1..Ln) = [], daca n = 0
; 				       = (E, L1) (+) perechi_h(E, L2..Ln)

(defun perechi_h(element lista)
	(cond
		((null lista) nil)
		(t(cons (list element (car lista)) (perechi_h element(cdr lista))))
	)
)

; model matematic :
; perechi(L1..Ln) = [], daca n = 0
; 				  = append(perechi_h(L1, L2..Ln), perechi(L2..Ln)), altfel
; L : lista
; cazuri de testare :
; (perechi '(A B C)) = ((A B) (A C) (B C))
; (perechi '(A B)) = ((A B))  

(defun perechi(lista)
	(cond
		((null lista) nil)
		((listp (car lista)) (perechi (cdr lista)))
		(t(append(perechi_h (car lista) (cdr lista)) (perechi (cdr lista))))
	)
)



; c) Sa se determine rezultatul unei expresii aritmetice memorate in preordine
; pe o stiva.
; a,b : intregi
; model matematic :
; operatie(o, a, b) = a + b, daca o = '+'
; 					= a - b, daca o = '-'
;				    = a * b, daca o = '*'
; 					= a / b, daca o = '/'

(defun operatie(o a b)
	(cond
		((equal o '+) (+ a b))
		((equal o '-) (- a b))
		((equal o '*) (* a b))
		((equal o '/) (/ a b))
	)
)

; model matematic :
; L : lista
; expresie_h(L1..Ln) = (0, []), daca n = 0
; 					 = (L1, L1..Ln), daca L1 este numar
; 					 = (operatie(L1, A1, A2), L'), unde
; (A1, L'') = expresie_h(L2..Ln) si
; (A2, L') = expresie_h(L'')
(defun expresie_h(lista)
	(cond
		((null lista) (list 0 nil))
		((numberp(car lista)) (list (car lista) (cdr lista)))
		(t
			(list
				(operatie
					(car lista) 
					(car(expresie_h(cdr lista)))
					(car(expresie_h(cadr(expresie_h(cdr lista)))))
				)
				(cadr(expresie_h(cadr(expresie_h(cdr lista)))))
			)
		)
	)
)

; model matematic :
; L : lista
; expresie(L) = L1, unde L1 este capul listei rezultate
; din expresie_h(L)
; cazuri de testare :
; (expresie '(+ 1 3)) = 4 (1 + 3)
; (expresie '(+ * 2 4 3)) = 11 (2 * 4 + 3)
; (expresie '(+ * 2 4 - 5 * 2 2)) = 9 (2 * 4 + 5 - 2 * 2)
(defun expresie(lista) (car(expresie_h lista)))


; d) Definiti o functie care, dintr - o lista de atomi, produce o lista de
; perechi(atom n), unde atom apare in lista initiala de n ori.
; L este o lista de perechi de forma(element, frecventa)
; E : atom
; notam Lx1 elementul si Lx2 frecventa acestuia, x = 1..n
; model matematic :
; adauga(L1..Ln, E) = ((E, 1)), daca n = 0
; 					= (E, L12 + 1 (+) L2..Ln), daca E = L11
; 					= adauga(L2..Ln, E), altfel

(defun adauga(dict element)
	(cond
		((null dict) (list (list element 1)))
		((equal element (caar dict)) (cons (list element (+ 1 (cadar dict))) (cdr dict)))
		(t(cons (car dict) (adauga (cdr dict) element)))
	)
)

; model matematic :
; L : lista de atomi
; dict : lista de perechi
; dictionar_h(L1..Ln, D) = D, daca n = 0
; 						 = dictionar_h(L2..Ln, adauga(D, L1)), altfel

(defun dictionar_h(lista dict)
	(cond
		((null lista) dict)
		(t(dictionar_h (cdr lista) (adauga dict (car lista))))
	)
)

; model matematic :
; dictionar(L) = dictionar_h(L, [])
; L : lista de atomi
; cazuri de testare :
; (dictionar '(A B A B A C A)) = ((A 4) (B 2) (C 1))
; (dictionar '(1 1 1 1 2)) = ((1 4) (2 1))
(defun dictionar(lista) (dictionar_h lista nil))
