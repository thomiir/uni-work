#include "repo.h"

void addImplicitInput(carList* List)
{
	car newCar;

	newCar = createCar("CT-99-BFL", "CX90", "mini", "inchiriata");
	addCar(List, newCar);

	newCar = createCar("CJ-10-BCX", "VITARA", "sport", "disponibila");
	addCar(List, newCar);

	newCar = createCar("AB-01-LOP", "ASTRA", "mini", "disponibila");
	addCar(List, newCar);

	newCar = createCar("HG-44-MGR", "ASTRA", "mini", "disponibila");
	addCar(List, newCar);

	newCar = createCar("CT-74-CXC", "VITARA", "suv", "disponibila");
	addCar(List, newCar);

	newCar = createCar("TL-62-EWR", "FABIA", "suv", "inchiriata");
	addCar(List, newCar);

	newCar = createCar("GR-08-FVV", "CX90", "altele", "disponibila");
	addCar(List, newCar);

	newCar = createCar("SV-30-ADL", "FABIA", "altele", "disponibila");
	addCar(List, newCar);

	newCar = createCar("CT-23-NOE", "FABIA", "sport", "inchiriata");
	addCar(List, newCar);

	newCar = createCar("AR-19-DEC", "CX90", "sport", "inchiriata");
	addCar(List, newCar);
}