#include <stdio.h>

int main(void)
{
    // declaração de variáveis
    unsigned tim, i, j, k = 1;
// leitura de times
    scanf("%u", &tim);
// quantidade inválida
    if (tim < 2)
    {
        printf("Campeonato invalido!\n");
    }
// saida dos jogos
    for (i = 1; i <= tim; i++)
    {
        for (j = i + 1; j <= tim; j++)
        {
            printf("Final %u: Time%u X Time%u\n", k, i, j);
            k++;
        }
    }

}