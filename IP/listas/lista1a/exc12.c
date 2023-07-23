#include <stdio.h>

#define CEM 100
#define CIN 50
#define DEZ 10
#define UM 1

int main(void)
{
    int cash, cem = 0, cin = 0, dez = 0, um = 0;

    scanf("%d", &cash);

    while (cash >= CEM)
    {
        cash -= CEM;
        cem++;
    }

    while (cash >= CIN)
    {
        cash -= CIN;
        cin++;
    }

    while (cash >= DEZ)
    {
        cash -= DEZ;
        dez++;
    }

    while (cash >= 1)
    {
        cash -= UM;
        um++;
    }

    printf("NOTAS DE 100 = %d\n", cem);
    printf("NOTAS DE 50 = %d\n", cin);
    printf("NOTAS DE 10 = %d\n", dez);
    printf("MOEDAS DE 1 = %d\n", um);

    return 0;
}

