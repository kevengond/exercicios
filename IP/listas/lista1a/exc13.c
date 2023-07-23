#include <stdio.h>

int main(void)
{
    double a, b, c, d, e, f;

    scanf("%lf %lf %lf %lf %lf %lf", &a, &b, &c, &d, &e, &f);

    printf("O VALOR DE X E = %.2lf\n", ((b * f) - (c * e)) / ((b * d) - (a * e)));
    printf("O VALOR DE Y E = %.2lf\n", ((f * a) - (c * d)) / ((e * a) - (b * d)));

    return 0;
}

