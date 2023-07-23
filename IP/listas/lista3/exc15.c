#include <stdio.h>
#include <string.h>
#include <ctype.h>

//constante com a quantidade máxima de caracteres por linha
enum{QMAX = 201};

//funções de limpeza da string, quantificação e comparação
void clear(char str[]);
void quantifi(char str[]);
void comp(int let[]);

int main(void)
{
	//declaração de variáveis
	int quant, i;
	char str[QMAX];
	
	//leitura da quantidade de casos de teste e limpeza do \n	
	scanf("%d", &quant);
	getchar();
	
	for (i = 0; i < quant; i++)
	{
		//leitura dos dados e limpeza do \n
		fgets(str, QMAX, stdin);
		clear(str);
		
		//chamada da função para quantificar as letras
		quantifi(str);

	}
}

//função para a limpeza do \n
void clear(char str[])
{
	int c = strlen(str);
	if (str[c - 1] == '\n') str[c - 1] = 0;
}

//função para quantificar as letras da string lida
void quantifi(char str[])
{
	//delcaração do vetor que recebe a quantidade de cada letra na string 
	//(0 = a | 25 = z) e outras variávies
	int let[26], i, aux;
	
	//limpeza do vetor
	for (i = 0; i < 26; i++) let[i] = 0;
	
	//cálculos
	for (i = 0; str[i]; i++)
	{
		//se o caractere não for numérico ou especial
		if (isalpha(str[i]))
		{
			//se for minúscula
			if (islower(str[i]))
			{
				aux = str[i] - 97;
				let[aux]++;
			}
			else //se for maiúscula
			{
				aux = str[i] - 65;
				let[aux]++;
			}
		}
	}
	
	//chamada da função para a comparação e saída 	
	comp(let);
}

//função que irá comparar os resultados das quantidades de cada letra
//e promove a saída
void comp(int let[])
{
	//declaração de variáveis
	int i = 0, maior;
	
	//busca da maior quantidade 
	maior = 0;	
	for (i = 0; i < 26; i++)
	{
		if (let[i] > maior)
		{
			maior = let[i];
		}
	}
	
	//comparação se a quantidade é igual a maior quantidade e saída	
	for (i = 0; i < 26; i++)
	{
		if (maior == let[i])	
		{	
			printf("%c", i + 97);
		}
	}
	printf("\n");
}

