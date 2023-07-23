#include <stdio.h>

int main(void)
{
	//declaração de variáveis
	int num_vet, num_test, j, num, i;

	//leitura do tamanho do vetor e teste de sua validade 
	scanf("%d", &num_vet);
	if (num_vet < 1 || num_vet > 100000) return 1;

	//declaração do vetor 
	int vet[num_vet];
	
	//leitura dos números do vetor
	for (j = 0; j < num_vet; j++)
	{
	       	scanf("%d", &vet[j]);
	}

	//leitura dos casos de teste e teste de sua validade
	scanf("%d", &num_test);
	if (num_test < 1 || num_test > 1000) return 2;

	//declaração de vetor que irá conter os resultados
	short int res[num_test];

	// pesquisa do númeor no vetor desordenado
	for (j = 0; j < num_test; j++)
	{
		res[j] = 0;
		scanf("%d", &num);
		for (i = 0; i < num_vet; i++)
		{
			if (num == vet[i]) 
			{
				res[j] = 1;	
			}
		}
	}

	//saída do resultado
	for (i = 0; i < num_test; i++)
	{
		if (res[i]) printf("ACHEI\n");
		else printf("NAO ACHEI\n");
	}


	return 0;
}

