#include <stdio.h>
#include <string.h>

//declaração de constantes para os valores da sena
enum {SENA = 6, QUINA = 5, QUADRA = 4};

//função para cálculo da quantidade de acertos  
int sena(int num[], int apt[]);

int main(void)
{
	//declaração de variáveis
	int num[SENA], i, quant, apt[SENA], j, rs, sen = 0, qui = 0, qua = 0;
	
	//leitura dos números da sena
	for (i = 0; i < SENA; i++) scanf("%d", &num[i]);
	
	//leitura da quantidade de apostas
	scanf("%d", &quant);
	if (quant < 1 || quant > 50000) return 1;
	
	//leitura das apostas e cálculo de acertos 
	for (i  = 0; i < quant; i++)
	{
		for (j = 0; j < SENA; j++) scanf("%d", &apt[j]);

		rs = sena(num, apt);

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


}

//função que retorna a quantidade de números iguais 
int sena(int num[], int apt[])
{
	int i, aux = 0, j;

	for (i = 0; i < SENA; i++)
	{
		for (j = 0; j < SENA; j++)
		{
			if (num[i] == apt[j]) aux++;
		}
	}
	return aux;
}

