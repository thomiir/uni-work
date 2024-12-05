#include <stdio.h>

int main()
{
	int n, i, s = 0, x;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &x);
		s += x;
	}
	printf("Suma numerelor citite este: %d", s);
	return 0;
}