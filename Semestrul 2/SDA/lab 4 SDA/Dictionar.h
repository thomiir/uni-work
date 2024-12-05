#pragma once
#include <climits>

#define NULL_TVALOARE -1
typedef int TCheie;
typedef int TValoare;

class IteratorDictionar;

#include <utility>
#include <functional>
#include <vector>
typedef std::pair<TCheie, TValoare> TElem;


const TElem NONE = { INT_MAX ,0 };
const TElem DELETED = { INT_MAX - 1 ,0 };

class Dictionar 
{
	friend class IteratorDictionar;

private:

	// vectorul care retine elementele
	TElem* table;

	// dimensiunea containerului
	int size;
	
	// capacitatea containerului
	int cap;


	static bool adauga_elem(TElem* table, int cap, TElem e)
	{
		// adaugam un element in container
		// adaugam elementul in prima pozitie libera din secventa de verificare a cheilor
		// adauga_elem() <- true, daca elementul a fost adaugat in container
		//				 <- false, in caz contrar

		for (int i = 0; i < cap; i++)
		{
			int pos = hashF(e.first, i, cap);
			if (liber(table[pos]))
			{
				table[pos] = e;
				return true;
			}
		}
		return false;
	}

	static bool liber(TElem elem)
	{
		// verificam daca o anumita pozitie este libera
		// 0(1)
		// liber() <- true, daca pozitia este libera
		//		   <- false, in caz contrar

		return elem.first >= INT_MAX - 1;
	}

	int pozitie(TCheie cheie) const
	{
		// cautam o cheie in container
		// caz favorabil : cheia este pe prima pozitie in secventa de verificare - O(1)
		// caz defavorabil : cheia nu se afla in container - O(n)
		// caz mediu : O(n)
		// pozitie() <- pozitia unei chei

		for (int i = 0; i < cap; i++)
		{
			int pos = hashF(cheie, i, cap);
			if (table[pos].first == cheie)
				return pos;
			if (table[pos].first == NONE.first)
				return -1;
		}
		return -1;
	}

	static int hashF(TCheie cheie, int i, int cap)
	{
		// functia de dispersie a cheilor
		// adresare deschisa cu verificare patratica
		// 0(1)
		// hashF() <- valoarea de dispersie a cheii

		return ((cheie & (cap - 1)) + i * (i + 1) / 2) & (cap - 1);
	}

	void redim() 
	{
		// redimensionarea containerului
		// 0(cap)

		int new_cap = cap * 2;
		TElem* new_table = new TElem[new_cap];

		for (int i = 0; i < new_cap; i++)
			new_table[i] = NONE;

		for (int i = 0; i < cap; i++)
			if (table[i].first != NONE.first)
				adauga_elem(new_table, new_cap, table[i]);

		delete[] table;
		table = new_table;
		cap = new_cap;

	}
public:

	// constructorul implicit al dictionarului
	Dictionar();

	// adauga o pereche (cheie, valoare) in dictionar	
	// daca exista deja cheia in dictionar, inlocuieste valoarea asociata cheii si returneaza vechea valoare
	// daca nu exista cheia, adauga perechea si returneaza null: NULL_TVALOARE
	TValoare adauga(TCheie c, TValoare v);

	// cauta o cheie si returneaza valoarea asociata (daca dictionarul contine cheia) sau null: NULL_TVALOARE
	TValoare cauta(TCheie c) const;

	// sterge o cheie si returneaza valoarea asociata (daca exista) sau null: NULL_TVALOARE
	TValoare sterge(TCheie c);

	// returneaza numarul de perechi (cheie, valoare) din dictionar 
	int dim() const;

	// verifica daca dictionarul e vid 
	bool vid() const;

	// se returneaza iterator pe dictionar
	IteratorDictionar iterator() const;

	// destructorul dictionarului	
	~Dictionar();

	// returneaza multimea valorilor
	std::vector<TValoare> multimeaValorilor();

};

