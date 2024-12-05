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
		void printAllCars(const VectorDinamic<Car>& carList);

		// printarea meniului principal
		void printMenu();

		// printarea unei singure masini
		void printCar(const Car& car);

		// filtrarea dupa producator
		void filterByProdUI();

		// filtrarea dupa tip
		void filterByTypeUI();

		// sortarea dupa numarul de inmatriculare
		void sortByLicPlateUI();

		// sortarea dupa tip
		void sortByTypeUI();

		// sortarea dupa producator + model
		void sortByProdModelUI();

	public:
		
		// constructorul clasei Console
		carConsole(carService& cS) noexcept : service{cS} {};

		// nu permitem crearea de noi obiecte de tip Console
		carConsole(const carConsole& cS) = delete;

		// functia principala de start
		void start();
};