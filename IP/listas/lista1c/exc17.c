#include <stdio.h>
#include <math.h>

#define r0 1

int main(void)
{
    // declaração de valores
    double rk, e, e_calc, num;

    // leitura de dados
    scanf("%lf %lf", &num, &e);

    // cálculos iniciais e saída inicial
    rk = (r0 + (num / r0)) / 2;
    e_calc = fabs(num - pow(rk, 2));
    printf("r: %.9lf, erro: %.9lf\n", rk, e_calc);

    // restante dos cálculos e saída
    while (e_calc > e)
    {
        rk = (rk + (num / rk)) / 2;
        e_calc = fabs(num - pow(rk, 2));
        printf("r: %.9lf, erro: %.9lf\n", rk, e_calc);
    }
}