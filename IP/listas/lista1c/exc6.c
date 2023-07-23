#include <stdio.h>

int main(void)
{
    //declaração de variáveis
    int n, i;
    double soma = 0;

    //leitura do dado
    scanf("%d", &n);

    //return 1 caso o numero seja menor ou igual a 1
    if (n <= 1)
    {
        printf("Numero invalido!\n");
        return 1;
    }

    //cálculo da somatória
    for (i = 1; i <= n; i++)
    {
        soma += (float) 1 / i;
    }

    //saída do dado
    printf("%.6lf\n", soma);

    return 0;
}
