#pragma once
#include "car.h"
#include "carRepo.h"
#include <vector>
#include <string>
using namespace std;

class carService
{
	private:
		// repository-ul curent
		carRepo& repo;

	public:
		// constructorul clasei Service
		carService(carRepo& r) : repo{ r } {};

		// impiedicam crearea de noi obiecte de tip Service
		carService(const carService& cS) = delete;

		// getter pentru lista curenta de masini
		const vector<Car>& getCarList() const;

		// adaugarea unei masini in lista
		void addCar(const string& licensePlate, const string& producer, const string& model, const string& type);
		
		// modificarea unei masini din lista
		void modifyCar(const string& licensePlate, const string& newLicensePlate, const string& newProducer, const string& newModel, const string& newType);
		
		// stergerea unei masini din lista
		void removeCar(const string& licensePlate);

		// cautarea unei masini in lista
		const Car findCar(const string& licensePlate) const;

		// getter pentru lungimea listei
		size_t listSize() const;
};

// teste pentru Service
void testService();