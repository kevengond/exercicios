#include <stdio.h>
#include <math.h>

// declaração da estrutura ponto
typedef struct pont
{
	double x;
	double y;
	double z;
}
ponto;

int main(void)
{
	//declaração de variáveis
	ponto pont[3];
	int i, j, quant;
       	double	dist;
	
	//leitura da quantidade de pontos e teste de validade
	scanf("%d", &quant);
	if (quant < 2 || quant > 1000) return 1;
	
	//leitura dos pontos
	for (i = 0; i < quant; i++)
	{
		scanf("%lf %lf %lf", &pont[i].x, &pont[i].y, &pont[i].z);
	}

	// cálculo e saída das distâncias	
	j = quant - 1;
	for ( i = 0; i < j; i++)
	{
		dist = sqrt(pow(pont[i].x - pont[i + 1].x, 2) + pow(pont[i].y - pont[i + 1].y, 2) + pow(pont[i].z - pont[i + 1].z, 2));	
		printf("%.2lf\n", dist);
	}
}	

