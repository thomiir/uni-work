#include "carService.h"
#include "carValidator.h"
#include <cassert>
using namespace std;

void carService::addCar(const string& licensePlate, const string& producer, const string& model, const string& type)
{
	if (repo.find(licensePlate) != -1)
		throw 1;
	if (validateCar(licensePlate, producer, model, type) == 0)
		throw 2;
	Car newCar{ licensePlate, producer, model, type };
	repo.add(newCar);
}

void carService::modifyCar(const string& licensePlate, const string& newLicensePlate, const string& newProducer, const string& newModel, const string& newType)
{

	const int position = repo.find(licensePlate);
	if (position == -1)
		throw 1; // masina nu exista in repo
	if (validateCar(newLicensePlate, newProducer, newModel, newType) == 0)
		throw 2; // noile date ale masinii sunt invalide
	Car newCar{ newLicensePlate, newProducer, newModel, newType };
	repo.modify(position, newCar);
}

void carService::removeCar(const string& licensePlate)
{

	const int position = repo.find(licensePlate);
	if (position == -1)
		throw -1; // masina nu exista in repo, deci nu avem ce sterge
	repo.remove(position);
}

const Car& carService::findCar(const string& licensePlate) const
{

	const int position = repo.find(licensePlate);
	if (position == -1)
		throw 1;
	return getCarList().get(position);
}

const VectorDinamic<Car>& carService::getCarList() const noexcept
{
	return repo.getList();
}

int carService::listSize() const noexcept
{
	return repo.size();
}

VectorDinamic<Car> carService::filterByProd(const string& producer) const
{
	VectorDinamic<Car> carList = getCarList();
	VectorDinamic<Car> filteredList;
	int added = 0;
	for (int i = 0; i < carList.size(); i++)
		if (carList.get(i).getProducer() == producer)
		{
			filteredList.add(carList.get(i));
			added = 1;
		}
	if (added == 0)
		throw 0;
	return filteredList;
}

VectorDinamic<Car> carService::filterByType(const string& type) const
{
	VectorDinamic<Car> carList = getCarList();
	VectorDinamic<Car> filteredList;
	int added = 0;
	for (int i = 0; i < carList.size(); i++)
		if (carList.get(i).getType() == type)
		{
			filteredList.add(carList.get(i));
			added = 1;
		}
	if (added == 0)
		throw 0;
	return filteredList;
}

VectorDinamic<Car> carService::sortByLicPlate(const char& mode) const
{
	VectorDinamic<Car> sortedList = getCarList();
	if (mode != 'c' && mode != 'd')
		throw 1;
	sortedList.sort(mode, 'l');
	return sortedList;
}

VectorDinamic<Car> carService::sortByType(const char& mode) const
{
	VectorDinamic<Car> sortedList = getCarList();
	if (mode != 'c' && mode != 'd')
		throw 1;
	sortedList.sort(mode, 't');
	return sortedList;
}

VectorDinamic<Car> carService::sortByProdModel(const char& mode) const
{
	VectorDinamic<Car> sortedList = getCarList();
	if (mode != 'c' && mode != 'd')
		throw 1;
	sortedList.sort(mode, 'p');
	return sortedList;
}

void testService()
{
	carRepo repo;
	carService service{ repo };

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
	catch (...)
	{
		assert (true);
	}

	// incercam sa adaugam o masina deja existenta
	try
	{
		service.addCar("AG-12-AAA", "RENAULT", "CLIO", "ALTELE");
	}
	catch (const int errCode)
	{
		assert (errCode == 1);
	}

	// verificam ca s-au adaugat masinile valide
	assert (service.getCarList().get(0).getLicensePlate() == "AG-12-AAA");
	assert (service.getCarList().get(0).getProducer() == "RENAULT");
	assert (service.getCarList().get(0).getModel() == "CLIO");
	assert (service.getCarList().get(0).getType() == "ALTELE");

	// verificam ca s-a modificat masina
	service.modifyCar("AG-12-AAA", "CJ-00-BGG", "SKODA", "FABIA", "SUV");
	assert (service.getCarList().get(0).getLicensePlate() == "CJ-00-BGG");
	assert (service.getCarList().get(0).getProducer() == "SKODA");
	assert (service.getCarList().get(0).getModel() == "FABIA");
	assert (service.getCarList().get(0).getType() == "SUV");

	// incercam sa modificam o masina inexistenta
	try
	{
		service.modifyCar("AA-00-AA", "AA-00-AAA", "PROD", "MODEL", "ALTELE");
	}
	catch (...)
	{
		assert (true);
	}

	try
	{
		service.modifyCar("CJ-00-BGG", "TEST", "TEST", "TEST", "TEST");
	}
	catch (...)
	{
		assert (true);
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
	catch (...)
	{
		assert (true);
	}

	// stergem o masina si verificam ca s-a micsorat marimea
	service.removeCar("CJ-00-BGG");
	assert (service.listSize() == 4);

	// incercam sa stergem o masina inexistenta
	try
	{
		service.removeCar("AA-00-AAA");
	}
	catch (...)
	{
		assert (true);
	}


	// teste pentru filtrarea dupa producator
	// testam cu un producator de masini existent in lista
	VectorDinamic<Car> carList = service.filterByProd("RENAULT");
	assert (carList.size() == 2);
	assert (carList.get(0).getLicensePlate() == "TR-45-POL");
	assert (carList.get(0).getProducer() == "RENAULT");
	assert (carList.get(0).getModel() == "ZOE");
	assert (carList.get(0).getType() == "SPORT");


	// testam cu un producator de masini inexistent in lista
	try
	{
		carList = service.filterByProd("FORD");
	}
	catch (...)
	{
		assert (true);
	}

	// teste pentru filtrarea dupa tip
	// testam cu un tip de masini existent in lista
	carList = service.filterByType("SPORT");
	assert (carList.size() == 3);
	assert (carList.get(0).getLicensePlate() == "CJ-01-AGH");
	assert (carList.get(0).getProducer() == "OPEL");
	assert (carList.get(0).getModel() == "CORSA");
	assert (carList.get(0).getType() == "SPORT");

	// testam cu un tip de masini inexistent in lista
	try
	{
		carList = service.filterByType("ALTELE");
	}
	catch (...)
	{
		assert (true);
	}

	// sortam descrescator dupa numarul de inmatriculare
	carList = service.sortByLicPlate('d');
	assert (carList.get(0).getLicensePlate() == "TR-45-POL");

	// sortam crescator dupa numarul de inmatriculare
	carList = service.sortByLicPlate('c');
	assert (carList.get(0).getLicensePlate() == "AB-98-GTR");

	// incercam sa sortam folosind un mod incorect
	try
	{
		carList = service.sortByLicPlate('g');
	}
	catch (...)
	{
		assert (true);
	}

	// sortam descrescator dupa tip
	carList = service.sortByType('d');
	assert (carList.get(0).getType() == "SUV");

	// sortam crescator dupa tip
	carList = service.sortByType('c');
	assert (carList.get(0).getType() == "SPORT");

	// incercam sa sortam folosind un mod incorect
	try
	{
		carList = service.sortByType('g');
	}
	catch (...)
	{
		assert (true);
	}

	// sortam descrescator dupa producator + model
	carList = service.sortByProdModel('d');
	assert (carList.get(0).getProducer() == "TOYOTA");

	// sortam crescator dupa producator + model
	carList = service.sortByProdModel('c');
	assert (carList.get(0).getProducer() == "OPEL");

	// incercam sa sortam folosind un mod incorect
	try
	{
		carList = service.sortByProdModel('g');
	}
	catch (...)
	{
		assert(true);
	}
}