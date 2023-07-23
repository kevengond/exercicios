#include <stdio.h>

int main(void)
{
	//declaração de variáveis
	int quant, i;

	//leitura da quantidade de elementos do vetor e teste de validade	
	scanf("%d", &quant);
	if (quant > 5000) return 1;

	//declaração do vetor de números	
	int vet[quant];
	
	//leitura dos números do vetor
	for (i = 0; i < quant; i++) scanf("%d", &vet[i]);
	
	//saída
	for (i = 0; i < quant; i++) printf("%d ", vet[i]);
	printf("\n");

}	
