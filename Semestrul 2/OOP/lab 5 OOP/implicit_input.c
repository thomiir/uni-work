#include "implicit_input.h"
#include <string.h>
#include <stdlib.h>

void addImplicit(ElemTypeList* l)
{
	Cheltuieli* newcheltuiala;
	char tip[25] = "mancare";
	newcheltuiala = createCheltuiala(22, 200, tip);
	adauga(l, newcheltuiala);

	strcpy_s(tip, _countof(tip), "internet");
	newcheltuiala = createCheltuiala(23, 400, tip);
	adauga(l, newcheltuiala);

	strcpy_s(tip, _countof(tip), "transport");
	newcheltuiala = createCheltuiala(15, 150, tip);
	adauga(l, newcheltuiala);

	strcpy_s(tip, _countof(tip), "mancare");
	newcheltuiala = createCheltuiala(31, 70, tip);
	adauga(l, newcheltuiala);

	strcpy_s(tip, _countof(tip), "telefon");
	newcheltuiala = createCheltuiala(1, 80, tip);
	adauga(l, newcheltuiala);
}