#include <stdio.h>
#include <string.h>
#include <math.h>

//declaração de uma constante com a quantidade máxima de caracteres 
enum {QMAX = 1001};

//funções para a criptografia e limpeza de uma string
void cripto(char str[]);
void clear(char str[]);

int main(void)
{
	//declaração de variáveis
	int quant, i;
	char str[QMAX];
	
	//leitura da quantidade de casos e teste de sua validade
	scanf("%d", &quant);
	if (quant < 1 || quant > 10000) return 1;
	getchar();

	//leitura da string e criptografia
	for (i = 0; i < quant; i++)
	{
		fgets(str, QMAX, stdin);
		clear(str);	
		
		//chamada da função para criptografar	
		cripto(str);

	}
}

//função que irá limpar o \n
void clear(char str[])
{
	int c = strlen(str);
	if (str[c - 1] == '\n') str[c - 1] = 0;
	else while (getchar() != '\n');
}

//função par criptografar a stirng
void cripto(char str[])
{
	//declaração de variáveis
	int i, tam = strlen(str);
	char aux[tam + 1];

	//Primeira etapa: Adicionar 3 posições as letras	
	for (i = 0; str[i]; i++) 
	{
		if ((str[i] >= 65 && str[i] <= 90) || (str[i] >= 97 && str[i] <= 122)) str[i] += 3;
	}
	
	//Segunda etapa: Inverter a string	
	for (i = 0; str[i]; i++) aux[i] = str[tam - 1 - i];
	aux[tam] = 0;
	
	//decobrir a metade da string	
	tam = strlen(str) / 2;
	
	//Terceira etapa: A partir da metade para frente, retornar uma posição	
	for (i = tam; aux[i]; i++) aux[i] -= 1;
	
	//Saída
	for (i = 0; aux[i]; i++) printf("%c", aux[i]);
	printf("\n");
}
