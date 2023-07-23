#include <stdio.h>
#include <string.h>

//função que ordena os valores de acordo com o índice
void idx(int vet_idx[], int vet[], int quant, int maior);

int main(void)
{
	//declaração de variáveis
	int quant, i, maior;
	
	//leitura da quantidade de valores
	scanf("%d", &quant);
	if (quant <= 1 || quant > 10000) return 1;
	
	//ordenação e leitura enquanto a quantidade for diferente de 0
	while (quant != 0)
	{
		//delcaração do vetor de valores
		int vet[quant];
	
		//descoberta do maior número e leitura
		maior = 0;
		for (i = 0; i < quant; i++)
		{
			scanf("%d", &vet[i]);
			if (vet[i] > maior) maior = vet[i];
		}
		
		//declaração de uma variável auxiliar para os índices	
		int vet_idx[maior + 1];
		memset(vet_idx, 0, sizeof(vet_idx));
	
		//chamada da função para ordenação em função dos índices	
		idx(vet_idx, vet, quant, maior);	
		
		//leitura novamente das quantidades
		scanf("%d", &quant);
	}
}

void idx(int vet_idx[], int vet[], int quant, int maior)
{
	int i, j;
	
	for (i = 0; i < quant; i++) vet_idx[vet[i]]++;
	
	for (i = 0; i < maior; i++) 
	{
		vet_idx[i + 1] += vet_idx[i];
	}

	int res[quant];

	for (i = 0; i < quant; i++)
	{
		res[vet_idx[vet[i]] - 1] = vet[i];
		vet_idx[vet[i]]--;
	}
	
		for (i = 0; i < quant; i++) printf("%d ", res[i]);
	printf("\n");
}



