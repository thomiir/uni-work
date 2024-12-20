#include <stdio.h>

int baza10(char sir[]);

int main()
{
    int a, ok;
    char sir[65];
    ok = 1;
    while (ok)
    {
        scanf("%s", sir);
        a = baza10(sir);
        if (a != 0) printf("%o\n", a);
        else ok = 0;
    }
    return 0;
}

