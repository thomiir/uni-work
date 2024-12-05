#include <string.h>
#include <ctype.h>

int validate(char licPlate[], char model[], char cat[], char isRented[])
{
	// validam numarul de inmatriculare
	// este de forma XX-00-XXX, unde X poate sa fie orice majuscula, iar 0 orice litera

	if (strlen(licPlate) > 9)
		return 0;

	if (isupper(licPlate[0]) == 0 || isupper(licPlate[1]) == 0 || isupper(licPlate[6]) == 0 &&
		isupper(licPlate[7]) == 0 || isupper(licPlate[8]) == 0 || isdigit(licPlate[3]) == 0 &&
		isdigit(licPlate[4]) == 0 || licPlate[2] != '-' || licPlate[5] != '-')
		return 0;

	// validam modelul
	// trebuie sa contina doar majuscule si cifre

	for (int i = 0; i < strlen(model); i++)
		if (isupper(model[i]) == 0 && isdigit(model[i]) == 0)
			return 0;

	// validam categoria
	// categoria este doar din multimea {sport, suv, mini, altele}

	if (strcmp(cat, "sport") != 0 && strcmp(cat, "suv") != 0 && strcmp(cat, "mini") != 0 &&
		strcmp(cat, "altele") != 0)
		return 0;

	// validam statusul de inchiriere
	// isRented poate fi doar "disponibila" sau "inchiriata"

	if (strcmp(isRented, "disponibila") != 0 && strcmp(isRented, "inchiriata") != 0)
		return 0;

	
	// daca a trecut de toate etapele de validare, datele masinii sunt bune

	return 1;
}