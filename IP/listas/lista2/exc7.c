#include <stdio.h>

enum {CASOS = 100};

int main(void)
{
	//declaração de variáveis
	int quant, i, mr, j, sum;
	
	//leitura da quantidade de elementos no vetor e teste de validade
	scanf("%d", &quant);
	if (quant <= 1 || quant > 10000) return 1;
	
	//leitura dos elementos e saída enquanto a quantidade for diferente de 0
	while (quant != 0)
	{
		mr = 0;

		int vet[quant];

		for (i = 0; i < quant; i++) 
		{
			scanf("%d", &vet[i]);
			if (vet[i] > mr) mr = vet[i];
		}

		for (i = 0; i <= mr; i++)
		{
			sum = 0;
			for (j = 0; j < quant; j++) 
			{
				if (vet[j] <= i) sum++;
			}
			printf("(%d) %d\n", i, sum);
		}

		scanf("%d", &quant);
	}
}
