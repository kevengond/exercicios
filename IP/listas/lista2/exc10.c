#include <stdio.h>

//funções para descobrir a frequência e o maior número
void freq(int vet[], int i);
void maior(int vet[], int i);

int main(void)
{
	//declaração de variáveis
	int quant, i;
	
	//leitura da quantidade de elementos e teste de validade
	scanf("%d", &quant);
	if (quant < 1 || quant > 10000) return 1;
	
	//declaração do vetor
	int vet[quant];
	
	//leitura dos números 
	for (i = 0; i < quant; i++) scanf("%d", &vet[i]);
	
	//chamada das funções
	freq(vet, quant);
	maior(vet, quant);
}

//saída da frequência do último elemento
void freq(int vet[], int i)
{
	int num = vet[i - 1], j, cont = 0;

	for (j = 0; j < i; j++)
	{
		if (vet[j] == num) cont++;
	}

	printf("Nota %d, %d vezes\n", num, cont);
}

//saída do maior elemento e seu índice
void maior(int vet[], int i)
{
	int maior = vet[0], j, idx;

	for (j = 1; j < i; j++) 
	{
		if (vet[j] > maior) 
		{
			maior = vet[j];
			idx = j;
		}
	}

	printf("Nota %d, indice %d\n", maior, idx);
}

