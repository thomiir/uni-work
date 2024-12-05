#include "IteratorDictionar.h"
#include "Dictionar.h"

using namespace std;


IteratorDictionar::IteratorDictionar(const Dictionar& d) : dict(d), index(0)
{
	// constructorul clasei Iterator
	// caz favorabil : prima pozitie este ocupata - O(1)
	// caz defavorabil : toate pozitiile tabelei sunt libere - O(n)
	// caz mediu : O(1)

	prim();
}

void IteratorDictionar::prim() 
{
	// mutam iteratorul sa arate catre primul element
	// cat timp pozitiile din secventa de cautare sunt libere, trecem la urmatorul index
	// caz favorabil : prima pozitie este ocupata - O(1)
	// caz defavorabil : toate pozitiile tabelei sunt libere - O(n)
	// caz mediu : O(1)


	for (index = 0; index < dict.cap && Dictionar::liber(dict.table[index]); index++);
}

void IteratorDictionar::urmator() 
{
	// mutam iteratorul la urmatorul element
	// daca este invalid, arunca exceptie
	// caz favorabil : pozitia elementului imediat urmator este ocupata - O(1) 
	// caz defavorabil : toate elementele urmatoare sunt libere - O(n)
	// caz mediu : O(1)

	if (!valid())
		throw exception();
	for (++index; index < dict.cap && Dictionar::liber(dict.table[index]); index++);
}


TElem IteratorDictionar::element() const 
{
	// returnam elementul curent
	// daca este invalid, arunca exceptie
	// element() <- elementul curent catre care arata iteratorul

	if (!valid())
		throw exception();
	return dict.table[index];
}

bool IteratorDictionar::valid() const 
{
	// verificam iteratorul
	// 0(1)
	// valid() <- true, daca iteratorul este valid
	//		   <- false, in caz contrar

	return index < dict.cap && !Dictionar::liber(dict.table[index]);
}
