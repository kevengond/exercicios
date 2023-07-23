#include <stdio.h>
#include <math.h>

enum {DIG = 3}; //delcaração da quantidade de dígitos nos números

// funão que inverte os números
int inver(int *n)
{
    int i, aux = *n, aux2, aux3= 0;

    for (i = 0; i < DIG; i++)
    {
        aux2 = aux % 10;
        aux3 += aux2 * pow(10, DIG - 1 - i);
        aux /= 10;

    }
    return *n = aux3;
}

// fnção que faz a comparação dos número e coloca a saída
void comp_sai(int n1[], int n2[], int casos)
{
    int maior[casos], i;

    for (i = 0; i < casos; i++)
    {
        maior[i] = (inver(&n1[i]) > inver(&n2[i])) ? n1[i] : n2[i];
        printf("%d\n", maior[i]);
    }
}

    // entrada dos daos
int main(void)
{
    int cas_t, i;

    scanf("%d", &cas_t);

    int num1[cas_t], num2[cas_t];

    for (i = 0; i < cas_t; i++) scanf("%d %d", &num1[i], &num2[i]);

    comp_sai(num1, num2, cas_t);
}