#include <stdio.h>
#include <string.h>

//constante com a quantidade máxima de caracteres por teste
enum {MAX = 10001};

//funçõe para descobrir as quantidades de vogais e consoantes
int letras(char str[], int tam);
int vogais(char str[], int tam);

//função para limpar o \n da string
void clear(char str[])
{
	int c = strlen(str);
	if (str[c - 1] == 'n') str[c - 1] = 0;
}

int main(void)
{
	//declaração de variáveis
	int quant , i, tam, let, vog;
	char str[MAX];

	//leitura da quantidade de casos de testes
	scanf("%d", &quant);
	getchar();

	//leitura das strings e cálculos	
	for (i = 0; i < quant; i++)
	{
		//leitura da string e limpeza do \n
		fgets(str, MAX, stdin);
		clear(str);

		//quantidade de elementos na string (não retorna a quantidade de letras)
		tam = strlen(str);

		//quantidade de letras 
		let = letras(str, tam);
	       //quantidade de vogais	
		vog = vogais(str, tam);
		
		//saída da quantidade de consoantes
		printf("Consoantes = %d\n", let - vog);

	}
}
//função para a quantidade de letras 
int letras(char str[], int tam)
{
	int i, cont = 0;

	for (i = 0; i < tam; i++)
	{
		if (((str[i] >= 65) && (str[i] <= 90)) || (str[i] >= 97) && (str[i] <= 122)) cont++;
	}
	
	printf("Letras = %d\n", cont);

	return cont;
}

//função para a quantidade de vogais
int vogais(char str[], int tam)
{
	int i, vogM = 0, vogm = 0;

	for (i = 0; i < tam; i++)
	{
		if ((str[i] >= 65) && (str[i] <= 90))
		{
			switch (str[i])
			{
				case 'A':
				case 'E':
				case 'I':
				case 'O':
				case 'U':
					vogM++;
					break;
			}
		}
		if ((str[i] >= 97) && (str[i] <= 122))
		{
			switch (str[i])
			{
				case 'a':
				case 'e':
				case 'i':
				case 'o':
				case 'u':
					vogm++;
					break;
			}
		}
	}

	printf("Vogais = %d\n", vogm + vogM);

	return vogm + vogM;
}

