#include "car.h"

carList createEmpty()
{
	carList List;
	List.n = 0;
	return List;
}

car createCar(char licPlate[], char carModel[], char carCat[], char carIsRented[])
{
	car newCar;
	strcpy(newCar.carLicPlate, licPlate);
	strcpy(newCar.carModel, carModel);
	strcpy(newCar.carCat, carCat);
	strcpy(newCar.carIsRented, carIsRented);
	return newCar;
}

int findCar(carList* List, char licPlate[])
{
	for (int i = 0; i < List->n; i++)
		if (strcmp(List->cars[i].carLicPlate, licPlate) == 0)
			return i;
	return -1;
}

int addCar(carList* List, car newCar)
{
	List->cars[List->n] = newCar;
	List->n++;
}

int deleteCar(carList* List, int pos)
{
	for (int i = pos; i < List->n - 1; i++)
		List->cars[i] = List->cars[i + 1];
	List->n--;
}