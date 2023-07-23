#include <stdio.h>

int main(void)
{
	//declaração de variáveis
	int i, quant, sum = 0;
	
	//leitura da quantidade de elementos do vetor
	scanf("%d", &quant);
	if (quant >= 5000) return 1;

	//declaração do vetor	
	int vet[quant];
	
	//leitura dos valores e soma
	for (i = 0; i < quant; i++) scanf("%d", &vet[i]);
	for (i = 0; i < quant; i++) sum += vet[i];
	
	//saída do resultado
	printf("%d\n", sum);
}


