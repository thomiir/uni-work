#include "car.h"
#include <stdlib.h>
#include <string.h>

carList createEmpty()
{
	carList myCarList;
	myCarList.currentDIM = 0;
	myCarList.maximumDIM = 10;
	myCarList.cars = malloc(myCarList.maximumDIM * sizeof(car));
	return myCarList;
}

void deleteCarList(carList* myCarList)
{
	free(myCarList->cars);
}

int findCar(carList* List, char licPlate[])
{
	for (int i = 0; i < List->currentDIM; i++)
		if (strcmp(List->cars[i].carLicPlate, licPlate) == 0)
			return i;
	return -1;
}

void addCar(carList* List, car newCar)
{
	if (List->currentDIM < List->maximumDIM)
	{
		List->cars[List->currentDIM] = newCar;
		List->currentDIM++;
	}
	else
	{
		int newMaxDIM = List->maximumDIM * 2;
		car* newCars = realloc(List->cars, newMaxDIM * sizeof(car));
		if (newCars != NULL && List->cars != NULL)
		{
			List->cars = newCars;
			List->maximumDIM = newMaxDIM;
			List->cars[List->currentDIM] = newCar;
			List->currentDIM++;
		}
	}
}

void deleteCar(carList* List, int pos)
{
	for (int i = pos; i < List->currentDIM - 1; i++)
		List->cars[i] = List->cars[i + 1];
	List->currentDIM--;
}