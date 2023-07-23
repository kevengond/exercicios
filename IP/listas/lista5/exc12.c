#include <stdio.h>
#include <math.h>

//declaração de um tipo imóvel
typedef struct imv
{
    int moradores;
    double consumo;
    int cons_mor;
}imovel;

//funções para cálculos dos consumos das cidades e ordenação dos valores
void cons_cty(int quant, imovel im[]);
void bubble(int quant, imovel im[]);

int main(void)
{
    //declaração de variáveis
    int quant, i;

    //leitura da quantidade de imóveis
    scanf("%d", &quant);

    while(quant)
    {
        //declaração de um vetor de imóveis
        imovel im[quant];

        //leitura da quantidade de moradores e consumo por imóvel
        for (i = 0; i < quant; i++)
        {
            scanf("%d %lf", &im[i].moradores, &im[i].consumo);
        }

        //chamada da função para cálculo do consumo da cidade
        cons_cty(quant, im);

        //leitura novamente da quantidade de imóveis
        scanf("%d", &quant);
    }
}

//função que calculula o consumo da cidade
void cons_cty(int quant, imovel im[])
{
    //declaração de variáveis
    static int cidade = 1;
    int i, j,  cons_t = 0, pop_t = 0, aux, cont, pulo;

    //saída da cidade
    if (cidade > 1) printf("\n");
    printf("Cidade# %d:\n", cidade);

    //cálculo do consumo médio por moradia e somatoria da quantidade de moradores e  consumo da cidade
    for (i = 0; i < quant; i++)
    {
        im[i].cons_mor = (int) floor(im[i].consumo / im[i].moradores);
        cons_t += im[i].consumo;
        pop_t += im[i].moradores;
    }

    //ordenação dos valores
    bubble(quant, im);

    //cálulos do consumo médio por residência e saída
    for (i = 0; i < quant; i++)
    {
        pulo = 0;
        cont = 0;
        aux = 0;
        for (j = i; j < quant; j++)
        {
            if (im[i].cons_mor == im[j].cons_mor)
            {
                cont += im[j].moradores;
                aux = 1;
                pulo++;
            }
        }
        i += pulo - 1;
        if (aux) printf("%d-%d ", cont, im[i].cons_mor);
        if (!aux) printf("%d-%d ", im[i].moradores, im[i].cons_mor);
    }
    printf("\n");

    //saída do consumo médio da cidade
    printf("Consumo medio: %.2lf m3.\n", (double) cons_t / pop_t);
    cidade++;
}

//bubble sort para ordenar os valore do consumo
void bubble(int quant, imovel im[])
{
    int i, j;
    imovel aux;

    for (i = 1; i < quant; i++)
    {
        for (j = 0; j < quant - i; j++)
        {
            if (im[j].cons_mor > im[j+1].cons_mor)
            {
                aux = im[j];
                im[j] = im[j+1];
                im[j+1] = aux;
            }
        }
    }
}