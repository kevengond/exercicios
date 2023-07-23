#include <stdio.h>

#define PI 3.14159
#define M2 100

int main(void)
{
    double raio, altura;

    scanf("%lf %lf", &raio, &altura);

    printf("O VALOR DO CUSTO E = %.2lf\n", (2 * PI * raio * (altura + raio)) * M2);

    return 0;
}

