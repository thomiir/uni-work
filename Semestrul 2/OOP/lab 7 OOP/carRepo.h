#pragma once
#include "car.h"
#include <vector>
#include <string>
#include "MyVector.h"
using namespace std;

class carRepo 
{
	private:
		// vectorul de masini
		VectorDinamic<Car> carList;

	public:
		// constructorul clasei repository
		carRepo() noexcept = default;

		// impiedicam crearea de noi obiecte repository
		carRepo(const carRepo& c) = delete;

		// adaugarea unei masini in vector
		void add(const Car& c);

		// modificarea unei masini din vector
		void modify(const int& position, const Car& newCar);

		// stergerea unei masini din vector
		void remove(const int& position);

		// cautarea unei masini in vector
		int find(const string& licensePlate) const;

		// getter pentru lista curenta de masini
		const VectorDinamic<Car>& getList() const noexcept;

		// getter pentru lungimea listei
		int size() const noexcept;

};

// teste pentru Repository
void testRepo();