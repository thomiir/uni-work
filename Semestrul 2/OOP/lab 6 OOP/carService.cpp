#include "carService.h"
#include <cassert>
using namespace std;

void carService::addCar(const string& licensePlate, const string& producer, const string& model, const string& type)
{
	Car newCar { licensePlate, producer, model, type };
	repo.add(newCar);
}

void carService::modifyCar(const string& licensePlate, const string& newLicensePlate, const string& newProducer, const string& newModel, const string& newType)
{
	size_t position = repo.find(licensePlate);
	Car newCar { newLicensePlate, newProducer, newModel, newType };
	repo.modify(position, newCar);
}

void carService::removeCar(const string& licensePlate)
{
	size_t position = repo.find(licensePlate);
	repo.remove(position);
}

const Car carService::findCar(const string& licensePlate) const
{
	size_t position = repo.find(licensePlate);
	return getCarList()[position];
}

const vector<Car>& carService::getCarList() const
{
	return repo.getList();
}

size_t carService::listSize() const
{
	return repo.size();
}


void testService()
{
	carRepo repo;
	carService service{ repo };

	service.addCar("AG-12-AAA", "RENAULT", "CLIO", "altele");
	assert (service.getCarList()[0].getLicensePlate() == "AG-12-AAA");
	assert (service.getCarList()[0].getProducer() == "RENAULT");
	assert (service.getCarList()[0].getModel() == "CLIO");
	assert (service.getCarList()[0].getType() == "altele");

	service.modifyCar("AG-12-AAA", "CJ-00-BGG", "SKODA", "FABIA", "suv");
	assert (service.getCarList()[0].getLicensePlate() == "CJ-00-BGG");
	assert (service.getCarList()[0].getProducer() == "SKODA");
	assert (service.getCarList()[0].getModel() == "FABIA");
	assert (service.getCarList()[0].getType() == "suv");

	Car testCar = {"","","",""};	
	testCar = service.findCar("CJ-00-BGG");
	assert (testCar.getLicensePlate() == "CJ-00-BGG");
	assert (testCar.getProducer() == "SKODA");
	assert (testCar.getModel() == "FABIA");
	assert (testCar.getType() == "suv");

	service.removeCar("CJ-00-BGG");
	assert (service.listSize() == 0);
}