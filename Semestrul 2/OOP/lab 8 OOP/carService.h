#pragma once
#include "car.h"
#include "carRepo.h"
#include <vector>
#include <string>
#include<map>
using namespace std;

class CarService
{
	private:
		// repository-ul curent
		CarRepo& repo;

	public:
		// constructorul clasei Service
		CarService(CarRepo& r) noexcept : repo{ r } {};

		// impiedicam crearea de noi obiecte de tip Service
		CarService(const CarService& cS) = delete;

		// getter pentru lista curenta de masini
		const vector<Car>& getCarList() const noexcept;

		// adaugarea unei masini in lista
		void addCar(const string& licensePlate, const string& producer, const string& model, const string& type);
		
		// modificarea unei masini din lista
		void modifyCar(const string& licensePlate, const string& newLicensePlate, const string& newProducer, const string& newModel, const string& newType);
		
		// stergerea unei masini din lista
		void removeCar(const string& licensePlate);

		// cautarea unei masini in lista
		const Car& findCar(const string& licensePlate) const;

		// getter pentru lungimea listei
		size_t listSize() const noexcept;

		// filtrare dupa producator
		vector<Car> filterByProd(const string& producer) const;

		// filtrare dupa tip
		vector<Car> filterByType(const string& type) const;

		// sortare dupa numarul de inmatriculare
		vector<Car> sortByLicPlate(const char& mode) const;

		// sortare dupa tip
		vector<Car> sortByType(const char& mode) const;
		
		// sortare dupa producator + model
		vector<Car> sortByProdModel(const char& mode) const;

		// creeaza raport
		map<string, int> report() const;

};

class WashService
{
	private:

		// service-ul pentru masini
		CarService& carService;
		
		// repository-ul pentru masinile de spalat
		CarRepo washRepo;

	public:

		// constructorul clasei WashService
		WashService(CarService& cS) noexcept : carService{ cS }, washRepo{} {};

		// getter pentru lungimea listei de masini de spalat
		size_t washSize() const noexcept
		{
			return washRepo.size();
		}

		// getter pentru lista de masini de spalat
		vector<Car> washList() const
		{
			return washRepo.getList();
		}

		// adaugam o masina noua in lista de spalat
		void addWash(const string& licensePlate);

		// golim lista de masini de spalat
		void emptyWash();

		// generam aleatoriu masini care sa fie spalate 
		void populateWash(size_t number);

		// impiedicam crearea de noi obiecte de tip Service
		WashService(const WashService& wS) = delete;

};

// teste pentru Service
void testService();