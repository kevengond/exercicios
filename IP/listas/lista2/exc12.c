#include <stdio.h>

//bubble sort para ordenar os números 
void bubblesort(int vet[], int t);
void troca(int *p, int *q);

int main(void)
{
	//declaração de valores
	int quant, i;
	
	//leitura da quantidade de elementos lidos e teste de validade
	scanf("%d", &quant);
	if (quant <= 1 || quant > 1000) return 1;

	//declaração de vetor
	int vet[quant];

	// leitura dos valores
	for (i = 0; i < quant; i++) scanf("%d", &vet[i]);
	
	//ordenação
	bubblesort(vet, quant);
	
	//saída
	for (i = 0; i < quant; i++) printf("%d\n", vet[i]);
}

//bubble sort
void bubblesort(int vet[], int t)
{
	int j, k;

	for (j = 1; j < t; j++)
	{
		for (k = 0; k < t - j; k++)
		{
			if (vet[k] > vet[k + 1]) troca(&vet[k], &vet[k + 1]);
		}
	}
}

//troca de posição dos elementos
void troca(int *p, int *q)
{
	int aux = *p;
	*p = *q;
	*q = aux;
}

