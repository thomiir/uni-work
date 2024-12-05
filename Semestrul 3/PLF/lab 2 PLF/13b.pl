% lista_divizori(M : intreg, N : intreg, L : lista)
% model de flux : (i, i, o)
% M : numarul de la care pornim calculul divizorilor (2)
% N : numarul insusi caruia ii calculam lista divizorilor
% L : lista divizorilor proprii gasiti
% model matematic recursiv :
% lista_divizori(M, N) = [], daca M >= N
%			 M (+) lista_divizori(M + 1, N), daca M < N si N
%			 % M = 0
%                        lista_divizori(M, N), daca M < N si N % M != 0

lista_divizori(M, N, []):- M >= N.
lista_divizori(M, N, [M | T]):-
    M < N,
    N mod M =:= 0,
    M1 is M + 1,
    lista_divizori(M1, N, T).
lista_divizori(M, N, T):-
    M < N,
    N mod M =\= 0,
    M1 is M + 1,
    lista_divizori(M1, N, T).

% concateneaza( A : lista, B : lista, C : lista)
% model de flux : (i, i, o)
% A, B : cele doua liste pe care vrem sa le concatenam
% C : lista rezultat (ordinea este A, B)
% model matematic recursiv :
% concateneaza(A1..n, B1..m) = B, daca n = 0
%		             = A1 (+) concateneaza(A2..n, B), altfel

concateneaza([], B, B).
concateneaza([H | T], B, [H | C]):-
    concateneaza(T, B, C).

% adauga_divizori( A : lista, B : lista)
% model de flux: (i, o)
% A : lista initiala
% B : lista A modificata astfel : dupa fiecare element se regasesc
%     si divizorii sai proprii
% model matematic recursiv :
% adauga_divizori(A1..n) = [], daca n = 0
%			 = A1 (+) lista_divizori(2, A1) (+)
%			   adauga_divizori(A2..n), altfel

adauga_divizori([], []).
adauga_divizori([H | T], [H | RezFinal]):-
    lista_divizori(2, H, Divizori),
    adauga_divizori(T, TRezDiv),
    concateneaza(Divizori, TRezDiv, RezFinal).

% adauga_divizori_eterogen( A : lista, B : lista)
% model de flux : (i, o)
% A : lista initiala
% B : lista A modificata astfel : dupa fiecare element dintr-o
%     sublista, se regasesc si divizorii sai proprii
% model matematic recursiv :
% adauga_divizori_eterogen(A1..n) = [], daca n = 0
%				  = A1 (+)
%				  adauga_divizori_eterogen(A2..n), daca
%				  n > 0 si A1 nu este o lista
%				  = adauga_divizori(A1) (+)
%				  adauga_divizori_eterogen(A2..n), daca
%				  n > 0 si A1 este o lista
% teste :
% adauga_divizori_eterogen([], L). (L = [])
% adauga_divizori_eterogen([10, 20], L). (L = [10, 20])
% adauga_divizori_eterogen([[10, 20], 15, [20, 50]], L). (L = [10, 2, 5,
% 20, 2, 4, 5, 10], 15, [20, 2, 4, 5, 10, 50, 2, 5, 10, 25]])

adauga_divizori_eterogen([], []).
adauga_divizori_eterogen([H | T], [HRez | TRez]):-
    is_list(H),
    adauga_divizori(H, HRez),
    adauga_divizori_eterogen(T, TRez).
adauga_divizori_eterogen([H | T], [H | TRez]):-
    \+ is_list(H),
    adauga_divizori_eterogen(T, TRez).


