#pragma once
#include "car.h"

// creeaza un vector vid
carList createEmpty();

// creeaza un obiect de tip car
// returneaza masina creata
// char licPlate - numarul de inmatriculare al masinii
// char carModel - modelul masinii
// char carCat - categoria masinii
// char carIsRented - statusul masinii
car createCar(char licPlate[], char carModel[], char carCat[], char carIsRented[]);

// gasirea unei masini in vector
// returneaza pozitia masinii in vector daca aceasta exista, -1 altfel
// carList List - structura de masini
// char licPlate - numarul de inmatriculare al masinii pe care o cautam
int findCar(carList* List, char licPlate[]);

// adaugarea unei masini in vector
// carList* List - pointer la lista de masini 
// car newCar - masina pe care dorim sa o adaugam in lista
int addCar(carList* List, car newCar);

// stergerea masinii de pe pozitia pos
// carList* List - pointer la lista de masini
// int pos - pozitia masinii pe care dorim sa o stergem
int deleteCar(carList* List, int pos);