#include <stdio.h>

// função para a soma dos divisores
int divi(int num)
{
 int i, sum = 0;
 for (i = 1; i < num; i++)
        {
            if (num % i == 0)
            {
                sum += i;
            }
        }
    return sum;
}

// main
int main(void)
{
    // declaração das variáveis
    int quant, i, sum = 0, num = 220, res = 0, sum2 = 0;

    // leitura das variáveis e teste de númeor inválido
    scanf("%d", &quant);
    if (quant >= 9) return 1;

    // cálculos e saída
    while (quant > res)
    {
        sum = divi(num);
        sum2 = divi(sum);
        if (num == sum2 && num < sum)
        {
            printf("(%d,%d)\n", num, sum);
            res++;
        }
        num++;
    }
}

