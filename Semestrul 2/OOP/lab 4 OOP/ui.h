#pragma once
#include "car.h"

// printarea meniului principal al aplicatiei, unde utilizatorul poate sa vada toate 
// functionalitatile
void printMainMenu();

// printarea listei de masini
// carList* List - pointer la lista de masini
void printList(carList* List);

// citirea datelor unei masini si adaugarea acesteia
// carList* List - pointer la lista de masini
void addCarUI(carList* List);

// citirea datelor unei masini si modificarea acesteia
// carList* List - pointer la lista de masini
void modifyCarUI(carList* List);

// citirea datelor unei masini si stergerea acesteia
// carList* List - pointer la lista de masini
void deleteCarUI(carList* List);

// citirea categoriei si filtrarea listei dupa aceasta
// carList* List - pointer lista de masini
void filterCarsByCatUI(carList* List);

// citirea modelului si filtrarea listei dupa acesta
// carList* List - pointer lista de masini
void filterCarsByModelUI(carList* List);

// citirea datelor unei masini si inchirierea acesteia
// carList* List - pointer lista de masini
void rentCarUI(carList* List);

// citirea datelor unei masini si returnarea acesteia
// carList* List - pointer lista de masini
void returnCarUI(carList* List);

// citirea modului de sortare (c = crescator, d = descrescator) si sortarea listei de masini in
// functie de model, in ordinea data de mod
// carList* List - pointer lista de masini
void sortCarsByModelUI(carList* List);

// citirea modului de sortare (c = crescator, d = descrescator) si sortarea listei de masini in
// functie de categorie, in ordinea data de mod
// carList* List - pointer lista de masini
void sortCarsByCatUI(carList* List);

// functia principala de pornire a programului
void run();

