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
%			 =
%			 A1
%			 (+)
%			 concateneaza(lista_divizori(A1),adauga_divizori(A2..n))
%			 altfel teste : adauga_divizori([], L). (L = [])
%			 adauga_divizori([12], L). (L = [12, 2, 3, 4,
%			 6]) adauga_divizori([2, 20, 1], L). (L = [2,
%			 20, 2, 4, 5, 10, 1]).

adauga_divizori([], []).
adauga_divizori([H | T], [H | RezFinal]):-
    lista_divizori(2, H, Divizori),
    adauga_divizori(T, TRezDiv),
    concateneaza(Divizori, TRezDiv, RezFinal).












