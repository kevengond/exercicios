#include <stdio.h>

//declaração de constantes para os valores da sena
enum {SENA = 6, QUINA = 5, QUADRA = 4};

//função para cálculo da quantidade de acertos  
int sena(int num[], int apt[]);

int main(void)
{
	//declaração de variáveis
	int quant, i, j, num[SENA], rs, sen = 0, qui = 0, qua = 0;
	
	//leitura da quantidade de apostas
	scanf("%d", &quant);
	if (quant < 1 || quant > 50000) return 1;
	
	//declaração da matriz que contêm as apostas
	int apost[quant][SENA];
	
	//leitura das apostas	
	for (i = 0; i < quant; i++)
	{
		for (j = 0; j < SENA; j++)
		{
			scanf("%d", &apost[i][j]);
		}
	}
	
	//leitura dos números sorteados
	for (i = 0; i < SENA; i++) scanf("%d", &num[i]);
	
	//cálculos
	for (i = 0; i < quant; i++)
	{
		//chamada para comparação
		rs = sena(num, apost[i]);

		if (rs == SENA) sen++;
		else if (rs == QUINA) qui++;
		else if (rs == QUADRA) qua++;
	}

	//saída
	if (sen) printf("Houve %d acertador(es) da sena\n", sen);
	else printf("Nao houve acertador para sena\n");

	if (qui) printf("Houve %d acertador(es) da quina\n", qui);
	else printf("Nao houve acertador para quina\n");

	if (qua) printf("Houve %d acertador(es) da quadra\n", qua);
	else printf("Nao houve acertador para quadra\n");

	return 0;
}

//função que retorna a quantidade de números iguais 
int sena(int num[], int *apt)
{
	//declaração de variáveis
	int i, aux = 0, j;
	
	//cálculos
	for (i = 0; i < SENA; i++)
	{
		for (j = 0; j < SENA; j++)
		{
			if (num[i] == apt[j]) aux++;
		}
	}
	//retorno da quantidade de números iguais
	return aux;
}


