#include <stdio.h>

int main(void)
{
    int ano;

    scanf("%d", &ano);

    if ((ano % 4 == 0 && ano % 10 != 0) || ano % 400 == 0)
        printf("ANO BISSEXTO\n");
    else 
        printf("ANO NAO BISSEXTO\n");

    return 0;
}

