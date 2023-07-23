#include <stdio.h>

int main(void)
{
    // declaração de variáveis
    int  num, i, cont = 0;

    // leitura
    scanf("%u", &num);
    if (num < 0)
    // teste para ver se o número digitado é inválido
    {
        printf("Numero invalido!\n");
        return 1;
    }
    // encontrar a quantidade de divisores
    for (i = 1; i <= num; i++)
    {
        if (!(num % i)) cont++;
    }

    // saída
    if (cont == 2) printf("PRIMO\n");
    else printf("NAO PRIMO\n");
}
