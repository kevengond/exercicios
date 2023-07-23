#include <stdio.h>

int main(void)
{
	//declaração de variáveis
	int quant, i, maior, menor;

	//leitura do tamanho do vetor
	scanf("%d", &quant);
	if (quant < 1 || quant > 1000) return 1;

	//declaração do vetor
	int vet[quant];

	//leitura dos dados
	for (i = 0; i < quant; i++) scanf("%d", &vet[i]);

	//atribuição de valores auxiliares
	maior = vet[0];
	menor = vet[0];

	//saída do vetor 1
	for (i = 0; i < quant - 1; i++) printf("%d ", vet[i]);
	printf("%d\n", vet[i]);
	
	//saída do vetor 2	
	for (i = quant - 1; i >= 1; i--) printf("%d ",vet[i]);
	printf("%d\n", vet[i]);

	//procura dos valores 
	for (i = 0; i < quant; i++)
	{
		if (vet[i] > maior) maior = vet[i];
		if (vet[i] < menor) menor = vet[i];
	}

	//saída do maior e do menor valor
	printf("%d\n", maior);
	printf("%d\n", menor);

}

