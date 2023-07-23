#include <stdio.h>

enum {ORD = 6, LMAX = 4};

int main(void)
{
	//declaração de variávies e da matriz
	int i, j, mat[ORD][ORD], maior, aux;
	
	//leitura dos valores
	for (i = 0; i < ORD; i++)
	{
		for (j = 0; j < ORD; j++)
		{
			scanf("%d", &mat[i][j]);
		}
	}
	
	//cálculos e saída (obs: Os dígitos 0 importam)	
	maior = 0;
	for (i = 0; i < ORD - 2; i++)
	{
		for (j = 0; j < ORD - 2; j++)
		{
			aux = 0;
			aux = mat[i][j]+mat[i][j+1]+mat[i][j+2]+mat[i+1][j+1]+mat[i+2][j]+mat[i+2][j+1]+mat[i+2][j+2];
		if (aux > maior || maior == 0) maior = aux;
		}
	}
	printf("%d\n", maior);
}





