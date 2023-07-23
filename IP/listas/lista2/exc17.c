#include <stdio.h>

int main(void)
{
	//declaração de variáveis
	int quant, i, cont = 0, j;
	
	//leitura da quantidade de elementos do vetor
	scanf("%d", &quant);
	if (quant >= 5000 || quant <= 0) return 1;

	//declaração do vetor
	int vet[quant];

	//cálculo para a quantidade de elementos iguais
	for (i = 0; i < quant; i++) scanf("%d", &vet[i]);
	
	for (i = 0; i < quant; i++)
	{ 
		for (j = 0; j < quant; j++) 
		{
			if (vet[i] == vet[j] && i != j) cont++;
		}
	}
	
	//saída da quantidade de elementos únicos
	printf("%d\n", quant - cont);
}
