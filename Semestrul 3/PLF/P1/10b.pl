% cmmdc(A : intreg, B : intreg, C : intreg)
% model de flux : (i, i, o)
% A, B = numerele carora le calculam cmmdc
% C = cmmdc calculat
% model matematic recursiv :
% cmmdc(A, B) = A, daca B = 0
%		cmmdc(B, A%B), altfel

cmmdc(A, 0, A).
cmmdc(A, B, C) :-B=\=0,
    R is A mod B,
    cmmdc(B, R, C).

% cmmdc_lista(L : lista, C : intreg)
% model de flux : (i, o)
% L : lista careia ii calculam cmmdc
% C : cmmdc calculat
% model matematic recursiv :
% cmmdc_lista(L) = L1, cand lista are doar un element
%                = cmmdc(L1, L2), cand lista are doar 2 elemente
%                = cmmdc_lista(cmmdc(L1, L2) U L3..Ln), altfel
% teste :
% cmmdc_lista([1, 2, 3, 4], C). (1)
% cmmdc_lista([10, 15, 20], C). (5)
% cmmdc_lista([2, 4], C). (2)
% cmmdc_lista([2], C). (2)

cmmdc_lista([A], A).
cmmdc_lista([A, B], C) :-
    cmmdc(A, B, C).
cmmdc_lista([A, B | Rest], C) :- Rest\=[],
    cmmdc(A, B, D),
    cmmdc_lista([D | Rest], C).










