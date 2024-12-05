#pragma once
#include <string>
#include <iostream>
using namespace std;
class Car
{
	private:
		// numarul de inmatriculare al masinii
		string licensePlate;
		
		// producatorul masinii
		string producer;

		// modelul masinii
		string model;

		//tipul masinii
		string type;
		
	public:
		// constructorul unui obiect de tip masina
		Car(const string l, const string p, const string m, const string t) : licensePlate{ l }, producer{ p }, model{ m }, type{ t } {};

		// getter pentru numarul de inmatriculare al masinii
		string getLicensePlate() const
		{
			return licensePlate;
		}

		// getter pentru producatorul masinii
		string getProducer() const
		{
			return producer;
		}

		// getter pentru modelul masinii
		string getModel() const
		{
			return model;
		}

		// getter pentru tipul masinii
		string getType() const
		{
			return type;
		}

		Car(const Car& c) : licensePlate{c.licensePlate}, producer{c.producer}, model{c.model}, type{c.type}
		{
			cout << "*\n";
		}
};

// testele pentru Domain
void testDomain();