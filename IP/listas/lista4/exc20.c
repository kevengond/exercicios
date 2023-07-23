#include <stdio.h>

//função para busca e troca dos elementos
void busc_troc(int lin, int col, int mat[lin][col]);

int main(void)
{
	//declaração de variáveis
	int lin, col, i, j;
	
	//leitura da quantidade de linhas e colunas
	scanf("%d %d", &lin, &col);
	if (lin < 1 || col < 1 || lin > 1000 || col > 1000) return 1;
	
	//declaração da matriz de valores	
	int mat[lin][col];
	
	//leitura dos valores
	for (i = 0; i < lin; i++)
	{
		for (j = 0; j < col; j++)
		{
			scanf("%d", &mat[i][j]);
		}
	}
	//chamada da função de busca
	busc_troc(lin, col, mat);

	return 0;
}

//função que busca o maior e o menor elemento e retorna a saída esperada
void busc_troc(int lin, int col, int mat[lin][col])
{
	//delcaração de variáveis
	int i, j, maior = mat[0][0], menor = mat[0][0], lM, cM, lm, cm, aux;
	
	//busca 	
	for (i = 0; i < lin; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (mat[i][j] >= maior) 
			{
				maior = mat[i][j];
				lM = i;
				cM = j;
			}
			if (mat[i][j] <= menor)
			{
				menor = mat[i][j];
				lm = i;
				cm = j;
			}
		}
	}
	
	//saída	
	for (i = 0; i < lin; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (i == lm && j == cm) printf("%d ", mat[lM][cM]);
			else if (i == lM && j == cM) printf("%d ", mat[lm][cm]);
			else printf("%d ", mat[i][j]);
		}
		printf("\n");
	}
}	

