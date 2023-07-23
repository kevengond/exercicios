#include <stdio.h>
#include <string.h>
#include <ctype.h>

//declarçaão de constante com a quantidade máxima de caracteres na string
enum {QMAX = 5001};

//função para a aliteração
void alit(char str[]);

int main(void)
{
	//declaração do vetor que conterá as strings
	char str[QMAX];
	
	//leiutra e limpeza do \n até o final do arquivo
	while (scanf("%[^\n]", str) != EOF)
	{
		getchar();
	
		//chamada da função que contará as aliterações
		alit(str);
	}
}

//função de saída da quantidade de aliterações
void alit(char str[])
{
	//declaração de variávies
	int cont = 0, trt = 1,  i; 
	char crt = tolower(str[0]);
	
	//cálculos
	for (i = 1; str[i]; i++)
	{
		if (str[i] == ' ')
		{
			if (tolower(str[i + 1]) == crt) 
			{
				if (trt) cont++;
				trt = 0;
			}
			else
			{	
				crt = tolower(str[i + 1]);
				trt = 1;
			}
		}
	}
	//saída
	printf("%d\n", cont);
}



