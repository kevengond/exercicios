#include <stdio.h>

//funções para o encontro do maior e menor número e cálculo da frequência
void maior(int lin, int col, int mat[lin][col]);
void menor(int lin, int col, int mat[lin][col]);
void freq(int lin, int col, int num, int mat[lin][col]);

int main(void)
{
	//declaração de variáveis
	int lin, col, i, j;
	
	//leiutra da quantidade de linhas e colunas na matriz
	scanf("%d %d", &lin, &col);
	if (lin <= 1 || col <= 1 || lin > 1000 || col > 1000) return 1;
	
	//declaração da matriz
	int mat[lin][col];
	
	//leitura dos valores na matriz
	for (i = 0; i < lin; i++)
	{
		for (j = 0; j < col; j++)
		{
			scanf("%d", &mat[i][j]);
		}
	}
	
	//chamada das funções
	menor(lin, col, mat);
	maior(lin, col, mat);
}

//função para o encontro do menor número
void menor(int lin, int col, int mat[lin][col])
{
	//declaração de variáveis
	int i, j, aux = mat[0][0];
	
	//encontro do menor número
	for (i = 0; i < lin; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (aux > mat[i][j]) aux = mat[i][j];
		}
	}
	//saída
	printf("%d ", aux);
	
	//chamada para a frequência do menor número
	freq(lin, col, aux, mat);
}

//função para o encontro do maior número
void maior(int lin, int col, int mat[lin][col])
{
	//declaração de variáveis
	int i, j, aux = mat[0][0];
	
	//encontro do menor número
	for (i = 0; i < lin; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (aux < mat[i][j]) aux = mat[i][j];
		}
	}
	//saída
	printf("%d ", aux);
	
	//chamada para a frequência do menor número
	freq(lin, col, aux, mat);
}

//função para a frequência dos números passados
void freq(int lin, int col, int num, int mat[lin][col])
{
	//declaração de variáveis
	int i, j, cont = 0;
	
	//cálculo da frequência 
	for (i = 0; i < lin; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (mat[i][j] == num) cont++;
		}
	}
	//saída
	printf("%.2lf%%\n", ((double)cont / (lin * col)) * 100);
}
