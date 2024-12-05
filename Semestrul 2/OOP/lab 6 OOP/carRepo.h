#pragma once
#include "car.h"
#include <vector>
#include <string>
using namespace std;

class carRepo 
{
	private:
		// vectorul de masini
		vector<Car> carList;

	public:
		// constructorul clasei repository
		carRepo() = default;

		// impiedicam crearea de noi obiecte repository
		carRepo(const carRepo& c) = delete;

		// adaugarea unei masini in vector
		void add(const Car& c);

		// modificarea unei masini din vector
		void modify(const size_t& position, const Car& newCar);

		// stergerea unei masini din vector
		void remove(const size_t& position);

		// cautarea unei masini in vector
		size_t find(const string& licensePlate) const;

		// getter pentru lista curenta de masini
		const vector<Car>& getList() const;

		// getter pentru lungimea listei
		size_t size() const;
};

// teste pentru Repository
void testRepo();