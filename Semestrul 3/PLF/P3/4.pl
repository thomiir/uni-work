% apare(E : intreg, L : lista)
% determinist
% model de flux : (i, i)
% E : elementul pe care il cautam in lista L
% L : lista L
% model matematic recursiv :
% apare(E, L1..n) = true, daca E = L1
%                   apare(E, L2..n), daca E =\= L1
%                   false, altfel

apare(E, [E | _]).
apare(E, [_ | T]):-
	apare(E, T).

% candidat(N : intreg, I : intreg)
% nedeterminist
% model de flux : (i, o)
% N : constrangerea
% I : valoarea generata din intervalul [1, N]
% model matematic recursiv :
% candidat(N) = (1) candidat(N - 1), daca N > 1
%	      = (2) N, altfel

candidat(N, N).
candidat(N, I):-
	N > 1,
	N1 is N - 1,
	candidat(N1, I).

% permutari(N : intreg, M : intreg, L : lista, Lg : intreg, Col : lista)
% nedeterminist
% model de flux : (i, i, o, i, i)
% N : limita superioara pt valorile elementelor
% M : diferenta minima dintre 2 elemente consecutive
% L : lista initiala de valori
% Lg : lungimea permutarilor in curs de generare
% Col : permutarea partiala construita pana acum
% model matematic recursiv:
% permutari(N, M, Lg, Col)
% = Col, daca Lg = N
% = permutari(N, M, L, Lg + 1, I (+) H (+) Col), daca abs(H - I) >= M
% si I nu exista deja in permutarea generata pana la acel moment
permutari(N, _, Col, N, Col):- !.
permutari(N, M, L, Lg, [H | T]):-
	candidat(N, I),
	abs(H - I) >= M,
	\+ apare(I, [H | T]),
	Lg1 is Lg + 1,
	permutari(N, M, L, Lg1, [I, H | T]).

% permutari_final(N : intreg, M: intreg, L : lista)
% nedeterminist
% model de flux : (i, i, o)
% N : limita superioara pt valorile elementelor
% M : diferenta minima dintre 2 elemente consecutive
% L : rezultatul
% model matematic recursiv:
% permutari_final(N, M) = permutari(N, M, 1, [candidat(N)])
% teste : permutari_final(4,2,R). R = [2,4,1,3], [3,1,4,2];
%	  permutari_final(5,3,R). R = false
permutari_final(N, M, L) :-
	candidat(N, I),
	permutari(N, M, L, 1, [I]).







