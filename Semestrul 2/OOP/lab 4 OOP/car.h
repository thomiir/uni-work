#pragma once

// obiectul de tip masina
typedef struct{
	/*
	carLicPlate - numarul de inmatriculare al masinii
	carModel - modelul masinii
	carCat - categoria masinii (mini, sport, suv, altele)
	carIsRented - starea masinii (este sau nu inchiriata)
	*/

	char carLicPlate[50];
	char carModel[50];
	char carCat[50];
	char carIsRented[15];
}car;

// lista care retine numarul de masini si vectorul aferent 
typedef struct
{
	// cars este vectorul de masini
	// currentDIM este lungimea curenta a vectorului
	// maximumDIM este lungimea maxima a vectorului

	car* cars;
	int currentDIM;
	int maximumDIM;
}carList;

// creeaza un obiect de tip car
// returneaza masina creata
// char licPlate - numarul de inmatriculare al masinii
// char carModel - modelul masinii
// char carCat - categoria masinii
// char carIsRented - statusul masinii
car createCar(char licPlate[], char carModel[], char carCat[], char carIsRented[]);
