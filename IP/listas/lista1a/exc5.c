#include <stdio.h>
#include <math.h>

int main(void)
{
    double altura, aresta;

    scanf("%lf %lf", &altura, &aresta);

    printf("O VOLUME DA PIRAMIDE E = %.2lf METROS CUBICOS\n", (1.5 * pow(aresta, 2) * sqrt(3) * altura) / 3);

    return 0;
}

