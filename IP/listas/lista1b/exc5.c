#include <stdio.h>

int main(void)
{
    double valor;

    scanf("%lf", &valor);

    if (valor >= 9 && valor <= 10)
        printf("NOTA = %.1lf CONCEITO = A\n", valor);
    else if (valor >= 7.5 && valor < 9)
        printf("NOTA = %.1lf CONCEITO = B\n", valor);
    else if (valor >= 6 && valor < 7.5)
        printf("NOTA = %.1lf CONCEITO = C\n", valor);
    else    
        printf("NOTA = %.1lf CONCEITO = D\n", valor);

    return 0;
}

