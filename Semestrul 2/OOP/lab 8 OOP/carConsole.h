#pragma once
#include "car.h"
#include "carService.h"

class CarConsole
{
	private:
		// service
		CarService& carService;
		WashService& washService;

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

		// printarea meniului pentru spalarea masinilor
		void printWashMenu();

		// golirea listei de masini care trebuie spalate
		void emptyWashList();

		// adauga in lista de masini care trebuie spalate
		void addToWashList();

		// genereaza aleatoriu lista de masini care trebuie spalate
		void generateWashList();

		// genereaza raport
		void generateReport();

	public:
		
		// constructorul clasei Console
		CarConsole(CarService& cS, WashService& wS) noexcept : carService{ cS }, washService{ wS } {};

		// nu permitem crearea de noi obiecte de tip Console
		CarConsole(const CarConsole& cS) = delete;

		// functia principala de start
		void start();
};