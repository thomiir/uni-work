#pragma once

#include <vector>
#include <stdlib.h>

typedef int TCheie;
typedef int TValoare;

#include <utility>
typedef std::pair<TCheie, TValoare> TElem;

using namespace std;

class IteratorMD;
class MD;


class lista_mica
{
public:
    int cp; // capacitatea de memorare a celor trei vectori
    int* urm; // vectorii de legaturi
    int* pre;         
    int prim; // primul element din lista
    int primLiber;      // primul element liber din lista
    TElem* elems;       // vectorul de elemente
    TCheie cheie;       // cheia elementelor din lista

    // constructorul implicit
    lista_mica() {};

    lista_mica(TCheie c)
    {
        // 0(1)
        // constructorul cu o cheie data ca parametru

        cheie = c;
        prim = -1;
        primLiber = 0;
        cp = 2;

        elems = new TElem[cp];
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

    int aloca()
    {
        // 0(1)
        // alocarea unei pozitii in container

        int i = primLiber;
        primLiber = urm[primLiber];
        return i;
    }

    void dealoca(int i)
    {
        // 0(1)
        // dealocarea unei pozitii din container

        urm[i] = primLiber;
        pre[primLiber] = i;
        primLiber = i;
    }

    int creeazaNod(TElem el)
    {
        // caz favorabil: nu trebuie redimensionati vectorii - O(1)
        // caz defavorabil: trebuie redimensionati vectorii - O(dim)
        // caz mediu: O(dim)
        // cream un nod in lista mica

        if (primLiber == -1)
            redim();
        int i = aloca(); // alocam spatiu pentru nodul creat
        elems[i] = el; // si actualizam legaturile corespunzator
        if (prim != -1)
            pre[prim] = i;
        urm[i] = prim;
        prim = i;
        pre[i] = -1;
        return i; // returnam pozitia nodului creat
    }

    void redim()
    {
        // 0(cp)
        // redimensionam vectorii pre, urm, elems

        int cp_nou = cp * 2;
        TElem* elem_nou = new TElem[cp_nou];
        int* urm_nou = new int[cp_nou];
        int* pre_nou = new int[cp_nou];

        for (int i = 0; i < cp; ++i)
        {
            elem_nou[i] = elems[i];
            urm_nou[i] = urm[i];
            pre_nou[i] = pre[i];
        }

        for (int i = cp; i < cp_nou - 1; ++i)
        {
            urm_nou[i] = i + 1;
            pre_nou[i] = i - 1; 
        }
        urm_nou[cp_nou - 1] = -1; 
        pre_nou[cp_nou - 1] = cp_nou - 2;

        primLiber = cp;

        delete[] elems;
        delete[] urm;
        delete[] pre;

        elems = elem_nou;
        urm = urm_nou;
        cp = cp_nou;
        pre = pre_nou;
    }
};

class MD
{
    friend class IteratorMD;
    private:
        int cp;             // capacitatea de memorare a celor trei vectori
        int* urm;           // vectorii de legaturi
        int* pre;
        int prim;           // primul element din lista
        int primLiber;      // primul element liber din lista
        int len;            // lungimea containerului
        lista_mica* elems;  // vectorul de chei

        int aloca()
        {
            // 0(1)
            // alocarea unei pozitii in container

            int i = primLiber;
            primLiber = urm[primLiber]; 
            return i;
        }

        void dealoca(int i)
        {
            // 0(1)
            // dealocarea unei pozitii din container

            urm[i] = primLiber;
            pre[primLiber] = i;
            primLiber = i;
        }


        int creeazaNod(TElem el)
        {
            // caz favorabil: nu trebuie redimensionati vectorii - O(1)
            // caz defavorabil: trebuie redimensionati vectorii - O(dim)
            // caz mediu: O(dim)
            // cream un nod in container

            if (primLiber == -1)
                redim();
            int i = aloca();
            lista_mica list(el.first);
            elems[i] = list;
            elems[i].creeazaNod(el);
            return i;
        }

        void redim()
        {
            // 0(cp)
            // redimensionam vectorii pre, urm, elems

            int cp_nou = cp * 2;
            lista_mica* elem_nou = new lista_mica[cp_nou];
            int* urm_nou = new int[cp_nou];
            int* pre_nou = new int[cp_nou];

            for (int i = 0; i < cp; ++i)
            {
                elem_nou[i] = elems[i];
                urm_nou[i] = urm[i];
                pre_nou[i] = pre[i];
            }

            for (int i = cp; i < cp_nou - 1; ++i)
            {
                urm_nou[i] = i + 1;
                pre_nou[i] = -1;
            }
            urm_nou[cp_nou - 1] = -1;

            delete[] pre;
            delete[] elems;
            delete[] urm;

            primLiber = cp;
            pre = pre_nou;
            elems = elem_nou;
            urm = urm_nou;
            cp = cp_nou;
        }

    public:

        //
        void goleste();

        // constructorul implicit al MultiDictionarului
        MD();

        // adauga o pereche (cheie, valoare) in MD	
        void adauga(TCheie c, TValoare v);

        //cauta o cheie si returneaza vectorul de valori asociate
        vector<TValoare> cauta(TCheie c) const;

        //sterge o cheie si o valoare 
        //returneaza adevarat daca s-a gasit cheia si valoarea de sters
        bool sterge(TCheie c, TValoare v);

        //returneaza numarul de perechi (cheie, valoare) din MD 
        int dim() const;

        //verifica daca MultiDictionarul e vid 
        bool vid() const;

        // se returneaza iterator pe MD
        IteratorMD iterator() const;

        // destructorul MultiDictionarului	
        ~MD();
};
