#pragma once
#include "car.h"

// creeaza un vector vid
carList createEmpty();

// eliberam zona de memorie alocata listei de masini
// carList* List - pointer la lista de masini
void deleteCarList(carList* myCarList);

// gasirea unei masini in vector
// returneaza pozitia masinii in vector daca aceasta exista, -1 altfel
// carList* List - pointer la lista de masini
// char licPlate - numarul de inmatriculare al masinii pe care o cautam
int findCar(carList* List, char licPlate[]);

// adaugarea unei masini in vector
// carList* List - pointer la lista de masini 
// car newCar - masina pe care dorim sa o adaugam in lista
void addCar(carList* List, car newCar);

// stergerea masinii de pe pozitia pos
// carList* List - pointer la lista de masini
// int pos - pozitia masinii pe care dorim sa o stergem
void deleteCar(carList* List, int pos);