#include <stdio.h>

int main(void)
{
    //declaração de variáveis
    int n1, n2, n3, r1, r2, r3, cont = 2, mmc = 1;
    // leitura de dados e retorno se for inválido
    scanf("%d %d %d", &n1, &n2, &n3);
    if(n1 == 0 || n2 == 0 || n3 == 0) return 1;
    // cálculos do mmc
    while (n1 != 1 || n2 != 1 || n3 != 1)
    {
        r1 = n1 % cont;
        r2 = n2 % cont;
        r3 = n3 % cont;

        if (r1 == 0 || r2 == 0 || r3 == 0)
        {
            printf("%d %d %d :%d\n", n1, n2, n3, cont);
            if (r1 == 0) n1 /= cont;
            if (r2 == 0) n2 /= cont;
            if (r3 == 0) n3 /= cont;

            mmc *= cont;
            cont--;
        }

        cont++;
    }
    // saída
    printf("MMC: %d\n", mmc);
}

