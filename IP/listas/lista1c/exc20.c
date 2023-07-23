#include <stdio.h>

int main(void)
{
    // declaração de variáveis
    int lin, col, i, j, aux;

    // leitura de daddos
    scanf("%d %d", &lin, &col);

    // saida
    for (i = 1; i <= lin; i++)
    {
        int aux = 0;
        for (j = 1; j <= col; j++)
        {
            if (i > j && aux != 0)
            {
                printf("-");
            }
            if (i > j)
            {
                printf("(%d,%d)", i, j);
                aux++;
            }
        }
        if (aux) printf("\n");
    }
}
