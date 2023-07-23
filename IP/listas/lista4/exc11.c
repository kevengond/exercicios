#include <stdio.h>

//declaração de uma constante com a ordem máxima da matriz
#define OMAX 3

int main(void)
{
	//declaração de variávies
	int lin, col, i, j, wall;
	
	//leitura da quantidade de linhas e colunas
	scanf("%d %d", &lin, &col);
	if (lin < 3 || col < 3) return 1;
	
	//declaração do "mapa" 	
	int mat[lin][col];
	
	//leitura do "mapa"	
	for (i = 0; i < lin; i++)
	{
		for (j = 0; j < col; j++)
		{
			scanf("%d", &mat[i][j]);
		}
	}
	
	//cálculos e saída (OBS: Se tiver o gorro, a camisa listrada e a calça logo
	//temos então o Wally;	
	wall = 0;
	for (i = 0; i < lin; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (i <= lin - 3)
			{
				if (mat[i][j] == 4 && mat[i + 1][j] == 1111 && mat[i + 2][j] == 8)
				{
						printf("%d %d\n", i + 1, j);
						wall = 1;
				}
			}
			else if (i == lin - 2)
			{
				if (mat[i][j] == 4 && mat[i + 1][j] == 1111 && mat[0][j] == 8)
				{
					printf("%d %d\n", i + 1, j);
					wall = 1;
				}
			}
			else if (i == lin - 1)
			{
				if (mat[i][j] == 4 && mat[0][j] == 1111 && mat[1][j] == 8)
				{
					printf("%d %d\n", 0, j);
					wall = 1;
				}
			}
		}
	}
	if (!wall) printf("WALLY NAO ESTA NA MATRIZ\n");
}	
