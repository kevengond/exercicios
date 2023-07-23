#include <stdio.h>

//*** TESTE***** delclaração de uma constante com uma quantidade máxima de respostas
enum {QUANT = 100};

int main(void)
{
    // declaração de variáveis
    double ant, num;
    int casos, i, cont = 0, res[QUANT], j = 0, aux;

    //leitura de casos inicial
    scanf("%d", &casos);
    if (casos == 0) return 1;

    //loop para os casos e confirmação se está em ordem crescente
    while (casos)
    {
        scanf("%lf", &num);
        ant = num;

        for (i = 0; i < casos - 1; i++)
        {
            scanf("%lf", &num);
            if (num <= ant) cont++;
            ant = num;
        }

        if (cont) res[j] = 0;
        else res[j] = 1;
        j++;
        cont = 0;

        scanf("%d", &casos);
    }

    //saída
    for (i = 0; i < j; i++)
    {
        if (!res[i]) printf("DESORDENADA\n");
        else printf("ORDENADA\n");
    }

    return 0;
}