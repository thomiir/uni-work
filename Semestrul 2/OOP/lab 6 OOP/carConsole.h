#pragma once
#include "car.h"
#include "carService.h"

class carConsole
{
	private:
		// service
		carService& service;

		// adaugarea unei masini
		void addCarUI();

		// modificarea unei masini
		void modifyCarUI();

		// stergerea unei masini
		void removeCarUI();

		// cautarea unei masini
		void findCarUI();

		// afisarea listei curente de masini
		void printAllCars(const vector<Car>& carList);

		// printarea meniului principal
		void printMenu();

		void printCar(const Car& car);

	public:
		
		// constructorul clasei Console
		carConsole(carService& cS) : service{cS} {};

		// nu permitem crearea de noi obiecte de tip Console
		carConsole(const carConsole& cS) = delete;

		// functia principala de start
		void start();
};