#include "IteratorMDO.h"
#include "MDO.h"
#include <vector>
#include <exception>
#include <iostream>
using namespace std;

int MDO::aloca() 
{
    // 0(1)
    // alocarea unei pozitii in vector

    int i = primLiber;
    primLiber = stanga[primLiber];
    return i;
}

void MDO::dealoca(int i) 
{
    // 0(1)
    // dealocarea unei pozitii din container

    dreapta[i] = -1;
    stanga[i] = primLiber;
    primLiber = i;
}

int MDO::creeazaNod(TElem elem) 
{
    // caz favorabil: nu trebuie redimensionati vectorii - O(1)
    // caz defavorabil: trebuie redimensionati vectorii - O(dim)
    // caz mediu: O(dim)
    // cream un nod in vectorul de legaturi
    
    if (primLiber == -1)
        redim();

    int i = aloca();
    if (i != -1) 
    {
        elems[i] = elem;
        stanga[i] = -1;
        dreapta[i] = -1;
    }
    return i;
}

MDO::MDO(Relatie r) 
{
    // 0(1)
    // constructorul containerului

    cp = 15;
    n = 0;
    rel = r;
    elems = new TElem[cp];
    stanga = new int[cp];
    dreapta = new int[cp];
    for (int i = 0; i < cp - 1; ++i) 
    {
        stanga[i] = i + 1;
        dreapta[i] = -1;
    }
    stanga[cp - 1] = dreapta[cp - 1] = -1;
    primLiber = 0;
    radacina = -1;
}

void MDO::redim() 
{
    // 0(cap)
    // redimensionam vectorii elems, stanga, dreapta

    TElem* new_elems = new TElem[cp * 2];
    int* new_stanga = new int[cp * 2];
    int* new_dreapta = new int[cp * 2];


    for (int i = 0; i < cp; i++) 
    {
        new_elems[i] = elems[i];
        new_stanga[i] = stanga[i];
        new_dreapta[i] = dreapta[i];
    }


    for (int i = cp; i < cp * 2 - 1; i++) 
    {
        new_stanga[i] = i + 1;
        new_dreapta[i] = -1;
    }

    new_stanga[cp * 2 - 1] = -1;
    new_dreapta[cp * 2 - 1] = -1;

    primLiber = cp;
    cp *= 2;

    delete[] elems;
    delete[] stanga;
    delete[] dreapta;

    elems = new_elems;
    stanga = new_stanga;
    dreapta = new_dreapta;
}

int MDO::adauga_rec(int nod, TElem elem) 
{
    // O(h), unde h este inaltimea arborelui
    // adaugam recursiv un nod in arbore

    if (nod == -1)
        // am gasit o pozitie pe care sa inseram si cream un nou nod
        nod = creeazaNod(elem); 
    else 
        if (rel(elem.first, elems[nod].first)) 
        // daca sunt in relatie, se adauga recursiv in arborele stang
        stanga[nod] = adauga_rec(stanga[nod], elem);
    else 
        // altfel se adauga recursiv in arborele drept
        dreapta[nod] = adauga_rec(dreapta[nod], elem);
    
    // returnam indexul nodului
    return nod;
}

int MDO::minim(int nod) 
{
    // 0(h), unde h este inaltimea arborelui
    // cautam cheia cu valoarea minima din arbore

    while (stanga[nod] != -1)
        nod = stanga[nod];
    return nod;
}

int MDO::sterge_rec(int nod, TElem elem, bool& sters) 
{
    // O(h), unde h este inaltimea arborelui
    // stergem recursiv un nod din arbore

    // daca subarborele este vid, nu avem ce sterge
    if (nod == -1)
        return nod;

    // daca am gasit nodul care trebuie sters
    if (elem == elems[nod])
    {
        int temp;
        sters = true;

        if (stanga[nod] != -1 && dreapta[nod] != -1) 
        {
            // daca nodul are doi fii
            temp = minim(dreapta[nod]); // gasim nodul cu cheia minima
            elems[nod] = elems[temp]; // inlocuim elementul nodului curent cu elementul succesorului
            dreapta[nod] = sterge_rec(dreapta[nod], elem, sters); // stergem recursiv succesorul din subarborele drept
            return nod; // returnam nodul curent
        }
        else 
        {
            temp = nod;
            int repl;
            // determinam fiul nenul pentru a inlocui nodul curent
            if (stanga[nod] == -1)
                repl = dreapta[nod];
            else
                repl = stanga[nod];
            // dealocam nodul sters
            dealoca(temp);
            // returnam indexul fiului
            return repl;
        }
    }

    // daca nu am gasit nodul, trecem la urmatorul nod
    // din secventa de cautare
    if (rel(elem.first, elems[nod].first))
        stanga[nod] = sterge_rec(stanga[nod], elem, sters);
    else
        dreapta[nod] = sterge_rec(dreapta[nod], elem, sters);
    return nod;
}

void MDO::adauga(TCheie c, TValoare v) 
{
    // O(h)
    // adaugam un nod in arbore

    radacina = adauga_rec(radacina, TElem(c, v));
    n++;
}

vector<TValoare> MDO::cauta(TCheie c) const 
{
    // O(h)
    // cautam un nod in arbore
    // cauta() <- vectorul de valori asociate cheii c
     
    // cautam nodul cu cheia c in arbore
    int nod = radacina;
    while (nod != -1 && elems[nod].first != c) 
        if (rel(c, elems[nod].first))
            nod = stanga[nod];
        else
            nod = dreapta[nod];

    // iteram prin valorile care au cheia c
    vector<TValoare> valori;
    while (nod != -1 && elems[nod].first == c) 
    {
        valori.push_back(elems[nod].second);
        nod = stanga[nod];
    }
    return valori;
}

bool MDO::sterge(TCheie c, TValoare v) 
{
    // O(h)
    // stergem elementul (c,v) din arbore
    // sterge() <- true, daca am sters elementul
    //          <- false, in caz contrar

    bool sters = false;
    radacina = sterge_rec(radacina, TElem(c, v), sters);
    if (sters)
        n--;
    return sters;
}

int MDO::dim() const 
{
    // 0(1)
    // dim() <- numarul de elems din container

    return n;
}

bool MDO::vid() const 
{
    // 0(1)
    // vid() <- 0, cand containerul nu are elems
    //		 <- 1, in caz contrar

    return n == 0;
}

IteratorMDO MDO::iterator() const 
{
    // 0(1)
    // iterator() <- un iterator pe containerul curent

    return IteratorMDO(*this);
}

MDO::~MDO()
{
    // 0(1)
    // destructorul containerului 

    delete[] elems;
    delete[] stanga;
    delete[] dreapta;
}

int MDO::eliminaAparitiiCheie(int x, TCheie c)
{
    // O(xh)
    // eliminam x aparitii pentru cheia c
    // daca multidictionarul este vid, arunca exceptie
    // eliminaAparitiiCheie() <- numarul de aparitii sterse

    if (vid())
        throw exception();

    vector<TValoare> valori = cauta(c);
    int z = x, j = 0;
    while (j < valori.size() && x)
    {
        if (sterge(c, valori[j]) == true) x--;
        j++;
    }
        
    return z - x;
}