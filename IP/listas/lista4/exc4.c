#include <stdio.h>

enum {DMAX = 10};

int main(void)
{
	//declaração de variávies
	int lin, col, i, j;
	
	//leitura da quantidade de linhas
	do
	{
		scanf("%d", &lin);
	}
       	while (lin < 1 || lin > 10);
	//leitura da quantidade de colunas
	do
	{
		scanf("%d", &col);
	}
	while (col < 1 || col > 10);
	
	//declaração da matriz
	int mat[lin][col];
	
	//leitura dos valores e saída
	for (i = 0; i < lin; i++)
	{
		printf("linha %d: ", i + 1);

		for (j = 0; j < col; j++)
		{
			scanf("%d", &mat[i][j]);
			printf("%d", mat[i][j]);
			if (j < col - 1) printf(",");
		}
		printf("\n");
	}
}


