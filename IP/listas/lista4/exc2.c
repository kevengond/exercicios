#include <stdio.h>

int main(void)
{
	//declaração de variáveis
	int ord, i, j;
	
	//leitura da ordem e teste de validade
	scanf("%d", &ord);
	if (ord <= 1 || ord > 1000) return 1;
	
	//delcaração da matriz quadrada
	int mat[ord][ord];
	
	//leitura e saída da diagonal principal
	for (i = 0; i < ord; i++)
	{
		for (j = 0; j < ord; j++)
		{
			scanf("%d", &mat[i][j]);
			if (i == j) printf("%d\n", mat[i][j]);
		}
	}
}
