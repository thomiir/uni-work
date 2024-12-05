#include "carConsole.h"
#include "car.h"
#include "carService.h"
#include "MyVector.h"
#include <iostream>
#include <string>

using namespace std;

void carConsole::printAllCars(const VectorDinamic<Car>& carList)
{

	for (int i = 0; i < carList.size(); i++)
		cout << i << ' ' << carList.get(i).getLicensePlate() << ' ' << carList.get(i).getProducer() << ' ' << carList.get(i).getModel() << ' ' << carList.get(i).getType() << '\n';
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
	cout << "5. Filtreaza masinile dupa producator.\n";
	cout << "6. Filtreaza masinile dupa tip.\n";
	cout << "7. Sorteaza masinile dupa numarul de inmatriculare.\n";
	cout << "8. Sorteaza masinile dupa tip.\n";
	cout << "9. Sorteaza masinile dupa producator + model.\n";
	cout << "10. Iesire.\n";
}

void carConsole::addCarUI()
{
	string licensePlate, producer, model, type;
	cout << "Introduceti numarul de inmatriculare al masinii: ";
	cin >> licensePlate;
	cout << "Introduceti producatorul masinii: ";
	cin >> producer;
	cout << "Introduceti modelul masinii: ";
	cin >> model;
	cout << "Introduceti tipul masinii: ";
	cin >> type;

	try
	{
		service.addCar(licensePlate, producer, model, type);
		cout << "Masina a fost adaugata cu succes!\n";
	}
	catch (const int errCode)
	{
		if (errCode == 1)
			cout << "Exista deja o masina cu acest numar de inmatriculare in baza de date!\n";
		else
			cout << "Datele masinii sunt invalide!\n";
	}
}

void carConsole::modifyCarUI()
{
	string oldLicensePlate, newLicensePlate, producer, model, type;
	cout << "Introduceti numarul de inmatriculare al masinii pe care doriti sa o modificati: ";
	cin >> oldLicensePlate;
	cout << "Introduceti noul numar de inmatriculare al masinii:";
	cin >> newLicensePlate;
	cout << "Introduceti producatorul masinii: ";
	cin >> producer;
	cout << "Introduceti modelul masinii: ";
	cin >> model;
	cout << "Introduceti tipul masinii: ";
	cin >> type;

	try
	{
		service.modifyCar(oldLicensePlate, newLicensePlate, producer, model, type);
		cout << "Masina a fost modificata cu succes!\n";
	}
	catch (const int errCode)
	{
		if (errCode == 1)
			cout << "Masina nu exista in baza de date!\n";
		else
			cout << "Noile date ale masinii sunt invalide!\n";
	}
}

void carConsole::findCarUI()
{
	string licensePlate;
	cout << "Introduceti numarul de inmatriculare al masinii pe care o cautati: ";
	cin >> licensePlate;

	try
	{
		Car carToFind = service.findCar(licensePlate);
		cout << "Masina cautata este: \n";
		printCar(carToFind);
	}
	catch (...)
	{
		cout << "Masina nu exista in baza de date!\n";
	}
}

void carConsole::removeCarUI()
{
	string licensePlate;
	cout << "Introduceti numarul de inmatriculare al masinii pe care doriti sa o stergeti: ";
	cin >> licensePlate;

	try
	{
		service.removeCar(licensePlate);
		cout << "Masina a fost stearsa cu succes!\n";
	}
	catch (...)
	{
		cout << "Masina cautata nu exista in baza de date!\n";
	}
}

void carConsole::filterByProdUI()
{
	string producer;
	cout << "Introduceti numele producatorului dupa care doriti sa filtrati: ";
	cin >> producer;
	try
	{
		VectorDinamic<Car> filteredList = service.filterByProd(producer);
		cout << "Lista de masini filtrata dupa producator este: \n";
		printAllCars(filteredList);
	}
	catch (...)
	{
		cout << "Nu exista masini de la acest producator!\n";
	}
}

void carConsole::filterByTypeUI()
{
	string type;
	cout << "Introduceti tipul dupa care doriti sa filtrati: ";
	cin >> type;
	try
	{
		VectorDinamic<Car> filteredList = service.filterByType(type);
		cout << "Lista de masini filtrata dupa tip este: \n";
		printAllCars(filteredList);
	}
	catch (...)
	{
		cout << "Nu exista masini de acest tip!\n";
	}
}

void carConsole::sortByLicPlateUI()
{
	char mode;
	cout << "Introduceti d pentru sortare descrescatoare si c pentru sortare crescatoare: ";
	cin >> mode;
	try
	{
		VectorDinamic<Car> sortedList = service.sortByLicPlate(mode);
		cout << "Lista sortata este: \n";
		printAllCars(sortedList);
	}
	catch (...)
	{
		cout << "Modul de sortare este invalid!\n";
	}
}

void carConsole::sortByTypeUI()
{
	char mode;
	cout << "Introduceti d pentru sortare descrescatoare si c pentru sortare crescatoare: ";
	cin >> mode;
	try
	{
		VectorDinamic<Car> sortedList = service.sortByType(mode);
		cout << "Lista sortata este: \n";
		printAllCars(sortedList);
	}
	catch (...)
	{
		cout << "Modul de sortare este invalid!\n";
	}
}

void carConsole::sortByProdModelUI()
{
	char mode;
	cout << "Introduceti d pentru sortare descrescatoare si c pentru sortare crescatoare: ";
	cin >> mode;
	try
	{
		VectorDinamic<Car> sortedList = service.sortByProdModel(mode);
		cout << "Lista sortata este: \n";
		printAllCars(sortedList);
	}
	catch (...)
	{
		cout << "Modul de sortare este invalid!\n";
	}
}

void populate(carService& cS)
{
	cS.addCar("CT-99-CXC", "FORD", "FIESTA", "ALTELE");
	cS.addCar("AB-21-GBM", "SUZUKI", "VITARA", "SPORT");
	cS.addCar("SV-01-ADL", "OPEL", "ASTRA", "MINI");
	cS.addCar("BH-25-BNC", "SKODA", "FABIA", "SUV");
	cS.addCar("SJ-68-PPR", "SEAT", "LEON", "ALTELE");
}

void carConsole::start()
{
	int option = 10;
	populate(service);
	while (true)
	{
		cout << "Lista curenta de masini este:\n";
		printAllCars(service.getCarList());
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
		else if (option == 5)
			filterByProdUI();
		else if (option == 6)
			filterByTypeUI();
		else if (option == 7)
			sortByLicPlateUI();
		else if (option == 8)
			sortByTypeUI();
		else if (option == 9)
			sortByProdModelUI();
		else break;

	}
}