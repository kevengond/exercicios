#include <stdio.h>

int main(void)
{
    int inteiro;

    scanf("%d", &inteiro);

    if (inteiro % 3 == 0 && inteiro % 5 == 0)
    {
        printf("O NUMERO E DIVISIVEL\n");
        return 0;
    }
    printf("O NUMERO NAO E DIVISIVEL\n");

    return 1;
}

