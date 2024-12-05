#include "carRepo.h"
#include <cassert>
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

void CarRepo::add(const Car& c)
{
	carList.push_back(c);
}

void CarRepo::remove(const __int64& position)
{
	carList.erase(carList.begin() + position);
}

void CarRepo::modify(const __int64& position, const Car& newCar)
{
	carList.at(position) = newCar;
}

__int64 CarRepo::find(const string& licensePlate) const
{

	auto x = find_if(carList.begin(), carList.end(), [licensePlate](const Car& car) {return car.getLicensePlate() == licensePlate; });
	const __int64 y = distance(carList.begin(), x);
	if (y - carList.size() == 0)
		return -1;
	return y;
}

const vector<Car>& CarRepo::getList() const noexcept
{
	return carList;
}

size_t CarRepo::size() const noexcept
{
	return carList.size();
}

void testRepo()
{
	Car testCar1{ "CT-99-CXC", "MAZDA", "CX90", "altele" };
	Car testCar2{ "AB-21-GBM", "SUZUKI", "VITARA", "sport" };
	Car testCar3{ "SV-01-ADL", "OPEL", "ASTRA", "mini" };
	CarRepo repo;

	// adaugam doua masini in repo
	repo.add(testCar1);
	repo.add(testCar2);

	// verificam ca s-au adaugat corect
	assert (repo.size() == 2);
	assert (repo.getList().at(0).getLicensePlate() == testCar1.getLicensePlate());
	assert (repo.getList().at(0).getProducer() == testCar1.getProducer());
	assert (repo.getList().at(0).getModel() == testCar1.getModel());
	assert (repo.getList().at(0).getType() == testCar1.getType());

	// modificam prima masina
	repo.modify(0, testCar3);
	assert (repo.getList().at(0).getLicensePlate() == testCar3.getLicensePlate());
	assert (repo.getList().at(0).getProducer() == testCar3.getProducer());
	assert (repo.getList().at(0).getModel() == testCar3.getModel());
	assert (repo.getList().at(0).getType() == testCar3.getType());

	// stergem o masina
	repo.remove(1);
	assert (repo.size() == 1);

	// cautam o masina
	__int64 position;
	position = repo.find(testCar3.getLicensePlate());
	assert (repo.getList().at(position).getLicensePlate() == testCar3.getLicensePlate());
	assert (repo.getList().at(position).getProducer() == testCar3.getProducer());
	assert (repo.getList().at(position).getModel() == testCar3.getModel());
	assert (repo.getList().at(position).getType() == testCar3.getType());

	// cautam o masina care nu exista
	position = repo.find("AB-00-AAA");
	assert (position == -1);
	
}