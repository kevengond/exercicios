#include <stdio.h>

int main(void)
{
	// declaração das variáveis
	int quant, i;
	
	//leitura da quantidade de elementos do vetor
	scanf("%d", &quant);
	if (quant > 5000) return 1;

	//decaração do vetor
	int vet[quant];
	
	//leitura dos números
	for (i = 0; i < quant; i++) scanf("%d", &vet[i]);
	
	//saída dos números
	for (i = quant - 1; i >= 0; i--) printf("%d ", vet[i]);
	printf("\n");
}

