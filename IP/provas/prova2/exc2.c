#include <stdio.h>
// definição das contantes para o crescimento da população
#define TAX_A 1.03
#define TAX_B 1.01

int main(void)
{
    // declaração das variáveis
    int popa = 0, popb = 0, temp = 1;

    // leitura da população
    scanf("%d %d", &popa, &popb);

    // cálculos
    while (popa < popb)
    {
        popa *= TAX_A;
        popb *= TAX_B;
        temp++;
    }

    // saída
    printf("ANOS = %d\n", --temp);
}



