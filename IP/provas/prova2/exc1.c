#include <stdio.h>

int main(void)
{
    // delcaração das variáveis
    int num1, num2, i;

    // leitura dos dois números
    scanf("%d %d", &num1, &num2);
    if (num1 % 2 == 0)
    {
        printf("PRIMEIRO NUMERO NAO E IMPAR\n");
        return 1;
    }

    // saída
    printf("%d ", num1);
    for (i = 1; i < num2; i ++)
    {
        num1 += 2;
        printf("%d ", num1);
    }
    printf("\n");
}