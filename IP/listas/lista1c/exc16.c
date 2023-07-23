#include <stdio.h>

// definição de uma constante com a quantidade mínima de matrículas
enum {QUANT = 100};

int main(void)
{
    // declaração de variáveis
    int matri[QUANT], aux_m, horas_t, i = 0, j = 0;
    double sal[QUANT], aux_s;

    // leitura
    scanf("%d %d %lf", &aux_m, &horas_t, &aux_s);

    // relaciona a matrícula com o seu salário
    while (aux_m != 0 && horas_t != 0 && aux_s != 0)
    {
        matri[i] = aux_m;
        sal[i] = horas_t * aux_s;

        i++;

        scanf("%d %d %lf", &aux_m, &horas_t, &aux_s);
    }
    // saída
    while(i--)
    {
        printf("%d %.2lf\n", matri[j], sal[j]);
        j++;
    }
}
