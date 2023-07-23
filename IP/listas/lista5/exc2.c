#include <stdio.h>
#include <string.h>

//constante com a quantidade máxima de caracteres permitida
enum {CCHAR = 51};

//struct de produdos
typedef struct prod
{
    char fru[CCHAR];
    double pre;
}fruta;

//função que calcula os gastos
void gastos(fruta prod[], int qprod);


int main(void)
{
    //declaração de variáveis
    int qtest, i, j, qprod;

    //leitura da quantidade de casos de teste
    scanf("%d", &qtest);

    for (i = 0; i < qtest; i++)
    {
        //leitura da quantidade de produtos e delcarção de um vetor de produtos
        scanf("%d", &qprod);
        fruta prod[qprod];
        getchar();

        //leitura dos produtos e seus respectivos valores
        for (j = 0; j < qprod; j++)
        {
            scanf("%[^' ']", prod[j].fru);
            scanf("%lf", &prod[j].pre);
            getchar();
        }

        //chamada da função para os gastos
        gastos(prod, qprod);
    }
}

//função que calcula os gastos
void gastos(fruta prod[], int qprod)
{
    //declaração de variáveis
    int i, j, compra, quantidade;
    double gast = 0;
    char cfru[CCHAR];

    //leitura da quantidade de produtos na compra
    scanf("%d", &compra);
    getchar();

    for (i = 0; i < compra; i++)
    {
        //leitura do produtos comprados e as quantidades
        scanf("%[^' ']", cfru);
        scanf("%d", &quantidade);
        getchar();

        //cálculo dos gastos
        for (j = 0; j < qprod; j++)
        {
            if (!strcmp(prod[j].fru, cfru))
            {
                gast += prod[j].pre * quantidade;
            }
        }
    }
    // saída
    printf("R$ %.2lf\n", gast);
}