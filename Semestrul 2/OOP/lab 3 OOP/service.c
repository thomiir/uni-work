#include "repo.h"
#include "validator.h"
#include <stdlib.h>
#include <string.h>

int addCarSrv(carList* List, char licPlate[], char model[], char cat[], char isRented[])
{
	int validCar = validate(licPlate, model, cat, isRented);
	if (validCar == 0)
		return -2; // eroare, datele masinii sunt invalide
	car newCar = createCar(licPlate, model, cat, isRented);
	int existing = findCar(List, licPlate);
	if (existing == -1)
	{		
		addCar(List, newCar);
		return 0;
	}

		return -1; // eroare - masina deja exista in repo, deci nu avem ce adauga 
}

int modifyCarSrv(carList* List, char licPlate[], char newLicPlate[], char newModel[], char newCat[], char newIsRented[])
{
	int position = findCar(List, licPlate);
	if (position == -1)
		return -1; // eroare - masina nu exista in repo
	else
	{
		int validCar = validate(newLicPlate, newModel, newCat, newIsRented);
		if (validCar == 0) 
			return -2; // eroare, noile date ale masinii sunt invalide
		car newCar = createCar(newLicPlate, newModel, newCat, newIsRented);
		List->cars[position] = newCar;
		return 0;
	}
}

int deleteCarSrv(carList* List, char licPlate[])
{
	int position = findCar(List, licPlate);
	if (position != -1)
	{
		deleteCar(List, position);
		return 0;
	}

		return -1; // eroare - masina nu exista in repo, deci nu avem ce sterge
}

carList filterCarsByCatSrv(carList* List, char cat[])
{
	carList newCarList = createEmpty();
	for (int i = 0; i < List->n; i++)
		if (strcmp(List->cars[i].carCat, cat) == 0)
		{
			newCarList.cars[newCarList.n] = List->cars[i];
			newCarList.n++;
		}
	return newCarList;
}

carList filterCarsByModelSrv(carList* List, char model[])
{
	carList newCarList = createEmpty();
	for (int i = 0; i < List->n; i++)
		if (strcmp(List->cars[i].carModel, model) == 0)
		{
			newCarList.cars[newCarList.n] = List->cars[i];
			newCarList.n++;
		}
	return newCarList;
}

int verifyIfAvailable(carList* List, char licPlate[])
{
	int position = findCar(List, licPlate);
	if (position == -1)
		return -2; // eroare - masina nu exista in repo

	if (strcmp(List->cars[position].carIsRented, "inchiriata") == 0)
		return -1; // masina este deja inchiriata
	return position;
}

int verifyIfRented(carList* List, char licPlate[])
{
	int position = findCar(List, licPlate);
	if (position == -1)
		return -2; // eroare - masina nu exista in repo

	if (strcmp(List->cars[position].carIsRented, "disponibila") == 0)
		return -1; // masina a fost deja returnata
	return position;

}

int rentCarSrv(carList* List, char licPlate[])
{
	int available = verifyIfAvailable(List, licPlate);
	if (available == -2 || available == -1)
		return available; // eroare - masina nu exista sau a fost deja inchiriata
	
	\
		strcpy(List->cars[available].carIsRented, "inchiriata");
	return 0;
}

int returnCarSrv(carList* List, char licPlate[])
{
	int available = verifyIfRented(List, licPlate);
	if (available == -2 || available == -1)
		return available; // eroare - masina nu exista sau a fost deja returnata
	else
	{
		strcpy(List->cars[available].carIsRented, "disponibila");
		return 0;
	}

}

int cmpModelAsc(const car car1, const car car2)
{
	return strcmp(car1.carModel, car2.carModel);
}

int cmpModelDesc(const car car1, const car car2)
{
	return strcmp(car2.carModel, car1.carModel);
}

carList* sortCarsByModelSrv(carList* List, char mode)
{
	if (mode == 'c')
		qsort(List->cars, List->n, sizeof(car), cmpModelAsc);
	else
		qsort(List->cars, List->n, sizeof(car), cmpModelDesc);
	
	return List;
}

int cmpCatAsc(const car car1, const car car2)
{
	return strcmp(car1.carCat, car2.carCat);
}

int cmpCatDesc(const car car1, const car car2)
{
	return strcmp(car2.carCat, car1.carCat);
}

carList* sortCarsByCatSrv(carList* List, char mode)
{
	if (mode == 'c')
		qsort(List->cars, List->n, sizeof(car), cmpCatAsc);
	else
		qsort(List->cars, List->n, sizeof(car), cmpCatDesc);

	return List;
}