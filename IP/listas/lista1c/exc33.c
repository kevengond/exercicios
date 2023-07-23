#include <stdio.h>

int main(void)
{
    // declaração das variáveis
    int i, rest, cont = 2, prim = 0;

    // leitura do número e teste para número inválido
    scanf("%d", &i);
    while (i <= 1)
    {
        printf("Fatoracao nao e possivel para o numero %d!\n", i);
        scanf("%d", &i);
    }

    // saída
    printf("%d = ", i);
    while (i != 1)
    {
        rest = i % cont;

        if (rest == 0)
        {
            if (prim) printf(" x ");
            else prim++;
            i /= cont;
            printf("%d", cont);
            cont--;
        }
        cont++;
    }
    printf("\n");

}
