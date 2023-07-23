#include <stdio.h>
#include <math.h>

int main(void)
{
    //declaração de variáveis
    int pop_a, pop_b, temp_anos = 1;

    //leitura dos dados
    scanf("%d %d", &pop_a, &pop_b);

    //operações
    while (pop_a < pop_b)
    {
        pop_a *= 1.03;
        pop_b *= 1.015;
        temp_anos++;
    }

    //saída
    printf("ANOS = %d\n", --temp_anos);

   return 0;
}
