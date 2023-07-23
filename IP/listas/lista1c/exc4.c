#include <stdio.h>

int main(void)
{
    //declaração de variáveis
    int x, y, i;

    // leitura dos dois valores de entrada
    scanf("%d %d", &x, &y);

    //teste para ver se o primeiro númeor é par
    if (!(x % 2))
    {
        //saída dos valores caso seja
        for (i = 0; i < y; i++)
        {
            printf("%d ", x);
            x += 2;
        }
        printf("\n");
    }
    else //saída de "erro" caso não seja par
    {
        printf("O PRIMEIRO NUMERO NAO E PAR\n");
    }

    return 0;
}
