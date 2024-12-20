% inserare(L : lista, E : intreg, P : intreg, R : lista)
% model de flux : (i, i, i, o)
% L : lista  de inceput
% E : elementul de inserat
% P : pozitia pe care inseram
% R : lista noua
% model matematic recursiv :
% inserare(L, E, P) = [E], daca n = 0 si P = 1
%                   = [], daca n = 0 si P > 1
%                   = E + L1..Ln, daca n > 0 si P = 1
%                   = L1 + inserare(L2..Ln, E, P - 1), altfel
% teste :
% inserare([], 99, 1, R). ([99])
% inserare([], 99, 2, R).  ([])
% inserare([1, 2, 3, 4], 99, 2, R). ([1, 99, 2, 3, 4])

inserare([], E, 1, [E]).
inserare([], _, P, []):- P > 1.
inserare([H | T], E, 1, [E , H | T]).
inserare([H | T], E, P, [H | R]) :-
    P > 1,
    P1 is P - 1,
    inserare(T, E, P1, R).
