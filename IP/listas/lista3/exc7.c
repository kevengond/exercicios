#include <stdio.h>
#include <string.h>
#include <stdlib.h>

enum {QMAX = 500};

//função para a limpeza do dado
void clear(char str[]);

int main(void)
{
	//declaração de variávies
	int quant, i, byt;
	
	//leitura da quantidade de casos lidos e teste de validade
	scanf("%d", &quant);
	if (quant < 1 || quant > 20) exit(1);
	
	//enquanto não chegar na quantidade
	for (i = 0; i < quant; i++)
	{
		//leitura da quantidade de letras que serão lidas / mostradas
		scanf("%d", &byt);
		getchar();
		
		//alocação da quantidade de memória necessária
		char *str = (char *) malloc(byt + 1);
		if (str == NULL) exit(1);
	
		//leitura e limpeza dos dados
		fgets(str, byt + 1, stdin);
		clear(str);
	
		//saída
		printf("%s\n", str);
		
		//liberação da memória alocada
		free(str);
	}
}

//limpeza dos dados 
void clear(char str[])
{
	//descomberta do tamanho da string
	int c = strlen(str);
	//caso tenha pego o \n, faz a sua limpeza
	if (str[c - 1] == '\n') str[c - 1] = 0;
	else //caso contrário, limpa-se o buffer até encontrar o \n
	{
		while (getchar() != '\n');
	}
} 
