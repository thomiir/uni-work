#pragma once
#include "car.h"
#include <iostream>
#include <cassert>
template <typename Car>
class Iterator;
template <typename Car>
class VectorDinamic
{
	public:
		// constructorul clasei
		VectorDinamic();

		// constructorul de copiere
		VectorDinamic(const VectorDinamic& vd);

		// destructorul clasei
		~VectorDinamic();

		// move constructor
		VectorDinamic& operator=(VectorDinamic&& vd) noexcept;
		
		// adaugarea unui element in vector
		void add(const Car& c);

		// stergerea unui element din vector
		void remove(int poz);

		// getter pentru elementul de pe pozitia poz
		Car& get(int poz) const noexcept;

		// setter pentru elementul de pe pozitia poz
		void set(int poz, const Car& c);

		// getter pentru lungimea vectorului
		int size() const noexcept;

		// functie de sortare
		void sort(const char& mode, const char& field);

		// operator assignment
		VectorDinamic& operator=(const VectorDinamic& vd);

		friend class Iterator<Car>;

		// returneaza un iterator la inceputul vectorului
		Iterator<Car> begin();

		// returneaza un iterator la sfarsitul vectorului
		Iterator<Car> end();

	private:
		// dimensiunea curenta a vectorului
		int currentDIM;

		// dimensiunea maxima a vectorului
		int maximumDIM;
		
		// pointer la vectorul de masini
		Car* carList;

		// functie care aloca spatiu daca este nevoie
		void ensureCapacity();
};

// constructor
template<typename Car>
VectorDinamic<Car>::VectorDinamic(): currentDIM{ 0 }, maximumDIM{ 1 }, carList{ new Car[1] } {} ;

// constructor de copiere
template<typename Car>
VectorDinamic<Car>::VectorDinamic(const VectorDinamic<Car>& vd)
{
	carList = new Car[vd.maximumDIM];
	for (int i = 0; i < vd.currentDIM; i++)
		if (i < vd.maximumDIM)
			carList[i] = vd.carList[i];
	currentDIM = vd.currentDIM;
	maximumDIM = vd.maximumDIM;
}

// destructor
template<typename Car>
VectorDinamic<Car>::~VectorDinamic()
{
	delete[] carList;
}

// move constructor
// construim un nou vector dintr-un r-value (la return)
template<typename Car>
VectorDinamic<Car>& VectorDinamic<Car>::operator=(VectorDinamic<Car>&& vd) noexcept
{
	delete[] carList;
	carList = vd.carList;
	currentDIM = vd.currentDIM;
	maximumDIM = vd.maximumDIM;
	vd.carList = nullptr;
	vd.currentDIM = 0;
	vd.maximumDIM = 0;
	return *this;
}

// adaugarea unui element in vector
template<typename Car>
void VectorDinamic<Car>::add(const Car& c)
{
	ensureCapacity();
	carList[currentDIM++] = c;
}

// stergerea elementului de pe pozitia poz din vector
template<typename Car>
void VectorDinamic<Car>::remove(int poz)
{
	for (auto i = poz; i < currentDIM - 1; i++)
		carList[i] = carList[i + 1];
	currentDIM--;
}

// getter pentru un element de pe pozitia poz din vector
template<typename Car>
Car& VectorDinamic<Car>::get(int poz) const noexcept
{
	return carList[poz];
}

// setter pentru un element de pe pozitia poz din vector
template<typename Car>
void VectorDinamic<Car>::set(int poz, const Car& c)
{
	carList[poz] = c;
}

// getter pentru lungimea vectorului
template<typename Car>
int VectorDinamic<Car>::size() const noexcept
{
	return currentDIM;
}

// alocam spatiu in plus daca este cazul
template<typename Car>
void VectorDinamic<Car>::ensureCapacity()
{
	if (currentDIM < maximumDIM)
		return;

	maximumDIM = maximumDIM * 2;
	Car* aux = new Car[maximumDIM];
	for (int i = 0; i < currentDIM; i++)
		aux[i] = carList[i];
	delete[] carList;
	carList = aux;
}

