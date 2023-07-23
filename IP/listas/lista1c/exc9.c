#include <stdio.h>

//recursividade para fazer o fatorial
int fact(int num)
{
    if (num == 1 || num == 0)
    {
        return 1;
    }

    return num * fact(num - 1);
}

//função principal
int main(void)
{
    //declaração da variável
    int num;

    //leitura do número
    scanf("%d", &num);
    //saída
    printf("%d! = %d\n", num, fact(num));

    return 0;
}
