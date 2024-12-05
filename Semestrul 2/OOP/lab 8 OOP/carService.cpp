#include "carService.h"
#include "carValidator.h"
#include "exception.h"
#include <cassert>
#include <algorithm>
#include <random>
#include <chrono>
#pragma warning( disable : 4244 )
using namespace std;

void CarService::addCar(const string& licensePlate, const string& producer, const string& model, const string& type)
{
	if (repo.find(licensePlate) >= 0)
		throw ExistentCarError("Masina exista deja in baza de date!\n");
	if (validateCar(licensePlate, producer, model, type) == 0)
		throw InvalidCarError("Datele masinii sunt invalide!\n");
	Car newCar{ licensePlate, producer, model, type };
	repo.add(newCar);
}

void CarService::modifyCar(const string& licensePlate, const string& newLicensePlate, const string& newProducer, const string& newModel, const string& newType)
{
	const __int64 position = repo.find(licensePlate);
	if (position < 0)
		throw InexistentCarError("Masina nu exista in baza de date!\n");
	if (validateCar(newLicensePlate, newProducer, newModel, newType) == 0)
		throw InvalidCarError("Datele masinii sunt invalide!\n");
	Car newCar{ newLicensePlate, newProducer, newModel, newType };
	repo.modify(position, newCar);
}

void CarService::removeCar(const string& licensePlate)
{
	const __int64 position = repo.find(licensePlate);
	if (position < 0)
		throw InexistentCarError("Masina nu exista in baza de date!\n");
	repo.remove(position);
}

const Car& CarService::findCar(const string& licensePlate) const
{

	const __int64 position = repo.find(licensePlate);
	if (position < 0)
		throw InexistentCarError("Masina nu exista in baza de date!\n");
	return getCarList().at(position);
}

const vector<Car>& CarService::getCarList() const noexcept
{
	return repo.getList();
}

size_t CarService::listSize() const noexcept
{
	return repo.size();
}

vector<Car> CarService::filterByProd(const string& producer) const
{
	vector<Car> filteredList;
	copy_if(getCarList().begin(), getCarList().end(), back_inserter(filteredList), [producer](const Car& car) { return car.getProducer() == producer; });
	if (filteredList.empty())
		throw EmptyListError("Nu exista masini de acest tip in baza de date!\n");
	return filteredList;
}

vector<Car> CarService::filterByType(const string& type) const
{
	vector<Car> filteredList;
	copy_if(getCarList().begin(), getCarList().end(), back_inserter(filteredList), [type](const Car& car) { return car.getType() == type; });
	if (filteredList.empty())
		throw EmptyListError("Nu exista masini de acest tip in baza de date!\n");
	return filteredList;
}

vector<Car> CarService::sortByLicPlate(const char& mode) const
{
	vector<Car> sortedList = getCarList();
	if (mode != 'c' && mode != 'd')
		throw InvalidSortingMode("Mod de sortare invalid!");

	if (mode == 'c') 
		sort(sortedList.begin(), sortedList.end(), [](const Car& car1, const Car& car2) { return car1.getLicensePlate() < car2.getLicensePlate(); });
	else
		sort(sortedList.begin(), sortedList.end(), [](const Car& car1, const Car& car2) { return car1.getLicensePlate() > car2.getLicensePlate(); });
	return sortedList;
}

vector<Car> CarService::sortByType(const char& mode) const
{
	vector<Car> sortedList = getCarList();
	if (mode != 'c' && mode != 'd')
		throw InvalidSortingMode("Mod de sortare invalid!");

	if (mode == 'c')
		sort(sortedList.begin(), sortedList.end(), [](const Car& car1, const Car& car2) { return car1.getType() < car2.getType(); });
	else
		sort(sortedList.begin(), sortedList.end(), [](const Car& car1, const Car& car2) { return car1.getType() > car2.getType(); });
	return sortedList;
}

vector<Car> CarService::sortByProdModel(const char& mode) const
{
	vector<Car> sortedList = getCarList();
	if (mode != 'c' && mode != 'd')
		throw InvalidSortingMode("Mod de sortare invalid!");

	if (mode == 'c')
		sort(sortedList.begin(), sortedList.end(), [](const Car& car1, const Car& car2) 
			{ 
				if (car1.getProducer() == car2.getProducer()) 
					return car1.getModel() < car2.getModel(); 
				else 
					return car1.getProducer() < car2.getProducer(); 
			});
	
	else
		sort(sortedList.begin(), sortedList.end(), [](const Car& car1, const Car& car2)
			{
				if (car1.getProducer() == car2.getProducer())
					return car1.getModel() > car2.getModel();
				else
					return car1.getProducer() > car2.getProducer();
			});
	return sortedList;
}

