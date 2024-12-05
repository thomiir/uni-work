#include "service.h"
#include "implicit_input.h"
#include <stdio.h>
#include <stdlib.h>

void printMainMenu()
{
	printf("Alegeti o optiune din meniul de mai jos:\n");
	printf("1. Adaugati o masina.\n");
	printf("2. Modificati o masina.\n");
	printf("3. Stergeti o masina.\n");
	printf("4. Filtrati masinile dupa model.\n");
	printf("5. Filtrati masinile dupa categorie.\n");
	printf("6. Inchiriati o masina.\n");
	printf("7. Returnati o masina.\n");
	printf("8. Sortati masinile dupa model.\n");
	printf("9. Sortati masinile dupa categorie.\n");
	printf("0. Iesire.\n");
}

void printList(carList* List)
{
	for (int i = 0; i < List->currentDIM; i++)
		printf("%10s %10s %10s %15s\n", List->cars[i].carLicPlate, List->cars[i].carModel, List->cars[i].carCat, List->cars[i].carIsRented);
}

void addCarUI(carList* List)
{
	char licPlate[15], model[15], cat[15];
	printf("Introduceti datele masinii pe care doriti sa o adaugati:\n");
	printf("Numarul de inmatriculare: ");
	scanf_s("%s", licPlate, 15);
	printf("Modelul:");
	scanf_s("%s", model, 15);
	printf("Categoria: ");
	scanf_s("%s", cat, 15);
	int retValue = addCarSrv(List, licPlate, model, cat, "disponibila");
	if (retValue == -1)
		printf("Eroare la adaugarea masinii. Masina deja exista in baza de date!\n");
	else if (retValue == -2)
		printf("Eroare la adaugarea masinii. Datele masinii sunt invalide!\n");
	else
		printf("Masina a fost adaugata cu succes!\n");
}

void modifyCarUI(carList* List)
{
	char licPlate[15], newLicPlate[15], newModel[15], newCat[15], newIsRented[15];
	printf("Introduceti numarul de inmatriculare al masinii pe care doriti sa o modificati:");
	scanf_s("%s", licPlate, 15);
	printf("Introduceti noul numar de inmatriculare al masinii:");
	scanf_s("%s", newLicPlate, 15);
	printf("Introduceti noul model al masinii:");
	scanf_s("%s", newModel, 15);
	printf("Introduceti noua categorie a masinii:");
	scanf_s("%s", newCat, 15);
	printf("Introduceti noul status al masinii:");
	scanf_s("%s", newIsRented, 15);
	int retValue = modifyCarSrv(List, licPlate, newLicPlate, newModel, newCat, newIsRented);
	if (retValue == -1)
		printf("Eroare la modificarea masinii. Masina nu exista in baza de date!\n");
	else
		printf("Masina a fost modificata cu succes!\n");
}

void deleteCarUI(carList* List)
{
	char licPlate[15];
	printf("Introduceti numarul de inmatriculare al masinii pe care doriti sa o stergeti:");
	scanf_s("%s", licPlate, 15);
	int retValue = deleteCarSrv(List, licPlate);
	if (retValue == -1)
		printf("Eroare la stergerea masinii. Masina nu exista in baza de date!\n");
	else
		printf("Masina a fost stearsa cu succes!\n");

}

void filterCarsByCatUI(carList* List)
{
	char cat[15];
	carList filteredList;
	printf("Introduceti categoria dupa care doriti sa filtrati:");
	scanf_s("%s", cat, 15);
	filteredList = filterCarsByCatSrv(List, cat);
	if (filteredList.currentDIM != 0)
	{
		printf("Lista filtrata este:\n");
		printList(&filteredList);
	}
	else
		printf("Nu exista nicio masina din aceasta categorie!\n");
	deleteCarList(&filteredList);
}

void filterCarsByModelUI(carList* List)
{
	char model[15];
	carList filteredList;
	printf("Introduceti modelul dupa care doriti sa filtrati:");
	scanf_s("%s", model, 15);
	filteredList = filterCarsByModelSrv(List, model);
	if (filteredList.currentDIM != 0)
	{
		printf("Lista filtrata este:\n");
		printList(&filteredList);
	}
	else
		printf("Nu exista acest model de masina!\n");
	deleteCarList(&filteredList);
	
}

void rentCarUI(carList* List)
{
	char licPlate[15];
	printf("Introduceti numarul de inmatriculare al masinii pe care doriti sa o inchiriati:");
	scanf_s("%s", licPlate, 15);
	int retValue = rentCarSrv(List, licPlate);
	if (retValue == 0)
		printf("Masina a fost inchiriata cu succes!\n");
	else if (retValue == -2)
		printf("Nu exista o masina cu acest numar de inmatriculare in baza de date!\n");
	else
		printf("Masina a fost deja inchiriata!\n");
}

void returnCarUI(carList* List)
{
	char licPlate[15];
	printf("Introduceti numarul de inmatriculare al masinii pe care doriti sa o returnati:");
	scanf_s("%s", licPlate, 15);
	int retValue = returnCarSrv(List, licPlate);
	if (retValue == 0)
		printf("Masina a fost returnata cu succes!\n");
	else if (retValue == -2)
		printf("Nu exista o masina cu acest numar de inmatriculare in baza de date!\n");
	else
		printf("Masina a fost deja returnata!\n");
}

void sortCarsByModelUI(carList* List)
{
	char mode;
	printf("Introduceti d pentru sortare descrescatoare, respectiv c pentru sortare crescatoare:\n");
	scanf_s(" %c", &mode, 1);
	if (mode == 'd' || mode == 'c')
		List = sortCarsByModelSrv(List, mode);
	else printf("Mod invalid!\n");
}

void sortCarsByCatUI(carList* List)
{
	char mode;
	printf("Introduceti d pentru sortare descrescatoare, respectiv c pentru sortare crescatoare:\n");
	scanf_s(" %c", &mode, 1);
	if (mode == 'd' || mode == 'c')
		List = sortCarsByCatSrv(List, mode);
	else printf("Mod invalid!\n");
}

void run()
{
	carList empty = createEmpty(), *List = &empty;
	int option;
	addImplicitInput(List);

	while (1)
	{
		printf("Lista curenta de masini este:\n");
		printList(List);

		printMainMenu();
		scanf_s("%d", &option);

		if (option == 1)
			addCarUI(List);

		else if (option == 2)
			modifyCarUI(List);

		else if (option == 3)
			deleteCarUI(List);

		else if (option == 4)
			filterCarsByModelUI(List);

		else if (option == 5)
			filterCarsByCatUI(List);

		else if (option == 6)
			rentCarUI(List);

		else if (option == 7)
			returnCarUI(List);

		else if (option == 8)
			sortCarsByModelUI(List);

		else if (option == 9)
			sortCarsByCatUI(List);

		else if (option == 0)
			break;
	}
	deleteCarList(List);
}