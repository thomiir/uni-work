#pragma once
#include "car.h"
#include <vector>
#include <string>
using namespace std;

class CarRepo 
{
	private:
		// vectorul de masini
		vector<Car> carList = {};

	public:
		// constructorul clasei repository
		CarRepo() noexcept = default;

		// impiedicam crearea de noi obiecte repository
		CarRepo(const CarRepo& c) = delete;

		// adaugarea unei masini in vector
		void add(const Car& c);

		// modificarea unei masini din vector
		void modify(const __int64& position, const Car& newCar);

		// stergerea unei masini din vector
		void remove(const __int64& position);

		// cautarea unei masini in vector
		__int64 find(const string& licensePlate) const;

		// getter pentru lista curenta de masini
		const vector<Car>& getList() const noexcept;

		// getter pentru lungimea listei
		size_t size() const noexcept;
};

// teste pentru Repository
void testRepo();