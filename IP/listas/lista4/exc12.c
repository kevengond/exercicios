#include <stdio.h>

//constantes com as quantidades máximas e mínimas suportadas
#define EMAX 100
#define EMIN 1

int main(void)
{
	//declaração de variávies
	int esq, i, j, seg;
	
	//leitua da quantidade de quadras e teste de validade
	scanf("%d", &esq);
	if (esq < EMIN || esq > EMAX) return 1;
	
	//declaração da matriz com a posição das câmeras
	int mat[esq + 1][esq + 1];
	
	//leitura dos valores	
	for (i = 0; i < esq + 1; i++)
	{
		for (j = 0; j < esq + 1; j++)
		{
			scanf("%d", &mat[i][j]);
		}
	}
	
	//cálculos e saída dos valores
	for (i = 0; i < esq; i++)
	{
		for (j = 0; j < esq; j++)
		{
			seg = 0;
			if (mat[i][j]) seg++;
			if (mat[i + 1][j]) seg++;
			if (mat[i + 1][j + 1]) seg++;
			if (mat[i][j + 1]) seg++;
			if (seg >= 2) printf("S");
			else printf("U");
		}
		printf("\n");
	}
}

