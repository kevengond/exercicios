#include <stdio.h>

int main(void)
{
    // declaração de variáveis
    int num, i, sum = 0, cont = 0;
    // leitura do número e teste
    scanf("%d", &num);
    if (num < 0) return 1;
    // contador de divisores do número
    for (i = 1; i < num; i++) if (!(num % i)) cont++;
    // saída dos divisores
    printf("%d = ", num);
    for (i = 1; i < num; i++)
    {
        if (!(num % i))
        {
            printf("%d", i);
            sum += i;
            if (sum < num && --cont) printf(" + ");
        }
    }
    printf(" = %d", sum);
    // saída se é perfeito ou não
    if (sum == num) printf(" (NUMERO PERFEITO)\n");
    else printf(" (NUMERO NAO E PERFEITO)\n");

    return 0;
}