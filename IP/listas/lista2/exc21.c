#include <stdio.h>

//funções para a ordenação do vetor
void bubble(unsigned vt[], unsigned qt);
void troca(unsigned *p, unsigned *q);

int main(void)
{
	//declaração de variáveis
	unsigned quant, i, j;
	
	//leitura da quantidade de elementos 
	scanf("%u", &quant);
	if (quant < 1 || quant > 100000) return 1;

	//declaração do vetor
	unsigned vet[quant];

	//leitura dos valores
	for (i = 0; i < quant; i++) scanf("%u", &vet[i]);

	//chamada para bubble sort	
	bubble(vet, quant);

	//saída dos valoers pares
	for (i = 0; i < quant; i++) 
	{
		if (!(vet[i] % 2)) printf("%u\n", vet[i]);
	}

	//chamada para bubble sort novamente
	bubble(vet, quant);

	//saída dos valoers ímpares	
	for (i = 0; i < quant; i++)
	{
		if (vet[i] % 2) printf("%u\n", vet[i]);
	}
}

//troca de valores
void troca(unsigned *p, unsigned *q)
{
	unsigned aux = *p;
	*p = *q;
	*q = aux;
}

//bubble sort com duas implementações: 1- para pares | 2- para ímpares
void bubble(unsigned vt[], unsigned qt)
{
	static int k = 0;
	int i, j;
	unsigned aux;
	
	for (i = 1; i < qt; i++)
	{
		for (j = 0; j < qt - 1; j++)
		{
			if (vt[j] > vt[j + 1] && k == 0)
			{
				troca(&vt[j], &vt[j + 1]);	
			}
			if (vt[j] < vt[j + 1] && k == 1)
			{
				troca(&vt[j], &vt[j + 1]);
			}	
		}
	}
	k++;
}

