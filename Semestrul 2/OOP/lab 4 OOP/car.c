#include "car.h"
#include <string.h>

car createCar(char licPlate[], char carModel[], char carCat[], char carIsRented[])
{
	car newCar;
	strcpy(newCar.carLicPlate, licPlate);
	strcpy(newCar.carModel, carModel);
	strcpy(newCar.carCat, carCat);
	strcpy(newCar.carIsRented, carIsRented);
	return newCar;
}