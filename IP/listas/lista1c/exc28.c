#include <stdio.h>
#include <math.h>
// númeor máximo para o expoente
#define BASMAX 100

//  função para descobrir o expoente da base 10 do denominador
 int desc_bas(double num);

// main
int main(void)
{
    // declaração de variáveis
    int nume, deno, i, bas;
    double num;

    // leitura do número
    scanf("%lf", &num);

    // chamada da função
    bas = desc_bas(num);

    //cálculos
    nume =  num * pow(10, bas);

    deno = pow(10, bas);

    for (i = 2; i < pow(10, bas); i++)
    {
        if (!(nume % i) && !(deno % i))
        {
            nume /= i;
            deno /= i;
            i--;
        }
    }
    // saída
    printf("%d/%d\n", nume, deno);
}
// função para descobrir o expoente da base 10 do denominador
int desc_bas(double num)
{
    int aux, i;

    for (i = 0; i <= BASMAX; i++)
    {
        aux = num * pow(10, i);
        if (aux == (num * pow(10, i))) break;
    }

    return i;
}