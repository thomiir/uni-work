#include "IteratorMD.h"
#include "MD.h"
#include <iostream>
#include <vector>
#include <exception>
using namespace std;

void MD::goleste()
{
	// 0(dim ^ 2)
	// golim multidictionarul

	int curent = prim;
	// daca multidictionarul este deja gol, arunca exceptie
	if (curent == -1)
		throw exception();
	
	// construim un vector care contine toate elementele din multidictionar
	vector<pair<TCheie, TValoare>> elemsToDel;
	while (curent != -1)
	{
		// iteram prin multidictionar si adaugam valorile in vector

		int curentLM = elems[curent].prim;
		while (curentLM != -1)
		{
			elemsToDel.push_back({ elems[curent].cheie, elems[curent].elems[curentLM].second });
			curentLM = elems[curent].urm[curentLM];
		}
		curent = urm[curent];
	}

	// iterand prin vector, stergem pe rand elementele din multidictionar
	for (const auto& elem : elemsToDel)
	{
		sterge(elem.first, elem.second);
	}
 
}


MD::MD()
{
	// 0(1)
	// constructorul clasei multidictionar

	len = 0;          
	prim = -1;        
	primLiber = 0;    
	cp = 2;

	elems = new lista_mica[cp];
	urm = new int[cp];
	pre = new int[cp];

	// initializam vectorii de legaturi
	for (int i = 0; i < cp - 1; i++)
	{
		urm[i] = i + 1;
		pre[i] = -1;
	}
	urm[cp - 1] = -1; 
	pre[cp - 1] = -1;
}

void MD::adauga(TCheie c, TValoare v)
{
	// caz favorabil: cheia este pe prima pozitie in container - O(1)
	// caz defavorabil: cheia nu exista in container - O(dim)
	// caz mediu: O(dim)
	// adaugam un element in container

	if (prim == -1) // daca este gol containerul
	{
		TElem element_auxiliar = pair<TCheie, TValoare>(c,v);
		int i = creeazaNod(element_auxiliar);  // cream un nou nod si refacem legaturile
		if (prim != -1)
			pre[prim] = i;
		urm[i] = prim;
		prim = i;
		pre[i] = -1;
		len = 1;
		return;
	}

	int anterior = -1;
	int current = prim;
	while (current != -1)
	{
		if (elems[current].cheie == c)  // daca exista cheia in container, adaugam nodul la aceasta
		{
			TElem element_auxiliar = pair<TCheie, TValoare>(c, v);
			elems[current].creeazaNod(element_auxiliar);
			len++;
			return;
		}

		anterior = current;
		current = urm[current]; // trecem la urmatorul element
	}

	if (current <= -1)  // daca nu exista cheia in container, cream un nou nod
	{
		TElem element_auxiliar;
		element_auxiliar.first = c;
		element_auxiliar.second = v;
		int i = creeazaNod(element_auxiliar);
		len++;
		urm[anterior] = i;
		pre[i] = anterior;
		urm[i] = -1;
		return;
	}
}

vector<TValoare> MD::cauta(TCheie c) const
{
	// caz favorabil: cheia este pe prima pozitie in container - O(dim_listamica)
	// caz defavorabil: cheia nu se afla in dictionar - O(dim)
	// caz mediu: O(dim)
	// cautam o cheie in container si returnam toate valorile asociate

	vector<TValoare> v;
	int current = prim;
	while (current != -1) 
	{
		if (elems[current].cheie == c)  // daca am gasit cheia in container
		{
			int first_elem = elems[current].prim;
			while (first_elem != -1)  // iteram peste valorile cheii respective
			{
				v.push_back(elems[current].elems[first_elem].second); // le adaugam intr-un vector
				first_elem = elems[current].urm[first_elem];
			}
			return v; // returnam vectorul creat
		}
		current = urm[current]; // trecem la urmatorul element
	}
	return v;  // returnam vectorul nul
}

bool MD::sterge(TCheie c, TValoare v)
{
	// caz favorabil: elementul este pe prima pozitie in ambele liste - O(1)
	// caz defavorabil: elementul nu se afla in container - O(dim)
	// caz mediu: O(dim)
	// stergem o valoare din container

	if (prim == -1)
		return false;

	int current = prim;
	while (current != -1) // cat timp nu am ajuns la sfarsitul listei
	{
		if (elems[current].cheie == c) // daca am gasit cheia in lista mare
		{
			int first_elem = elems[current].prim;
			while (first_elem != -1)
			{
				if (elems[current].elems[first_elem].second == v) // daca am gasit valoarea in lista mica
				{
					// actualizam legaturile
					if (elems[current].pre[first_elem] != -1)
						elems[current].urm[elems[current].pre[first_elem]] = elems[current].urm[first_elem];

					// actualizam legaturile
					if (elems[current].urm[first_elem] != -1)
						elems[current].pre[elems[current].urm[first_elem]] = elems[current].pre[first_elem];

					// actualizam inceputul listei
					if (elems[current].prim == first_elem)
						elems[current].prim = elems[current].urm[first_elem];

					// dealocam elementul sters
					elems[current].dealoca(first_elem);

					// daca a devenit vida lista curenta de elemente
					// refacem legaturile si dealocam nodul sters
					if (elems[current].prim == -1)
					{
						if (pre[current] != -1)
							urm[pre[current]] = urm[current];
						if (urm[current] != -1)
							pre[urm[current]] = pre[current];

						if (current == prim)
							prim = urm[current];

						dealoca(current);
					}

					// 
					len--;
					return true;
				}
				first_elem = elems[current].urm[first_elem];
			}

			// am gasit cheia, dar valoarea nu exista
			// deci returnam fals
			return false;
		}
		
		// trecem la urmatorul element
		current = urm[current];
	}

	// nu am gasit valoarea, returnam fals
	return false;
}


int MD::dim() const
{
	// 0(1)
	// dim() <- numarul de elemente din container

	return len;
}

bool MD::vid() const
{
	// 0(1)
	// vid() <- 0, cand containerul nu are elemente
	//		 <- 1, in caz contrar

	return len == 0;
}

IteratorMD MD::iterator() const
{
	// 0(1)
	// iterator() <- un iterator pe containerul curent

	return IteratorMD(*this);
}

MD::~MD()
{
	// 0(1)
	// destructorul containerului 

	//delete[] elems;
	//delete[] pre;
	//delete[] urm;
}
