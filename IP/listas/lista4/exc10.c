#include <stdio.h>

//constante com a dimensão máxima da matriz
enum {DMAX = 1000};

int main(void)
{
	//declaração de variávies
	int dim, i, j, tr = 0;
	
	//leitura da dimensão e teste de validade	
	scanf("%d", &dim);
	if (dim <= 1 || dim >= DMAX) return 1;
	
	//declaração das matrizes
	int mat[dim][dim], mat1[dim][dim];
	
	//leitura dos valores e cálculo do traço
	for (i = 0; i < dim; i++)
	{
		for (j = 0; j < dim; j++)
		{
			scanf("%d", &mat[i][j]);
			mat1[j][i] = mat[i][j];
			if (i == j) tr += mat[i][j];
		}
	}
	//cálculos finais e saída
	for (i = 0; i < dim; i++)
	{
		for (j = 0; j < dim; j++)
		{
			mat[i][j] *= tr;
			printf("%d ", mat1[i][j] + mat[i][j]);
		}
		printf("\n");
	}
}
