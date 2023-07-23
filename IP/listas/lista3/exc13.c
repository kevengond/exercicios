#include <stdio.h>
#include <string.h>

//constante com a quantidade máxima de caracteres
enum {QMAX = 10001};

//funções para a limpeza e operações
void clear(char str[]);
void opera(char str1[], char str2[]);

int main(void)
{
	//declaração de variáveis
	int quant, j, i, tam; 
	char str[QMAX];
	
	//leitura da quantidade de casos e teste de validade
	scanf("%d", &quant);
	if (quant > 100) return 1;
	getchar();
	
	for (i = 0; i < quant; i++)
	{
		//leitura da string e limpeza do \n
		fgets(str, QMAX, stdin);
		clear(str);
		
		//cálculo para o tamanho da string
		for (j = 0; str[j] != ' '; j++);
		tam = j;
		
		//declaração de duas stirng auxiliares
		char aux1[tam + 1], aux2[tam + 1];
		
		//separação das strings (uma sendo a base e a outra a string a ser obtida)
		for (j = 0; j < tam; j++)
		{
			aux1[j] = str[j];
			aux2[j] = str[tam + 1 + j];
		}
		//adição do caractere nulo
		aux1[tam] = aux2[tam] = 0;
		
		//chamada da função que irá fazer os cálculos
		opera(aux1, aux2);
	}
}

//limpeza do \n
void clear(char str[])
{
	int c = strlen(str);
	if (str[c - 1] == '\n') str[c - 1] = 0;
}
//cálculos
void opera(char str1[], char str2[])
{
	//declaração de variáveis
	int dist_rel, dist  = 0, i;
	//
	//cálculo da distância em função dos caracteres
	for (i = 0; str1[i]; i++)
	{
		dist_rel = str2[i] - str1[i];
		if (dist_rel < 0)
		{
			dist_rel += 26;
		}
		dist += dist_rel;
	}
	//saída
	printf("%d\n", dist);
}

