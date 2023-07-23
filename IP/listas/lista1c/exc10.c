#include <stdio.h>

//funçao para apresentar a soma
void soma(double num, double ini, double quant, double inc)
{
    int i;

    printf("Tabuada de soma:\n");

    for (i = 0; i < quant; i++)
    {
        printf("%.2lf + %.2lf = %.2lf\n", num, ini + (inc * i), num + (ini + (inc * i)));
    }
}
//funçao para paresentar a subtração
void subt(double num, double ini, double quant, double inc)
{
    int i;

    printf("Tabuada de subtracao:\n");

    for (i = 0; i < quant; i++)
    {
         printf("%.2lf - %.2lf = %.2lf\n", num, ini + (inc * i), num - (ini + (inc * i)));
    }
}
//funçaõ para apresentar a multiplicação
void mult(double num, double ini, double quant, double inc)
{
    int i;

    printf("Tabuada de multiplicacao:\n");

    for (i = 0; i < quant; i++)
    {
         printf("%.2lf x %.2lf = %.2lf\n", num, ini + (inc * i), num * (ini + (inc * i)));
    }
}
//funçao para apresentar a divisão
void divs(double num, double ini, double quant, double inc)
{
    int i;

    printf("Tabuada de divisao:\n");

    for (i = 0; i < quant; i++)
    {
         printf("%.2lf / %.2lf = %.2lf\n", num, ini + (inc * i), num / (ini + (inc * i)));
    }
}
//main
int main(void)
{
    //delcaração das variáveis
    double num, ini, quant, inc;

    //leitura
    scanf("%lf %lf %lf %lf", &num, &ini, &quant, &inc);
    //chamada das funções
    soma(num, ini, quant, inc);
    subt(num, ini, quant, inc);
    mult(num, ini, quant, inc);
    divs(num, ini, quant, inc);

    return 0;
}