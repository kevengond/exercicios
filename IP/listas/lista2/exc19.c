#include <stdio.h>

int main(void)
{
	//declaração de variáveis
	int quant, i, aux;
	
	//leitura da quantidade de valores e teste de validade
	scanf("%d", &quant);
	if (quant < 1 || quant > 1000) return 1;
	
	//declaração do vetor que irá armazenar os valores
	int vet[quant];

	//leitura dos valores
	for (i = 0; i < quant; i++) scanf("%d", &vet[i]);

	//saída	
	aux = vet[0];
	for (i = 0; i < quant; i++)
	{
		if (vet[i] > aux)
		{
			printf("%d\n", aux);
			aux = vet[i];
		}
	}
	printf("%d\n", aux);
}	

