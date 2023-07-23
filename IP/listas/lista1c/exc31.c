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
    double num, n, i, res = 0;

    // leitura dos dados
    scanf("%lf %lf", &num, &n);

    // cálculos
    for (i = 0; i <= n; i++)
    {
        res += pow(num, i) / fac(i);
    }
    // saída
    printf("e^%.2lf = %.6lf\n", num, res);
}