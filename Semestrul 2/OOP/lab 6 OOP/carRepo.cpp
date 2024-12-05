#include "carRepo.h"
#include <cassert>
#include <iostream>
using namespace std;

void carRepo::add(const Car& c)
{
	cout << "inainte de add in repo\n";
	carList.push_back(c);
	cout << "dupa add in repo\n";
}

void carRepo::remove(const size_t& position)
{
	carList.erase(carList.begin() + position);
}

void carRepo::modify(const size_t& position, const Car& newCar)
{
	carList[position] = newCar;
}

size_t carRepo::find(const string& licensePlate) const
{
	for (size_t i = 0; i < carList.size(); i++)
		if (carList[i].getLicensePlate() == licensePlate)
			return i;
	return (size_t)-1;
}

const vector<Car>& carRepo::getList() const
{
	return carList;
}

size_t carRepo::size() const
{
	return carList.size();
}

void testRepo()
{
	Car testCar1{ "CT-99-CXC", "MAZDA", "CX90", "altele" };
	Car testCar2{ "AB-21-GBM", "SUZUKI", "VITARA", "sport" };
	Car testCar3{ "SV-01-ADL", "OPEL", "ASTRA", "mini" };
	carRepo repo;
	repo.add(testCar1);
	repo.add(testCar2);

	assert (repo.size() == 2);
	assert (repo.getList()[0].getLicensePlate() == testCar1.getLicensePlate());
	assert (repo.getList()[0].getProducer() == testCar1.getProducer());
	assert (repo.getList()[0].getModel() == testCar1.getModel());
	assert (repo.getList()[0].getType() == testCar1.getType());

	repo.modify(0, testCar3);
	assert (repo.getList()[0].getLicensePlate() == testCar3.getLicensePlate());
	assert (repo.getList()[0].getProducer() == testCar3.getProducer());
	assert (repo.getList()[0].getModel() == testCar3.getModel());
	assert (repo.getList()[0].getType() == testCar3.getType());

	repo.remove(1);
	assert (repo.size() == 1);

	size_t position = repo.find(testCar3.getLicensePlate());
	assert (repo.getList()[position].getLicensePlate() == testCar3.getLicensePlate());
	assert (repo.getList()[position].getProducer() == testCar3.getProducer());
	assert (repo.getList()[position].getModel() == testCar3.getModel());
	assert (repo.getList()[position].getType() == testCar3.getType());
	
	position = repo.find("AA-00-ABC");
	assert (position == (size_t)-1);
}