#include <stdio.h>

int main(void)
{
	//declaração de variávies
	int ord, i, j, k;
	
	//leitura da ordem e teste de validade
	scanf("%d", &ord);
	if (ord < 1 || ord > 1000) return 1;
	
	//declaração da variável e atribuição da ordem no auxiliar k
	int mat[ord][ord];
	k = ord;
	
	//leitura e saída
	for (i = 0; i < ord; i++)
	{
		for (j = 0; j < ord; j++)
		{
			scanf("%d", &mat[i][j]);
		}
		printf("%d\n", mat[i][k - 1]);
		k--;
	}
}

	
