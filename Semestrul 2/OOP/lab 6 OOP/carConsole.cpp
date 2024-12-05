#include "carConsole.h"
#include "car.h"
#include "carService.h"
#include <iostream>
#include <string>

using namespace std;

void carConsole::printAllCars(const vector<Car>& carList)
{
	cout << "Lista curenta de masini este:\n";
	for (size_t i = 0; i < carList.size(); i++)
		cout << i << ' ' << carList[i].getLicensePlate() << ' ' << carList[i].getModel() << ' ' << carList[i].getProducer() << ' ' << carList[i].getType() << '\n';
}

void carConsole::printCar(const Car& car)
{
	cout << car.getLicensePlate() << ' ' << car.getProducer() << ' ' << car.getModel() << ' ' << car.getType() << '\n';
}

void carConsole::printMenu()
{
	cout << "Selectati o optiune din meniul aplicatiei:\n";
	cout << "1. Adauga o masina.\n";
	cout << "2. Modifica o masina.\n";
	cout << "3. Sterge o masina.\n";
	cout << "4. Cauta o masina.\n";
	cout << "9. Iesire.\n";
}

void carConsole::addCarUI()
{
	string licensePlate, producer, model, type;
	cout << "Introduceti numarul de inamtriculare al masinii: ";
	cin >> licensePlate;
	cout << "Introduceti producatorul masinii: ";
	cin >> producer;
	cout << "Introduceti modelul masinii: ";
	cin >> model;
	cout << "Introduceti tipul masinii: ";
	cin >> type;
	service.addCar(licensePlate, producer, model, type);
	cout << "Masina a fost adaugata cu succes!\n";
}

void carConsole::modifyCarUI()
{
	string oldLicensePlate, newLicensePlate, producer, model, type;
	cout << "Introduceti numarul de inamtriculare al masinii pe care doriti sa o modificati: ";
	cin >> oldLicensePlate;
	cout << "Introduceti noul numar de inmatriculare al masinii:";
	cin >> newLicensePlate;
	cout << "Introduceti producatorul masinii: ";
	cin >> producer;
	cout << "Introduceti modelul masinii: ";
	cin >> model;
	cout << "Introduceti tipul masinii: ";
	cin >> type;
	service.modifyCar(oldLicensePlate, newLicensePlate, producer, model, type);
	cout << "Masina a fost modificata cu succes!\n";
}

void carConsole::findCarUI()
{
	string licensePlate;
	cout << "Introduceti numarul de inamtriculare al masinii pe care o cautati: ";
	cin >> licensePlate;
	cout << "Masina cautata este: \n";
	printCar(service.findCar(licensePlate));
}

void carConsole::removeCarUI()
{
	string licensePlate;
	cout << "Introduceti numarul de inmatriculare al masinii pe care doriti sa o stergeti: ";
	cin >> licensePlate;
	service.removeCar(licensePlate);
}

void populate(carService& cS)
{
	cS.addCar("CT-99-CXC", "MAZDA", "CX90", "altele");
	cS.addCar("AB-21-GBM", "SUZUKI", "VITARA", "sport");
	cS.addCar("SV-01-ADL", "OPEL", "ASTRA", "mini");
	cS.addCar("BH-25-BNC", "SKODA", "FABIA", "suv");
	cS.addCar("SJ-68-PPR", "SEAT", "LEON", "altele");
}

void carConsole::start()
{
	int option;
	//populate(service);
	while (true)
	{
		//printAllCars(service.getCarList());
		printMenu();
		cin >> option;
		if (option == 1)
			addCarUI();
		else if (option == 2)
			modifyCarUI();
		else if (option == 3)
			removeCarUI();
		else if (option == 4)
			findCarUI();
		else break;

	}
}