#include <stdio.h>

int prim(int nr)
{
	/*
	int prim(int nr) determina primalitatea variabilei nr
	parametru nr (int) - numarul despre care dorim sa verificam daca este prim  
	preconditii - nr este un numar natural 
	postconditii - returneaza 0 daca este compus, 1 daca este prim
	*/

	if (nr == 0 || nr == 1) return 0;
	for (int d = 2; d * d <= nr; d++)
		if (nr % d == 0) return 0;
	return 1;
}

void verifica(int n)
{
	/*
	verificarea ipotezei lui Goldbach
	preconditii - n natural, par
	postconditii - 
	*/

	for (int nr = 2; nr <= n; nr++)
		if (prim(nr) && prim(n - nr)) 
			{ 
			printf("%d = %d + %d\n", n, nr, n - nr);
			break; 
			}
}
int descompune(int n, int p)
{
	/*
	calcularea puterii la care apare p in n!
	preconditii - n natural nenul, p prim
	postconditii - nr natural, exponentul lui p in n!
	*/

	int nr = 0,x;
	for (int i = 1; i <= n; i++)
	{
		x = i;
		while (x % p == 0)
		{
			x /= p;
			nr++;
		}

	}
	return nr;
}
void print_menu()
{
	/*
	printarea meniului aplicatiei 
	*/

	printf("Alegeti o optiune din meniul aplicatiei:\n");
	printf("1. Verificati ipoteza lui Goldbach.\n");
	printf("2. Tipareste exponentul la care numarul p apare in descompunerea in factori primi a numarului N = 1*2*...*n.\n");
	printf("q. Iesire.\n");
}

int main()
{
	/*
	functia principala a programului
	*/

	int n,p;
	char option;
	while (1)
	{ 
		print_menu();
		scanf(" %c", &option);
		if (option == '1')
			{
			printf("Introduceti numarul n: ");
			scanf("%d", &n);
			verifica(n);
			}
		else if (option == '2')
		{
			printf("Introduceti numarul n: ");
			scanf("%d", &n);
			printf("Introduceti numarul p: ");
			scanf("%d", &p);
			printf("%d\n",descompune(n,p));
		}
		else if (option == 'q')
			break;
	}


	return 0;
}