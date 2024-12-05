#include "carRepo.h"
#include "MyVector.h"
#include <cassert>
#include <iostream>
using namespace std;

void carRepo::add(const Car& c)
{
	carList.add(c);
}

void carRepo::remove(const int& position)
{
	carList.remove(position);
}

void carRepo::modify(const int& position, const Car& newCar)
{
	carList.set(position, newCar);
}

int carRepo::find(const string& licensePlate) const
{
	for (int i = 0; i < carList.size(); i++)
		if (carList.get(i).getLicensePlate() == licensePlate)
			return i;
	return -1;
}

const VectorDinamic<Car>& carRepo::getList() const noexcept
{
	return carList;
}

int carRepo::size() const noexcept
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
	assert (repo.getList().get(0).getLicensePlate() == testCar1.getLicensePlate());
	assert (repo.getList().get(0).getProducer() == testCar1.getProducer());
	assert (repo.getList().get(0).getModel() == testCar1.getModel());
	assert (repo.getList().get(0).getType() == testCar1.getType());

	repo.modify(0, testCar3);
	assert (repo.getList().get(0).getLicensePlate() == testCar3.getLicensePlate());
	assert (repo.getList().get(0).getProducer() == testCar3.getProducer());
	assert (repo.getList().get(0).getModel() == testCar3.getModel());
	assert (repo.getList().get(0).getType() == testCar3.getType());

	repo.remove(1);
	assert (repo.size() == 1);

	int position = repo.find(testCar3.getLicensePlate());
	assert (repo.getList().get(position).getLicensePlate() == testCar3.getLicensePlate());
	assert (repo.getList().get(position).getProducer() == testCar3.getProducer());
	assert (repo.getList().get(position).getModel() == testCar3.getModel());
	assert (repo.getList().get(position).getType() == testCar3.getType());
	
	position = repo.find("AA-00-ABC");
	assert (position == -1);
}