// move constructor
template<typename Pet>
VectorDinamic<Pet>& VectorDinamic<Pet>::operator=(const VectorDinamic<Pet>& vd)
{
	delete[] carList;
	carList = new Pet[vd.maximumDIM];
	for (int i = 0; i < vd.currentDIM; i++)
		carList[i] = vd.carList[i];
	currentDIM = vd.currentDIM;
	maximumDIM = vd.maximumDIM;
	return *this;
}

// functia de comparare pentru sortare
inline int cmpF(const char& mode, const char& field, const Car& Car1, const Car& Car2)
{
	if (field == 'l') // sortam dupa licensePlate
	{
		if (mode == 'c') // sortam crescator
			return Car1.getLicensePlate() > Car2.getLicensePlate();
		else
			return Car1.getLicensePlate() < Car2.getLicensePlate();
	}

	if (field == 't') // sortam dupa tip
	{
		if (mode == 'c') // sortam crescator
			return Car1.getType() > Car2.getType();
		else
			return Car1.getType() < Car2.getType();
	}


	if (mode == 'c') // sortam crescator
		if (Car1.getProducer() == Car2.getProducer())
			return Car1.getModel() > Car2.getModel();
		else
			return Car1.getProducer() > Car2.getProducer();
	else
		if (Car1.getProducer() == Car2.getProducer())
			return Car1.getModel() < Car2.getModel();
		else
			return Car1.getProducer() < Car2.getProducer();

}

// sortarea vectorului de masini
template<typename Car>
void VectorDinamic<Car>::sort(const char& mode, const char& field)
{
	int b = 0;
	while (b == 0)
	{
		b = 1;
		for (int i = 0; i < currentDIM - 1; i++)
			if (cmpF(mode, field, carList[i], carList[i + 1]))
			{
				swap(carList[i], carList[i + 1]);
				b = 0;
			}
	}
}

template<typename Car>
class Iterator {
private:
	const VectorDinamic<Car>& v;
	int poz = 0;
public:
	// constructorul clasei Iterator
	Iterator(const VectorDinamic<Car>& v) noexcept;

	// constructor 
	Iterator(const VectorDinamic<Car>& v, int poz)noexcept;

	// verificarea iteratorului 
	bool valid()const;
	
	// getter pentru elementul curent
	Car& element() const;

	// trecerea la urmatorul element
	void next();

	// overload operator*
	// returneaza elementul []
	Car& operator*();

	// overload operator++
	Iterator& operator++();

	// overload operator ==
	bool operator==(const Iterator& ot)noexcept;

	// overload operator !=
	bool operator!=(const Iterator& ot)noexcept;
};

template<typename Car>
Iterator<Car>::Iterator(const VectorDinamic<Car>& v) noexcept :v{ v } {}

template<typename Car>
Iterator<Car>::Iterator(const VectorDinamic<Car>& v, int poz)noexcept : v{ v }, poz{ poz } {}

template<typename Car>
bool Iterator<Car>::valid()const {
	return poz < v.currentDIM;
}

template<typename Car>
Car& Iterator<Car>::element() const {
	return v.carList[poz];
}

template<typename Car>
void Iterator<Car>::next() {
	poz++;
}

template<typename Car>
Car& Iterator<Car>::operator*() {
	return element();
}

template<typename Car>
Iterator<Car>& Iterator<Car>::operator++() {
	next();
	return *this;
}

template<typename Car>
bool Iterator<Car>::operator==(const Iterator<Car>& ot) noexcept {
	return poz == ot.poz;
}

template<typename Car>
bool Iterator<Car>::operator!=(const Iterator<Car>& ot)noexcept {
	return !(*this == ot);
}

template<typename Car>
Iterator<Car> VectorDinamic<Car>::begin()
{
	return Iterator<Car>(*this);
}

template<typename Car>
Iterator<Car> VectorDinamic<Car>::end()
{
	return Iterator<Car>(*this, currentDIM);
}