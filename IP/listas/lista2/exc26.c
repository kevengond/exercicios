#include <stdio.h>

//declaração de constantes paar a quantidade de anões e a soma dos números dos chapéus
enum {AN = 9, RES = 100};

//funções para a ordenação do vetor
void bubblesort(int anoes[], int quant);
void troca(int *p, int *q);

int main(void)
{
	//declaração de variáveis
	int quant, i, anoes[AN], j, k, cont, saida, nul1, nul2;
	
	//leitua da quantidade de testes
	scanf("%d", &quant);
	
	//leitura dos números ordenação e cálculos
	for (i = 0; i < quant; i++)
	{
		cont = 0;
		//leitura
		for (j = 0; j < AN; j++) scanf("%d", &anoes[j]);
		
		//chamada para a ordenação
		bubblesort(anoes, AN);	
		
		//cálculos	
		for (j = 0; j < AN; j++) cont += anoes[j]; 

		for (k = 0; k < AN; k++)
		{
			saida = cont;
			saida -= anoes[k];
			for (j = k + 1; j < AN; j++) 
			{
				if (saida - anoes[j] == 100)
				{
					nul1 = anoes[k];
					nul2 = anoes[j];
				}
			}
		}
		
		//saída
		for (j = 0; j < AN; j++)
		{
			if (anoes[j] != nul1 && anoes[j] != nul2) 
			{
				printf("%d\n", anoes[j]);
			}
		}

	}
	return 0;
}

//bubble sort para a ordenação
void bubblesort(int anoes[], int quant)
{
	int i, j;

	for (i = 1; i < quant; i++)
	{
		for (j = 0; j < quant - i; j++)
		{
			if (anoes[j] > anoes[j + 1]) troca(&anoes[j], &anoes[j + 1]);
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
