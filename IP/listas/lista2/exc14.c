#include <stdio.h>
#include <math.h>

//bubble sort para ordenação
void bubble(int vet[], int quant);
void troca(int *p, int *q);

int main(void)
{
	//declaração de variáveis
	int quant, i, meio;

	//leitura da quantidade de elementos do vetor e teste de validade
	scanf("%d", &quant);
	if (quant <= 0 || quant > 1000000) return 1;
	
	//declaração do vetor
	int vet[quant];
	
	//leitura dos números
	for (i = 0; i < quant; i++) scanf("%d", &vet[i]);

	//bubble sort 
	bubble(vet, quant);

	//saída
	if (quant % 2)
	{
		meio = (int) ceil(quant / 2.0) - 1;
		printf("%.2lf\n", (double) vet[meio]);
	}
	else
	{
		meio = (quant / 2) - 1;
		printf("%.2lf\n", (double) (vet[meio] + vet[meio + 1]) / 2);
	}
}

//bubble sort para ordenar
void bubble(int vet[], int qt)
{
	int i, j;

	for (i = 1; i < qt; i++)
	{
		for (j = 0; j < qt - i; j++)
		{
			if (vet[j] > vet[j + 1]) troca(&vet[j], &vet[j + 1]);
		}
	}
}

//troca de valores
void troca(int *p, int *q)
{
	int aux = *p;
	*p = *q;
	*q = aux;
}

