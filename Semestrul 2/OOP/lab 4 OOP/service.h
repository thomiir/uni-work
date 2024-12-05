#pragma once
#include "repo.h"

// adaugarea unei masini
// carList* List - pointer la lista de masini
// char licPlate - numarul de inmatriculare
// char model - modelul masinii
// char cat - categoria masinii
// char isRented - statusul masinii
// returneaza -2 daca datele masinii sunt invalide, -1 daca masina exista deja si 0 daca nu au fost erori
int addCarSrv(carList* List, char licPlate[], char model[], char cat[], char isRented[]);

// modificarea unei masini
// carList* List - pointer la lista de masini
// char licPlate - numarul de inmatriculare dupa care cautam
// char newLicPlate - noul numar de inmatriculare
// char newModel - noul model al masinii
// char newCat - noua categorie a masinii
// char newIsRented - noul status al masinii
// returneaza -2 daca datele masinii sunt invalide, -1 daca masina nu exista si 0 daca nu au fost erori
int modifyCarSrv(carList* List, char licPlate[], char newLicPlate[], char newModel[], char newCat[], char newIsRented[]);

// stergerea unei masini
// carList* List - pointer la lista de masini
// char licPlate - numarul de inmatriculare al masinii pe care dorim sa o stergem
int deleteCarSrv(carList* List, char licPlate[]);

// filtrarea listei de masini dupa categorie
// carList* List - pointer la lista de masini
// char cat - categoria dupa care filtram
// returneaza o alta lista, filtrata dupa categorie
carList filterCarsByCatSrv(carList* List, char cat[]);

// filtrarea listei de masini dupa model
// carList* List - pointer la lista de masini
// char model - modelul dupa care filtram
// returneaza o alta lista, filtrata dupa model
carList filterCarsByModelSrv(carList* List, char model[]);

// inchirierea unei masini
// carList* List - pointer la lista de masini
// char licPlate - numarul de inmatriculare al masinii pe care dorim sa o inchiriem
// returneaza -2 daca masina nu exista, -1 daca ea a fost deja inchiriata si 0 daca nu au fost erori
int rentCarSrv(carList* List, char licPlate[]);

// returnarea unei masini
// carList* List - pointer la lista de masini
// char licPlate - numarul de inmatriculare al masinii pe care dorim sa o returnam
// returneaza -2 daca masina nu exista, -1 daca ea a fost deja returnata si 0 daca nu au fost erori
int returnCarSrv(carList* List, char licPlate[]);

// sortarea listei de masini dupa model
// carList* List - pointer la lista de masini
// char mode - modul in care sortam; c = crescator, d = descrescator
// returneaza un pointer la lista de masini sortata dupa model 
carList* sortCarsByModelSrv(carList* List, char mode);

// sortarea listei de masini dupa categorie
// carList* List - pointer la lista de masini
// char mode - modul in care sortam; c = crescator, d = descrescator
// returneaza un pointer la lista de masini sortata dupa categorie 
carList* sortCarsByCatSrv(carList* List, char mode);
