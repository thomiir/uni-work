#include "car.h"
#include "carService.h"
#include "carConsole.h"
#include "exception.h"
#include <iostream>
#include <string>

using namespace std;

void CarConsole::printAllCars(const vector<Car>& carList)
{
	for (auto& car : carList)
		printCar(car);
}

void CarConsole::printCar(const Car& car)
{
	cout << car.getLicensePlate() << ' ' << car.getProducer() << ' ' << car.getModel() << ' ' << car.getType() << '\n';
}

void CarConsole::printWashMenu()
{
	cout << "Selectati o optiune din meniul urmator:\n";
	cout << "1. Goleste lista.\n";
	cout << "2. Adauga in lista.\n";
	cout << "3. Genereaza lista.\n";
	cout << "4. Revenire la meniul principal.\n";
}

void CarConsole::printMenu()
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
	cout << "10. Meniul de spalare masini.\n";
	cout << "11. Genereaza raport.\n";
	cout << "12. Iesire.\n";
}

void CarConsole::addCarUI()
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
		carService.addCar(licensePlate, producer, model, type);
		cout << "Masina a fost adaugata cu succes!\n";
	}
	catch (const Error& err)
	{
		cout << err.getMessage();
	}
}

void CarConsole::modifyCarUI()
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
		carService.modifyCar(oldLicensePlate, newLicensePlate, producer, model, type);
		cout << "Masina a fost modificata cu succes!\n";
	}
	catch (const Error& err)
	{
		cout << err.getMessage();
	}
}

void CarConsole::findCarUI()
{
	string licensePlate;
	cout << "Introduceti numarul de inmatriculare al masinii pe care o cautati: ";
	cin >> licensePlate;

	try
	{
		Car carToFind = carService.findCar(licensePlate);
		cout << "Masina cautata este: \n";
		printCar(carToFind);
	}
	catch (const Error& err)
	{
		cout << err.getMessage();
	}
}

void CarConsole::removeCarUI()
{
	string licensePlate;
	cout << "Introduceti numarul de inmatriculare al masinii pe care doriti sa o stergeti: ";
	cin >> licensePlate;

	try
	{
		carService.removeCar(licensePlate);
		cout << "Masina a fost stearsa cu succes!\n";
	}
	catch (const Error& err)
	{
		cout << err.getMessage();
	}
}

void CarConsole::filterByProdUI()
{
	string producer;
	cout << "Introduceti numele producatorului dupa care doriti sa filtrati: ";
	cin >> producer;
	try
	{
		vector<Car> filteredList = carService.filterByProd(producer);
		cout << "Lista de masini filtrata dupa producator este: \n";
		printAllCars(filteredList);
	}
	catch (const Error& err)
	{
		cout << err.getMessage();
	}
}

void CarConsole::filterByTypeUI()
{
	string type;
	cout << "Introduceti tipul dupa care doriti sa filtrati: ";
	cin >> type;
	try
	{
		vector<Car> filteredList = carService.filterByType(type);
		cout << "Lista de masini filtrata dupa tip este: \n";
		printAllCars(filteredList);
	}
	catch (const Error& err)
	{
		cout << err.getMessage();
	}
}

void CarConsole::sortByLicPlateUI()
{
	char mode;
	cout << "Introduceti d pentru sortare descrescatoare si c pentru sortare crescatoare: ";
	cin >> mode;
	try
	{
		vector<Car> sortedList = carService.sortByLicPlate(mode);
		cout << "Lista sortata este: \n";
		printAllCars(sortedList);
	}
	catch (const Error& err)
	{
		cout << err.getMessage();
	}
}

void CarConsole::sortByTypeUI()
{
	char mode;
	cout << "Introduceti d pentru sortare descrescatoare si c pentru sortare crescatoare: ";
	cin >> mode;
	try
	{
		vector<Car> sortedList = carService.sortByType(mode);
		cout << "Lista sortata este: \n";
		printAllCars(sortedList);
	}
	catch (const Error& err)
	{
		cout << err.getMessage();
	}
}

void CarConsole::sortByProdModelUI()
{
	char mode;
	cout << "Introduceti d pentru sortare descrescatoare si c pentru sortare crescatoare: ";
	cin >> mode;
	try
	{
		vector<Car> sortedList = carService.sortByProdModel(mode);
		cout << "Lista sortata este: \n";
		printAllCars(sortedList);
	}
	catch (const Error& err)
	{
		cout << err.getMessage();
	}
}

void CarConsole::emptyWashList()
{
	washService.emptyWash();
	cout << "Lista a fost golita cu succes!\n";
}

void CarConsole::addToWashList()
{
	string licensePlate;
	cout << "Introduceti numarul de inmatriculare al masinii pe care doriti sa o adaugati: ";
	cin >> licensePlate;
	try
	{
		washService.addWash(licensePlate);
	}
	catch (const Error& err)
	{
		cout << err.getMessage();
	}
}

void CarConsole::generateWashList()
{
	size_t number;
	cout << "Introduceti numarul de masini care trebuie adaugate: ";
	cin >> number;
	try
	{
		washService.populateWash(number);
	}
	catch (const Error& err)
	{
		cout << err.getMessage();
	}
}

void CarConsole::generateReport()
{
	map<string, int> rep = carService.report();
	for (auto pr : rep)
		cout << pr.first << ' ' << pr.second << '\n';
}

void populate(CarService& cS)
{
	cS.addCar("CT-99-CXC", "FORD", "FIESTA", "ALTELE");
	cS.addCar("AB-21-GBM", "SUZUKI", "VITARA", "SPORT");
	cS.addCar("SV-01-ADL", "OPEL", "ASTRA", "MINI");
	cS.addCar("BH-25-BNC", "SKODA", "FABIA", "SUV");
	cS.addCar("SJ-68-PPR", "SEAT", "LEON", "ALTELE");
}

void CarConsole::start()
{
	int option = 10;
	populate(carService);
	while (1)
	{
		cout << "Lista curenta de masini este:\n";
		printAllCars(carService.getCarList());
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
		else if (option == 10)
		{
			int washOption = 4;
			while (1)
			{
				cout << "Sunt " << washService.washSize() << " masini care trebuie spalate\n";
				printAllCars(washService.washList());
				printWashMenu();
				cin >> washOption;
				if (washOption == 1)
					emptyWashList();
				else if (washOption == 2)
					addToWashList();
				else if (washOption == 3)
					generateWashList();
				else break;
			}
		}
		else if (option == 11)
			generateReport();
		else break;

	}
}