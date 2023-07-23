#include <stdio.h>

//bubble sort 
void bubble(int *mat, int ord);

int main(void)
{
	//declaração de variaveis
	int ord, i, j;
	
	//leitura da ordem e teste de validade
	scanf("%d", &ord);
	if (ord  < 1 || ord > 1000) return 1;
	
	//declaração da matriz
	int mat[ord][ord];
	
	//leitura dos valores
	for (i = 0; i < ord; i++)
	{
		for (j = 0; j < ord; j++)
		{
			scanf("%d", &mat[j][i]);
		}

	}
	
	//saída	
	for (i = 0; i < ord; i++)
	{
		for (j = 0; j < ord; j++)
		{
			//chamada do bubble sort para ordenção dos valores
			bubble(mat[j], ord);
			printf("%d ", mat[j][i]);
		}
		printf("\n");
	}

}

//bubble sort para ordenar os valores da matriz
void bubble(int *mat, int ord)
{
	int i, j, aux;

	for (i = 1; i < ord; i++)
	{
		for (j = 0; j < ord - i; j++)
		{
			if (mat[j] > mat[j + 1])
			{
				aux = mat[j];
				mat[j] = mat[j + 1];
				mat[j + 1] = aux;
			}
		}
	}
}
