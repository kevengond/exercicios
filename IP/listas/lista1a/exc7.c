#include <stdio.h>
#include <math.h>

int main(void)
{
    double lad1, lad2, lad3, t, area;

    scanf("%lf %lf %lf", &lad1, &lad2, &lad3);

    t = (lad1 + lad2 + lad3) / 2;
    area = sqrt(t * (t - lad1) * (t - lad2) * (t - lad3));

    printf("A AREA DO TRIANGULO E = %.2lf\n", area);

    return 0;
}

