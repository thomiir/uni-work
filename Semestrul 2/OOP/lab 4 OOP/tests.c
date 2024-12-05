#include "repo.h"
#include "service.h"
#include "validator.h"
#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

// teste pentru repo

void testRepo()
{

	// test pentru createEmpty()

	carList List = createEmpty(), *testList = &List;
	assert (testList->currentDIM == 0);
	assert (testList->maximumDIM == 10);


	// test pentru createCar()

	car testCar = createCar("AR-21-GGH", "VITARA", "mini", "disponibila");
	assert (strcmp(testCar.carLicPlate, "AR-21-GGH") == 0);
	assert (strcmp(testCar.carModel, "VITARA") == 0);
	assert (strcmp(testCar.carCat, "mini") == 0);
	assert (strcmp(testCar.carIsRented, "disponibila") == 0);


	// test pentru addCar()
	
	addCar(testList, testCar);
	assert (testList->currentDIM == 1);
	assert(strcmp(testList->cars[0].carLicPlate, "AR-21-GGH") == 0);
	assert(strcmp(testList->cars[0].carModel, "VITARA") == 0);
	assert(strcmp(testList->cars[0].carCat, "mini") == 0);
	assert(strcmp(testList->cars[0].carIsRented, "disponibila") == 0);

	car testCar2 = createCar("AB-04-ORT", "SUPERB", "sport", "inchiriata");
	addCar(testList, testCar2);
	assert(testList->currentDIM == 2);
	assert(strcmp(testList->cars[1].carLicPlate, "AB-04-ORT") == 0);
	assert(strcmp(testList->cars[1].carModel, "SUPERB") == 0);
	assert(strcmp(testList->cars[1].carCat, "sport") == 0);
	assert(strcmp(testList->cars[1].carIsRented, "inchiriata") == 0);


	// test pentru findCar()

	assert(findCar(testList, "AR-21-GGH") == 0);
	assert(findCar(testList, "AR-21-GGG") == -1);


	// test pentru deleteCar()

	deleteCar(testList, 0);
	assert (testList->currentDIM == 1);

	deleteCar(testList, 0);

	// dealocam memoria

	deleteCarList(testList);
}

// teste pentru service

