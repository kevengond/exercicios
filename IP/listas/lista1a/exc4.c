#include <stdio.h>

int main(void)
{
    double a, b, c;
   
    scanf("%lf %lf %lf", &a, &b, &c);

    printf("O VALOR DE DELTA E = %.2lf\n", (b * b) - (4 * a * c));

    return 0;
}

