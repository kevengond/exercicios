#include <stdio.h>

//quantidade máxima de resultados
enum { CASOS = 100};

int main(void)
{
	//declaração de variáveis
	int quant, res[CASOS][2], i, idx, j = 0;
	
	//leitura da quantidade do vetor e teste de validade
	scanf("%d", &quant);
	if (quant <= 1 || quant > 10000) return 1;
	
	//leitura dos números enquanto o tamanho do vetor não for 0
		
	while (quant != 0)
	{
		int vet[quant];
		idx = 0;

		for (i = 0; i < quant; i++) scanf("%d", &vet[i]);

		for (i = 0; i < quant; i++) if (vet[i] > vet[idx]) idx = i;

		res[j][0] = idx;
		res[j][1] = vet[idx];
		j++;

		scanf("%d", &quant);
	}
	
	//saída
	for (i = 0; i < j; i++) printf("%d %d\n", res[i][0], res[i][1]);
}
