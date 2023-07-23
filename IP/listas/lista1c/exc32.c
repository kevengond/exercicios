#include <stdio.h>
#include <math.h>

// função fatorial
long int fac(double num)
{
    if (num == 1 || num == 0) return 1;

    return num * fac(num - 1);
}

// main
int main(void)
{
    // declaração das variáveis
    double res = 0, sen, n, i;

    // leitura de dados
    scanf("%lf %lf", &sen, &n);
    // cálculos
    for (i = 0; i <= n; i++)
    {
        res += (pow(-1, i) * pow(sen, (2 * i )+ 1)) / fac((2 * i) + 1);
    }
    // saída
    printf("seno(%.2lf) = %.6lf\n", sen, res);
}