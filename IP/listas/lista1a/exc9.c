#include <stdio.h>
#include <math.h>

#define MS 3.6
#define TON 1000

int main(void)
{
    double mass_plane, ace, temp;

    scanf("%lf %lf %lf", &mass_plane, &ace, &temp);

    printf("VELOCIDADE = %.2lf\n", ace * temp * MS);
    printf("ESPACO PERCORRIDO = %.2lf\n", (ace * temp * temp) / 2);
    printf("TRABALHO REALIZADO = %.2lf\n", (pow((ace * temp), 2) * mass_plane * TON) / 2));

    return 0;
}
