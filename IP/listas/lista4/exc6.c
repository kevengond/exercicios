#include <stdio.h>

enum  {ORD = 2};

int main(void)
{
	//declaração de variávies
	int i, j, aux;
	//declaração das matrizes
	double mat[ORD][ORD], mat2[ORD][ORD];
	
	//leitura dos valores 
	for (i = 0; i < ORD; i++)
	{
		for (j = 0; j < ORD; j++)
		{
			scanf("%lf", &mat[i][j]);
		}
	}
	
	//cálculos e saída
	for (i = 0; i < ORD; i++)
	{
		aux = 0;
		for (j = 0; j < ORD; j++)
		{
			mat2[i][j] = (mat[i][aux] * mat[aux][j]) + (mat[i][aux + 1] * mat[aux + 1][j]);
			printf("%.3lf ", mat2[i][j]);
		}
		printf("\n");
	}
}