void WashService::addWash(const string& licensePlate)
{
	if (validateLicensePlate(licensePlate) == 0)
		throw InvalidLicensePlate("Numarul de inmatriculare al masinii este invalid!\n");
	try
	{
		Car car = carService.findCar(licensePlate);
		washRepo.add(car);
	}
	catch (const Error& error)
	{
		throw error;
	}	
}

void WashService::emptyWash()
{
	while (washRepo.size())
		washRepo.remove(0);
}

void WashService::populateWash(size_t number)
{
	if (number > carService.listSize())
		throw InvalidGenerateNumber("Numarul de masini de generat este prea mare!\n");
	vector<Car> copyCarList = carService.getCarList();
	auto seed = chrono::system_clock::now().time_since_epoch().count();
	shuffle(copyCarList.begin(), copyCarList.end(), default_random_engine(seed));
	for (size_t i = 0; i < number; i++)
		washRepo.add(copyCarList.at(i));
}

map<string, int> CarService::report() const
{
	map<string, int> rep;
	for (auto& car : getCarList())
	{
		auto it = rep.find(car.getType());
		if (it != rep.end())
			rep[car.getType()]++;
		else
			rep.insert(pair<string, int>(car.getType(), 1));
	}
	return rep;
}


void testService()
{
	CarRepo repo;
	CarService service{ repo };

	// adaugam cateva masini
	service.addCar("AG-12-AAA", "RENAULT", "CLIO", "ALTELE");
	service.addCar("CJ-01-AGH", "OPEL", "CORSA", "SPORT");
	service.addCar("AB-98-GTR", "TOYOTA", "COROLLA", "SUV");
	service.addCar("TR-45-POL", "RENAULT", "ZOE", "SPORT");
	service.addCar("SV-10-BBB", "RENAULT", "MEGAN", "SPORT");

	// incercam sa adaugam o masina invalida
	try
	{
		service.addCar("TEST", "TEST", "TEST", "TEST");
	}
	catch (const Error& error)
	{
		assert(error.getMessage() == "Datele masinii sunt invalide!\n");
	}

	// incercam sa adaugam o masina deja existenta
	try
	{
		service.addCar("AG-12-AAA", "RENAULT", "CLIO", "ALTELE");
	}
	catch (const Error& error)
	{
		assert (error.getMessage() == "Masina exista deja in baza de date!\n");
	}

	// verificam ca s-au adaugat masinile valide
	assert (service.getCarList().at(0).getLicensePlate() == "AG-12-AAA");
	assert (service.getCarList().at(0).getProducer() == "RENAULT");
	assert (service.getCarList().at(0).getModel() == "CLIO");
	assert (service.getCarList().at(0).getType() == "ALTELE");

	// verificam ca s-a modificat masina
	service.modifyCar("AG-12-AAA", "CJ-00-BGG", "SKODA", "FABIA", "SUV");
	assert (service.getCarList().at(0).getLicensePlate() == "CJ-00-BGG");
	assert (service.getCarList().at(0).getProducer() == "SKODA");
	assert (service.getCarList().at(0).getModel() == "FABIA");
	assert (service.getCarList().at(0).getType() == "SUV");

	// incercam sa modificam o masina inexistenta
	try
	{
		service.modifyCar("AA-00-AA", "AA-00-AAA", "PROD", "MODEL", "ALTELE");
	}
	catch (const Error& error)
	{
		assert (error.getMessage() == "Masina nu exista in baza de date!\n");
	}

	// incercam sa modificam o masina cu date invalide
	try
	{
		service.modifyCar("CJ-00-BGG", "TEST", "TEST", "TEST", "TEST");
	}
	catch (const Error& error)
	{
		assert (error.getMessage() == "Datele masinii sunt invalide!\n");
	}

	// cautam o masina existenta
	Car testCar;	
	testCar = service.findCar("CJ-00-BGG");
	assert (testCar.getLicensePlate() == "CJ-00-BGG");
	assert (testCar.getProducer() == "SKODA");
	assert (testCar.getModel() == "FABIA");
	assert (testCar.getType() == "SUV");

	// cautam o masina inexistenta
	try
	{
		testCar = service.findCar("CS-01-AAA");
	}
	catch (const Error& error)
	{
		assert(error.getMessage() == "Masina nu exista in baza de date!\n");
	}

	// stergem o masina si verificam ca s-a micsorat marimea
	service.removeCar("CJ-00-BGG");
	assert (service.listSize() == 4);

	// incercam sa stergem o masina inexistenta
	try
	{
		service.removeCar("AA-00-AAA");
	}
	catch (const Error& error)
	{
		assert(error.getMessage() == "Masina nu exista in baza de date!\n");
	}


	// teste pentru filtrarea dupa producator
	// testam cu un producator de masini existent in lista
	vector<Car> carList = service.filterByProd("RENAULT");
	assert (carList.size() == 2);
	assert (carList.at(0).getLicensePlate() == "TR-45-POL");
	assert (carList.at(0).getProducer() == "RENAULT");
	assert (carList.at(0).getModel() == "ZOE");
	assert (carList.at(0).getType() == "SPORT");


	// testam cu un producator de masini inexistent in lista
	try
	{
		carList = service.filterByProd("FORD");
	}
	catch (const Error& error)
	{
		assert (error.getMessage() == "Nu exista masini de acest tip in baza de date!\n");
	}

	// teste pentru filtrarea dupa tip
	// testam cu un tip de masini existent in lista
	carList = service.filterByType("SPORT");
	assert (carList.size() == 3);
	assert (carList.at(0).getLicensePlate() == "CJ-01-AGH");
	assert (carList.at(0).getProducer() == "OPEL");
	assert (carList.at(0).getModel() == "CORSA");
	assert (carList.at(0).getType() == "SPORT");

	// testam cu un tip de masini inexistent in lista
	try
	{
		carList = service.filterByType("ALTELE");
	}
	catch (const Error& error)
	{
		assert(error.getMessage() == "Nu exista masini de acest tip in baza de date!\n");
	}

	// sortam descrescator dupa numarul de inmatriculare
	carList = service.sortByLicPlate('d');
	assert (carList.at(0).getLicensePlate() == "TR-45-POL");

	// sortam crescator dupa numarul de inmatriculare
	carList = service.sortByLicPlate('c');
	assert (carList.at(0).getLicensePlate() == "AB-98-GTR");

	// incercam sa sortam folosind un mod incorect
	try
	{
		carList = service.sortByLicPlate('g');
	}
	catch (const Error& error)
	{
		assert(error.getMessage() == "Mod de sortare invalid!");
	}

	// sortam descrescator dupa tip
	carList = service.sortByType('d');
	assert (carList.at(0).getType() == "SUV");

	// sortam crescator dupa tip
	carList = service.sortByType('c');
	assert (carList.at(0).getType() == "SPORT");

	// incercam sa sortam folosind un mod incorect
	try
	{
		carList = service.sortByType('g');
	}
	catch (const Error& error)
	{
		assert(error.getMessage() == "Mod de sortare invalid!");
	}

	// sortam descrescator dupa producator + model
	carList = service.sortByProdModel('d');
	assert (carList.at(0).getProducer() == "TOYOTA");

	// sortam crescator dupa producator + model
	carList = service.sortByProdModel('c');
	assert (carList.at(0).getProducer() == "OPEL");

	// incercam sa sortam folosind un mod incorect
	try
	{
		carList = service.sortByProdModel('g');
	}
	catch (const Error& error)
	{
		assert (error.getMessage() == "Mod de sortare invalid!");
	}

	// testam functia de generat raport
	map<string, int>mp = service.report();
	assert(mp["SPORT"] == 3);


	// testam functionalitatile clasei WashService
	WashService washService{ service };
	assert (washService.washSize() == 0);

	// adaugam o masina existenta
	washService.addWash("AB-98-GTR");
	assert (washService.washSize() == 1);
	assert(washService.washList().at(0).getLicensePlate() == "AB-98-GTR");
	assert(washService.washList().at(0).getProducer() == "TOYOTA");
	assert(washService.washList().at(0).getModel() == "COROLLA");
	assert(washService.washList().at(0).getType() == "SUV");

	// incercam sa adaugam o masina inexistenta
	try
	{
		washService.addWash("AA-00-AAA");
	}
	catch (const Error& error)
	{
		assert (error.getMessage() == "Masina nu exista in baza de date!\n");
	}

	// incercam sa adaugam o masina cu numar de inmatriculare invalid
	try
	{
		washService.addWash("TEST");
	}
	catch (const Error& error)
	{
		assert (error.getMessage() == "Numarul de inmatriculare al masinii este invalid!\n");
	}

	// stergem toate masinile din lista de spalat
	washService.emptyWash();
	assert (washService.washSize() == 0);

	// generam masini de spalat
	washService.populateWash(2);
	assert (washService.washSize() == 2);

	// incercam sa generam prea multe masini de spalat
	try
	{
		washService.populateWash(10);
	}
	catch (const Error& error)
	{
		assert (error.getMessage() == "Numarul de masini de generat este prea mare!\n");
	}
}