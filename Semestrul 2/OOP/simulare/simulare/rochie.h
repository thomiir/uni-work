#pragma once
#include <string>
using namespace std;
class Rochie
{
private:
	// reprezentarea interna a obiectului rochie
	int cod;
	string denumire;
	string marime;
	int pret;
	string disponibilitate;

public:
	// constructorul clasei rochie
	Rochie(int _cod, string _denumire, string _marime, int _pret, string _disponibilitate)
	{
		cod = _cod;
		denumire = _denumire;
		marime = _marime;
		pret = _pret;
		disponibilitate = _disponibilitate;
	}

	// getter pentru id-ul rochiei
	int get_cod()
	{
		return cod;
	}

	// getter pentru denumirea rochiei
	string get_denumire()
	{
		return denumire;
	}

	// getter pentru marimea rochiei
	string get_marime()
	{
		return marime;
	}

	// getter pentru pretul rochiei
	int get_pret()
	{
		return pret;
	}

	// getter pentru atributul rochiei
	string get_disponibilitate()
	{
		return disponibilitate;
	}

	void set_disponibilitate(string _disponibilitate)
	{
		disponibilitate = _disponibilitate;
	}

};

// teste pentru domain
void testDomain();