#include <stdio.h>
#include <math.h>

//declaração da struct para as coordenadas 
typedef struct pont
{
	double x;
	double y;
	double z;
}
pont;

//bubble sort para ordenar 
double bubble(double vt[], int q);

int main(void)
{
	//delcaração de variáveis
	int quant, i;
	double maior, res[3];

	//leitura da quantidade de elemntos do vetor e teste de validade  	
	scanf("%d", &quant);
	if (quant < 2 || quant > 1000) return 1;
	
	//delcaração de um vetor de pontos 
	pont ponto[quant];

	//leitura dos valores 
	for (i = 0; i < quant; i++) scanf("%lf %lf %lf", &ponto[i].x, &ponto[i].y, &ponto[i].z);

	//cálculos e saída 
	for (i = 0; i < quant - 1; i++)
	{
		res[0] = fabs(ponto[i + 1].x - ponto[i].x);
		res[1] = fabs(ponto[i + 1].y - ponto[i].y);
		res[2] = fabs(ponto[i + 1].z - ponto[i].z);

	
		maior = bubble(res, quant);

		printf("%.2lf\n", maior);
	}
}

//ordenação do maiores valors e rotorno do resultado 
double bubble(double vt[], int q)
{
	int i, j;
       	double aux;
	
	for (i = 1; i < q; i++)
	{
		for (j = 0; j < q - i; j++)
		{
			if (vt[j] < vt[j + 1])
			{
				aux = vt[j];
				vt[j] = vt[j + 1];
				vt[j + 1] = aux;
			}
		}
	}
	return vt[0];
}
				


