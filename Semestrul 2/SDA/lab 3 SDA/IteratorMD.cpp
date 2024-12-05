#include "IteratorMD.h"

IteratorMD::IteratorMD(const MD& d) : md(d) 
{
	// 0(1)
	// constructorul iteratorului

	prim();
}

void IteratorMD::prim() 
{
	// 0(1)
	// setam iteratorul pe prima pozitie din container

	i = md.prim;
	if (i > -1)
		j = md.elems[i].prim;
}

void IteratorMD::urmator() 
{
	// 0(1)
	// mutam iteratorul cu o pozitie in container
	// daca este invalid, arunca exceptie

	if (!valid())
	{
		throw exception();
		return;
	}

	j = md.elems[i].urm[j];
	if (j == -1 || j == md.elems[i].primLiber)
	{
		i = md.urm[i];
		if (i != -1)
			j = md.elems[i].prim;
	}

}

bool IteratorMD::valid() const 
{
	// 0(1)
	// verificam daca iteratorul este valid
	// valid() <- true, daca iteratorul este valid
	//		   <- false, in caz contrar

	if (i == -1 || j == -1)
		return false;
	if (i >= 0 && j >= 0 && md.cp > i && md.elems[i].cp > j && i != md.primLiber && j != md.elems[i].primLiber)
		return true;
	return false;
}

TElem IteratorMD::element() const 
{
	// 0(1)
	// daca este invalid, arunca exceptie
	// element() <- elementul de pe pozitia curenta

	if (!valid())
		throw exception();
	return md.elems[i].elems[j];
}

