#include <stdio.h>

#define TRE 0.5
#define STRE 0.3

int main(void)
{
    double sal;

    scanf("%lf", &sal);

    if (sal <= 300)
        printf("SALARIO COM REAJUSTE = %.2lf\n", sal * (1 + TRE));
    else
        printf("SALARIO COM REAJUSTE = %.2lf\n", sal * (1 + STRE));

    return 0;
}

