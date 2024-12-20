#include <stdio.h>

int base10(char sir[]);

int main()
{
    int a, ok;
    char sir[65];
    ok = 1;
    while (ok)
    {
        scanf("%s", sir);
        a = base10(sir);
        if (a != 0) printf("%o\n", a);
        else ok = 0;
    }
    return 0;
}

int base10(char sir[])
{return 0;}
