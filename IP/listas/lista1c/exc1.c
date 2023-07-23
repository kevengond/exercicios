#include <stdio.h>

 // definir as constantes para os valores de cada lugar
#define POP 1
#define GERAL 5
#define ARQ 10
#define CAD 20

int main(void)
{
    //declaração de variáveis
    int publico, casos_test, i = 0, j;
    double pop, geral, arq, cad, aux = 0;

    //leitura de casos de teste
    scanf("%d", &casos_test);

    //declaração de um vetor que irá gurardar os valores em cada jogo
    double valor[casos_test];
    j = casos_test;

    //contas para cadda jogo
    while (casos_test--)
    {
        scanf("%d %lf %lf %lf %lf", &publico, &pop, &geral, &arq, &cad);

        aux += (publico * (pop / 100)) * POP;
        aux += (publico * (geral / 100)) * GERAL;
        aux += (publico * (arq / 100)) * ARQ;
        aux += (publico * (cad / 100)) * CAD;

        valor[i] = aux;


        i++;
        aux = 0;
    }

    //saída de valores
    for (i = 0; i < j; i++)
    {
        printf("A RENDA DO JOGO N. %d  E = %.2lf\n", i + 1, valor[i]);
    }

    return 0;
}
