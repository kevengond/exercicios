#include <stdio.h>
#include <math.h>

//declaração de um tipo ponto
typedef struct pont
{
    double u;
    double x;
    double y;
    double z;
}ponto;

int main(void)
{
    //declaração de variáveis
    int quant, i, j;
    double dinst;
    
    //leitura da quantidade dos pontos
    scanf("%d", &quant);
    if (quant < 2 || quant > 1000) return 1;
    
    //declaração de um vetor de pontos
    ponto pts[quant];
    
    //leitura das coordenadas
    for (i = 0; i < quant; i++)
    {
        scanf("%lf %lf %lf %lf", &pts[i].u, &pts[i].x, &pts[i].y, &pts[i].z);
    }
    
    //saída da distância entre os pontos
    for (i = 0; i < quant - 1; i++)
    {
        printf("%.2lf\n", sqrt(pow(pts[i].u - pts[i+1].u , 2) + pow(pts[i].x - pts[i+1].x , 2) + pow(pts[i].y - pts[i+1].y , 2) + pow(pts[i].z - pts[i+1].z , 2)));
    }


}