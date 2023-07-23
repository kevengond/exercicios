#include <stdio.h>

int main(void)
{
    double prec_fab, dist, impost;

    scanf("%lf %lf %lf", &prec_fab, &dist, &impost);

    printf("O VALOR DO CARRO E = %.2lf\n", prec_fab * (1 + ((double)(dist + impost) / 100)));


    return 0;
}
