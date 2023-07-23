#include <stdio.h>

//constante com a ordem máxima permitida
#define DMAX 10
	
//função para a impressão em espiral
void esp(int lin, int col, int mat[lin][col]);

int main(void)
{
	//declaração de variáveis
	int lin, col, i, j, ida, vol, desc, sub, aux, k;
	
	//leitura da quantidade de linhas e colunas e teste de validade
	scanf("%d %d", &lin, &col);
	if (lin < 1 || col < 1 || lin > 10 || col > 10)
	{
		printf("Dimensao invalida\n");
		return 1;
	}
	
	//declaração da matriz	
	int mat[lin][col];
	
	//leitura dos dados
	for (i = 0; i < lin; i++)
	{
		for (j = 0; j < col; j++)
		{
			scanf("%d", &mat[i][j]);
		}
	}
	
	//chamada para a função	
	esp(lin, col, mat);
}
	
//Impressão dos valores da matriz em espiral
void esp(int lin, int col, int mat[lin][col])
{
	//declaração de variáveis
	int i, j, aux = lin * col;
	int sup = 0, inf = lin, dir = col, esq = 0;
	
	//enquanto não chegar na quantidade de caracteres da matriz	
	while (aux)
	{  
	   if (aux)
	   {
		//direita
		for (i = esq; i < dir; i++)
		{
			printf("%d ", mat[sup][i]);
			aux--;
		}
		sup++;
	   }

	   if (aux)
	   {	   
		// descida
		for (i = sup; i < inf; i++)
		{
			printf("%d ", mat[i][dir - 1]);
			aux--;
		}
		dir--;
	   }

	   if (aux)
	   {	   
		//esquerda
		for (i = dir - 1; i >= esq; i--)
		{
			printf("%d ", mat[inf - 1][i]);
			aux--;
		}
		inf--;
	   }

	   if (aux)
	   {
		//subida
		for (i = inf - 1; i >= sup; i--)
		{
			printf("%d ", mat[i][esq]);
			aux--;
		}
		esq++;
	   }
	}
	printf("\n");
}
