#include <stdio.h>
#include <math.h>

// função fatorial
int fac(double num)
{
    if (num == 1 || num == 0) return 1;

    return num * fac(num - 1);
}

// main
int main(void)
{
    // declaração das variáveis
    double res = 0, cosen, n, i;

    // leitura de dados
    scanf("%lf %lf", &cosen, &n);
    // cálculos
    for (i = 0; i <= n; i++)
    {
        res += (pow(-1, i) * pow(cosen, 2 * i)) / fac(2 * i);
    }
    // saída
    printf("cos(%.2lf) = %.6lf\n", cosen, res);
}