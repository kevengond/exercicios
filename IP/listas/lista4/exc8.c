#include <stdio.h>
#include <string.h>

enum {MAX = 100};

int main(void)
{
	//declaração de variáveis
	int lin, col, i, j, tam_bord, bord;
	
	//leitura dos valores e teste de validade
	scanf("%d %d %d %d", &lin, &col, &tam_bord, &bord);
	if (lin > MAX || col > MAX) return 1;
	
	//declaração da matriz e adição de 0
	int mat[lin][col];
	memset(mat, 0, sizeof(mat));
	
	//saída padrão
	printf("P2\n");
	printf("%d %d\n", col, lin);
	printf("255\n");
	
	//cálculos e saída
	for (i = 0; i < lin; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (i < tam_bord || j < tam_bord || i >= lin - tam_bord || j >= col- tam_bord)
			{
				mat[i][j] = bord;
			}
			printf("%d ", mat[i][j]);
		}
		printf("\n");
	}
}
			
