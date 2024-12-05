#include "IteratorMDO.h"
#include "MDO.h"

IteratorMDO::IteratorMDO(const MDO& d) : dict(d) 
{
    // O(h)
    // pozitionam iteratorul pe primul element din container

    prim();
}

void IteratorMDO::prim() 
{
    // O(h)
    // parcurgem arborele in inordine pentru a ajunge la primul element

    curent = dict.radacina;
    stiva = {};
    while (curent != -1) 
    {
        stiva.push(curent);
        curent = dict.stanga[curent];
    }

    if (!stiva.empty())
        curent = stiva.top();
}

void IteratorMDO::urmator() 
{
    // O(1) amortizat
    // mutam iteratorul la urmatorul element din container

    if (!valid())
        throw exception();

    curent = stiva.top();
    stiva.pop();
    if (dict.dreapta[curent] != -1) 
    {
        curent = dict.dreapta[curent];
        while (curent != -1) 
        {
            stiva.push(curent);
            curent = dict.stanga[curent];
        }
    }
    if (!stiva.empty())
        curent = stiva.top();
    else
        curent = -1;
}

bool IteratorMDO::valid() const 
{
    // 0(1)
    // iteratorul este valid doar daca indexul curent
    // este valid (diferit de -1)
    // valid() <- true, daca iteratorul refera un element existent
    //         <- false, in caz contrar

    return curent != -1;
}

TElem IteratorMDO::element() const 
{
    // 0(1)
    // element() <- elementul curent pe care il refera iteratorul

    if (!valid())
        throw exception();

    return dict.elems[curent];
}

