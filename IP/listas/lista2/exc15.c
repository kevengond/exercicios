#include <stdio.h>
#include <stdlib.h>

//função de cálculo da distância
void dist(int vet[], int tam);

int main(void)
{
	//declaração de variáveis
	int test, tam, i, j;
	
	//leitura da quantidade de casos de testes
	scanf("%d", &test);
	if (test < 1 || test > 10) return 1;
	
	//leitura do tamanho e números do vetor
	for (i = 0; i < test; i++)
	{
		scanf("%d", &tam);
		if (tam < 2 || tam > 1000) return 2;

		int vet[tam];

		for (j = 0; j < tam; j++) scanf("%d", &vet[j]);
		
		//chamada da função
		dist(vet, tam);
	}
}

//cálculo da distância e saída 
void dist(int vet[], int tam)
{
	int i, j, aux, cont = 0;
	
	aux = abs(vet[0] - vet[1]);

	for (i = 0; i < tam; i++)
	{
		for (j = i + 1; j < tam; j++)
		{
			if (abs(vet[i] - vet[j]) < aux && i != j)	
			{
				aux = abs(vet[i] - vet[j]);
			}
			cont++;
		}
	}

	printf("%d %d\n", aux, cont);
}

