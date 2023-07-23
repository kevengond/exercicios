#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// função de condição de existência de triangulo
int triangulo(int k, int i, int j)
{
    if (i + j > k && j + k > i && i + k > j)
    {
        if(abs(i - j) < k &&  abs(j - k) < i && abs(i - k) < j) return 1;
    }
    return 0;
}
// função da hipotenusa em função dos catetos de um triângulo retângulo
void hip(int num)
{
    int i, j, k;

   for (k = 1; k <= num; k++)
   {
        for (i = 1; i <= k; i++)
        {
            for (j = i + 1; j <= k; j++)
            {   int p = pow(i, 2) + pow(j, 2);
                if(triangulo(k, i, j) && pow(k, 2) == p)
                {
                    printf("hipotenusa = %d, catetos %d e %d\n", k, i, j);
                }
            }
        }

    }
}
// função base para leitura de um número (main)
int main(void)
{
    // declaração da variável
    int num;
    // leitura e teste da variável para ver se é válida
    scanf("%d", &num);
    if (num <= 0) return 1;
    //passagem da variável por valor par a função da hipotenusa
    hip(num);

    return 0;
}
