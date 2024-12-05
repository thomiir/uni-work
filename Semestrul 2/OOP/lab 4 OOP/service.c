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
	for (int i = 0; i < List->currentDIM; i++)
		if (strcmp(List->cars[i].carCat, cat) == 0)
		{
			newCarList.cars[newCarList.currentDIM] = List->cars[i];
			newCarList.currentDIM++;
		}
	return newCarList;
}

carList filterCarsByModelSrv(carList* List, char model[])
{
	carList newCarList = createEmpty();
	for (int i = 0; i < List->currentDIM; i++)
		if (strcmp(List->cars[i].carModel, model) == 0)
		{
			newCarList.cars[newCarList.currentDIM] = List->cars[i];
			newCarList.currentDIM++;
		}
	return newCarList;
}

int verifyStatus(carList* List, char licPlate[], char status[])
{
	int position = findCar(List, licPlate);
	if (position == -1)
		return -2; // eroare - masina nu exista in repo

	if (strcmp(List->cars[position].carIsRented, status) == 0)
		return -1; // masina a fost deja returnata sau inchiriata
	return position;
}

int rentCarSrv(carList* List, char licPlate[])
{
	int available = verifyStatus(List, licPlate, "inchiriata");
	if (available == -2 || available == -1)
		return available; // eroare - masina nu exista sau a fost deja inchiriata
	strcpy(List->cars[available].carIsRented, "inchiriata");
	return 0;
}

int returnCarSrv(carList* List, char licPlate[])
{
	int available = verifyStatus(List, licPlate, "disponibila");
	if (available == -2 || available == -1)
		return available; // eroare - masina nu exista sau a fost deja returnata
	strcpy(List->cars[available].carIsRented, "disponibila");
	return 0;
}

int cmp(const car* car1, const car* car2, const char mode, const char* field)
{
	if (strcmp(field, "model") == 0)
	{
		if (mode == 'd')
			return strcmp(car2->carModel, car1->carModel);
		else
			return strcmp(car1->carModel, car2->carModel);
	}
	else
	{
		if (mode == 'd')
			return strcmp(car2->carCat, car1->carCat);
		else
			return strcmp(car1->carCat, car2->carCat);
	}
}

void bsort(car* list, int DIM, char mode, char field[], int (*func)(car* car1, car* car2, char mode, char* field))
{
	int b = 0, e = 1;
	while (b == 0)
	{
		b = 1;
		for (int i = 0; i<DIM-e; i++)
			if (func(&list[i], &list[i + 1], mode, field) > 0)
			{
				car aux = list[i];
				list[i] = list[i + 1];
				list[i + 1] = aux;
				b = 0;
			}
		e++;
	}
}
carList* sortCarsByModelSrv(carList* List, char mode)
{
	bsort(List->cars, List->currentDIM, mode, "model", cmp);
	return List;
}

carList* sortCarsByCatSrv(carList* List, char mode)
{
	bsort(List->cars, List->currentDIM, mode, "cat", cmp);
	return List;
}