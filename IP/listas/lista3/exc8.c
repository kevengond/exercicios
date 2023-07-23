#include <stdio.h>
#include <string.h>

//declaração de uma constante com a quantidade máxima de caracteres na string
enum{QMAX = 500};

//funções para a limpeza da sttrig e pesquisa do caractere
void clean(char str[]);
int pesquisa(char str[], char pesq);

int main(void)
{
	//delcaração de variáveis
	int quant, i, idx;
	char str[QMAX], pesq;	
	
	//leitura da quantidade de casos de teste e teste de validade
	scanf("%d", &quant);
	if (quant < 1 || quant > 20) return 1;
	getchar();
	
	//enquanto não chegar na quantidade de testes
	for (i = 0; i < quant; i++)
	{
		//pegar o caractere para pesquisa e limpeza do ' ' 
		pesq = getchar();
		getchar();
		
		//leitura da string e limpeza do \n
		fgets(str, QMAX, stdin);
		clean(str);
		
		//chamada da função para a pesquiza do caractere
		idx = pesquisa(str, pesq);
		
		//saída
		if (idx != -1) printf("Caractere %c encontrado no indice %d da string.\n", pesq, idx);
		else printf("Caractere %c nao encontrado.\n", pesq);

	}

	return 0;
}

//função para limpar o \n da string
void clean(char str[])
{
	int c = strlen(str);

	if (str[c - 1] == '\n') str[c - 1] = 0;
}

//função para a pesquisa do caractere
int pesquisa(char str[], char pesq)
{
	int i;

	for (i = 0; str[i]; i++)
	{
		if (str[i] == pesq) return i;
	}

	return -1;
}
