#include <stdio.h>

int main(void)
{
    // declaração de variáveis
    int n, i, cont = 0, ant;

    scanf("%d", &n);

    // caso n seja menor que o pedido return 1
    if (n <= 0) return 1;
    // declaração de um array de números
    int num[n];

    // comparações dos número da posição do array 0 até n - 1, já que pega de 2 em 2
    for (i = 0; i < n; i++)
    {
        scanf("%d", &num[i]);
    }

    for (i = 0; i < n - 1; i++)
    {
        if (num[i] < num[i + 1])
        {
            cont++;
        }
        else
        {
            if (cont > ant) ant = cont; // isso é importante, já que deve ser a maior cadeia
            cont = 0;
        }
    }
    //caso o contador no final de 0, o valor de ant passa para o contador
    if (cont == 0 && ant != 0) cont = ant;
    // saída
    printf("O comprimento do segmento crescente maximo e: %d\n", cont);

    return 0;
}