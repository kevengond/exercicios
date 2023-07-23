#include <stdio.h>

int main(void)
{
    double fah, pol;

    scanf("%lf %lf", &fah, &pol);

    printf("O VALOR EM CELSIUS = %.2lf\n",   (double) 5 / 9 * (fah - 32));
    printf("A QUANTIDADE DE CHUVA E = %.2lf\n", pol * 25.4);

    return 0;
}

