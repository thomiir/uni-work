#include "Dictionar.h"
#include <iostream>
#include "IteratorDictionar.h"

Dictionar::Dictionar() 
{
	// constructorul clasei Dictionar
	// O(cap)

	cap = 16;
	table = new TElem[cap];
	for (int i = 0; i < cap; i++)
		table[i] = NONE;
	size = 0;
}

TValoare Dictionar::adauga(TCheie c, TValoare v)
{
	// adaugam un element in container
	// daca exista deja cheia, inlocuim valoarea cu una noua si o returnam pe cea veche
	// caz favorabil : cheia este pe prima pozitie in secventa de cautare - O(1)
	// caz defavorabil : tabela este plina, deci este necesara redispersarea cheilor - O(cap) 
	// caz mediu : O(1)
	// adauga() <- vechea valoare, daca deja exista cheia in container
	//		    <- NULL_TVALOARE, in caz contrar

	int pos = pozitie(c);
	if (pos >= 0)
	{
		int old_val = table[pos].second;
		table[pos].second = v;
		return old_val;
	}

	// incercam sa adaugam perechea <cheie, valoare>
	if (!adauga_elem(table, cap, { c,v }))
	{
		// in cazul in care nu s-a putut adauga perechea <cheie, valoare> in tabela,
		// o redimensionam si redispersam cheile, apoi apelam din nou functia de adaugare
		redim();
		adauga_elem(table, cap, { c,v });
	}

	// crestem numarul de elemente din container
	size++;
	return NULL_TVALOARE;
}

TValoare Dictionar::cauta(TCheie c) const
{
	// cautam o cheie in container si returnam valoarea asociata acesteia
	// caz favorabil : elementul este pe prima pozitie in secventa de verificare - O(1)
	// caz defavorabil : elementul nu exista in container O(n)
	// caz mediu : O(1)
	// cauta() <- valoarea asociata cheii cautate, daca aceasta exista
	//		   <- NULL_TVALOARE, in caz contrar

	int pos = pozitie(c);
	if (pos >= 0)
		return table[pos].second;
	else
		return NULL_TVALOARE;
}

TValoare Dictionar::sterge(TCheie c)
{
	// stergem un element din container
	// caz favorabil : elementul este pe prima pozitie in secventa de cautare - O(1)
	// caz defavorabil : elementul nu se afla in container - O(n)
	// caz mediu : O(1)
	// sterge() <- valoarea care s-a sters, daca aceasta exista
	//          <- NULL_TVALOARE, in caz contrar

	for (int i = 0; i < cap; i++)
	{
		int pos = hashF(c, i, cap);
		if (table[pos].first == NONE.first)
			return NULL_TVALOARE;
		if (table[pos].first == c)
		{
			int val = table[pos].second;
			table[pos] = DELETED;
			size--;
			return val;
		}
	}
	return NULL_TVALOARE;
}

int Dictionar::dim() const 
{
	// returnam dimensiunea Dictionarului
	// dim() <- numarul de elemente din container

	return size;
}

bool Dictionar::vid() const 
{
	// verificam daca Dictionarul este vid
	// 0(1)
	// vid() <- true, daca dimensiunea este nula
	//       <- false, in caz contrar

	return size == 0;
}

IteratorDictionar Dictionar::iterator() const 
{
	// construim un iterator pe Dictionar
	// 0(1)
	// iterator() <- un iterator pe container

	return IteratorDictionar(*this);
}

Dictionar::~Dictionar()
{
	// destructorul clasei Dictionar
	// 0(cap)

	delete[] table;
}

std::vector<TValoare> Dictionar::multimeaValorilor()
{
	// construim si returnam multimea valorilor dictionarului
	// aruncam exceptie daca dictionarul este vid
	// 0(dim)
	// multimeaValorilor <- vectorul de valori construit

	if (vid())
		throw std::exception();

	std::vector<TValoare> mult = {};
	auto it = iterator();
	while (it.valid())
	{
		mult.push_back(it.element().second);
		it.urmator();
	}
	return mult;
}