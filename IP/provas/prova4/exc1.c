#include <stdio.h>

int main(void)
{
	//declaração de variáveis
	int lin, col, i, j;
	
	//leitura da quantidade de linhas e colunas com teste de validade
	scanf("%d %d", &lin, &col);
	if (lin > 100 || col > 100) return 1;
	
	//declaração da matriz	
	int mat[lin][col];
	
	//leituar dos valores
	for (i = 0; i < lin; i++)
	{
		for (j = 0; j < col; j++)
		{
			scanf("%d", &mat[i][j]);
		}
	}

	//saída	
	for (j = 0; j < col; j++)
	{
		for (i = 0; i < lin; i++)
		{
			printf("%d ", mat[i][j]);
		}
		printf("\n");
	}
}
