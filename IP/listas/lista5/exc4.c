#include <stdio.h>
#include <math.h>

//declaração de um tipo para as coordenadas dos pontos
typedef struct pont
{
    double u;
    double x;
    double y;
    double z;
    double norma;
} coord;

//função para a ordenação dos pontos
void bubble(coord pont[], int quant);

int main(void)
{
    //declaração de variáveis
    int quant, i, j;

    //leitura da quantidade de pontos lidos
    scanf("%d", &quant);
    if (quant < 2 || quant > 1000) return 1;

    //declaração de um vetor de coordenadas/pontos
    coord pont[quant];

    //leitura dos valores e cálculo da norma
    for (i = 0; i < quant; i++)
    {
       scanf("%lf %lf %lf %lf", &pont[i].u, &pont[i].x, &pont[i].y, &pont[i].z);

       pont[i].norma = sqrt(pow(pont[i].u,2) + pow(pont[i].x,2) + pow(pont[i].y,2) + pow(pont[i].z,2));
    }

    //chamada da função para ordenação por bubble sort
    bubble(pont, quant);

    //saída dos valores
    for (i = 0; i < quant; i++)
    {
        printf("Vetor: (%.2lf, %.2lf, %.2lf, %.2lf) Norma: %.2lf\n", pont[i].u, pont[i].x, pont[i].y, pont[i].z, pont[i].norma);
    }
}

//bubble sort para ordenar os valores para a saída
void bubble(coord pont[], int quant)
{
    int i, j;
    coord aux;

    for(i = 1; i < quant; i++)
    {
        for (j = 0; j < quant - i; j++)
        {
            //coloquei a torca dentro da função mesmo
           if (pont[j].norma > pont[j+1].norma)
           {
               aux = pont[j];
               pont[j] = pont[j+1];
               pont[j+1] = aux;
           }
        }
    }
}