void testService()
{

	// test pentru addCarSrv()

	carList empty = createEmpty(), *testList = &empty;
	
	// testam cu o masina valida
	assert (addCarSrv(testList, "AB-84-LKJ", "FX24", "mini", "disponibila") == 0);
	assert (addCarSrv(testList, "CS-51-DDF", "CORSA", "sport", "inchiriata") == 0);
	assert (addCarSrv(testList, "DB-32-ASX", "SMART", "altele", "disponibila") ==0);
	assert (addCarSrv(testList, "SV-50-TPL", "IGNIS", "mini", "inchiriata") == 0);
	assert (addCarSrv(testList, "BH-08-MGR", "FIESTA", "mini", "disponibila") == 0);

	// testam cu o masina invalida
	assert (addCarSrv(testList, "AB-84-LKJ", "FX24", "mini", "neinchiriata") == -2);

	// testam cu o masina existenta
	assert (addCarSrv(testList, "AB-84-LKJ", "FX24", "mini", "disponibila") == -1);
	

	// test pentru modifyCarSrv()

	// testam cu o masina care nu exista in repo
	assert (modifyCarSrv(testList, "AB-83-LKJ", "AB-83-LKJ", "FX24", "mini", "disponibila") == -1);

	// testam cu o masina invalida
	assert (modifyCarSrv(testList, "AB-84-LKJ", "AB-83-LKJ", "FX-24", "mini", "disponibila") == -2);

	// testam cu o masina valida
	assert (modifyCarSrv(testList, "AB-84-LKJ", "AB-83-LKJ", "FX24", "mini", "disponibila") == 0);

	
	// test pentru deleteCarSrv()
	
	// testam cu o masina care nu exista in repo
	assert (deleteCarSrv(testList, "AB-82-LKJ") == -1);

	// testam cu o masina valida
	assert (deleteCarSrv(testList, "AB-83-LKJ") == 0);


	// test pentru filterCarsByCarSrv()

	// testam cu o categorie care sa nu contina nicio masina
	carList filteredList = filterCarsByCatSrv(testList, "suv");
	assert (filteredList.currentDIM == 0);
	deleteCarList(&filteredList);


	// testam cu o categorie care sa contina masini
	filteredList = filterCarsByCatSrv(testList, "sport");
	assert (filteredList.currentDIM == 1);
	assert (strcmp(filteredList.cars[0].carLicPlate, "CS-51-DDF") == 0);
	assert (strcmp(filteredList.cars[0].carModel, "CORSA") == 0);
	assert (strcmp(filteredList.cars[0].carCat, "sport") == 0);
	assert (strcmp(filteredList.cars[0].carIsRented, "inchiriata") == 0);
	deleteCarList(&filteredList);


	// test pentru filterCarsByModelSrv()

	// testam cu un model care sa nu contina nicio masina
	filteredList = filterCarsByModelSrv(testList, "VITARA");
	assert (filteredList.currentDIM == 0);
	deleteCarList(&filteredList);


	// testam cu un model care sa contina masini
	filteredList = filterCarsByModelSrv(testList, "CORSA");
	assert (filteredList.currentDIM == 1);
	assert (strcmp(filteredList.cars[0].carLicPlate, "CS-51-DDF") == 0);
	assert (strcmp(filteredList.cars[0].carModel, "CORSA") == 0);
	assert (strcmp(filteredList.cars[0].carCat, "sport") == 0);
	assert (strcmp(filteredList.cars[0].carIsRented, "inchiriata") == 0);
	deleteCarList(&filteredList);

	
	// test pentru rentCarSrv()

	// testam cu o masina care sa nu existe in lista
	assert (rentCarSrv(testList, "CS-50-DDF") == -2);

	// testam cu o masina care este deja inchiriata
	assert (rentCarSrv(testList, "CS-51-DDF") == -1);

	// testam cu o masina valida
	assert (rentCarSrv(testList, "DB-32-ASX") == 0);
	int position = findCar(testList, "DB-32-ASX");
	assert (strcmp(testList->cars[position].carIsRented, "inchiriata") == 0);
	

	// test pentru returnCarSrv()

	// testam cu o masina care sa nu existe in lista
	assert (returnCarSrv(testList, "TR-20-ACS") == -2);

	// testam cu o masina care a fost deja returnata
	assert(returnCarSrv(testList, "BH-08-MGR") == -1);

	// testam cu o masina valida
	assert (returnCarSrv(testList, "SV-50-TPL") == 0);
	position = findCar(testList, "SV-50-TPL");
	assert (strcmp(testList->cars[position].carIsRented, "disponibila") == 0);
	

	// test pentru sortCarsByModelSrv()

	// testam crescator
	testList = sortCarsByModelSrv(testList, 'c');
	assert (strcmp(testList->cars[0].carLicPlate, "CS-51-DDF") == 0);
	assert (strcmp(testList->cars[1].carLicPlate, "BH-08-MGR") == 0);

	// testam descrescator
	testList = sortCarsByModelSrv(testList, 'd');
	assert(strcmp(testList->cars[0].carLicPlate, "DB-32-ASX") == 0);
	assert(strcmp(testList->cars[1].carLicPlate, "SV-50-TPL") == 0);
	

	// test pentru sortCarsByCatSrv()

	// testam crescator
	testList = sortCarsByCatSrv(testList, 'c');
	assert (strcmp(testList->cars[0].carLicPlate, "DB-32-ASX") == 0);

	// testam descrescator
	testList = sortCarsByCatSrv(testList, 'd');
	assert(strcmp(testList->cars[0].carLicPlate, "CS-51-DDF") == 0);

	deleteCarList(testList);
}

// teste pentru validator

void testValidate()
{
	
	// testam intai cu o masina care are toate datele corecte
	assert (validate("BH-54-BNC", "SPRING", "mini", "disponibila") == 1);


	// testam masini care au numarul de inmatriculare incorect
	assert (validate("AAAAAAAAAAAA", "SPRING", "mini", "disponibila") == 0);
	assert (validate("01-CT-001", "SANDERO", "sport", "inchiriata") == 0);


	// testam masini care au modelul incorect
	assert (validate("BH-54-BNC", ",.;", "mini", "inchiriata") == 0);
	assert (validate("BH-54-BNC", "C!", "altele", "disponibila") == 0);


	// testam masini care au categoria incorecta
	assert (validate("BH-54-BNC", "SPRING", "break", "inchiriata") == 0);
	assert (validate("BH-54-BNC", "SANDERO", "utilitara", "disponibila") == 0);


	// testam masini care au statusul incorect
	assert (validate("BH-54-BNC", "SPRING", "mini", "") == 0);
	assert (validate("BH-54-BNC", "SANDERO", "sport", "neinchiriata") == 0);
}

void runAllTests()
{
	testRepo();
	testService();
	testValidate();
}