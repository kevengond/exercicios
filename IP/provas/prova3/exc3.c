#include <stdio.h>
#include <string.h>

//constante com a quantidade máxima permitida
enum {MAX = 500};
	
//função para a limpeza da string (retirada do \n)
void clear(char str[])
{
	int c = strlen(str);
	if (str[c - 1] == '\n') str[c - 1] = 0;
}

//função pedida
int strcmpnerd( char *s1, char* s2)
{
	//declaração de variáveis
	int tam1, tam2, i, cont = 0;
	
	//descoberta do tamanho das strings
	tam1 = strlen(s1);
	tam2 = strlen(s2);
	
	//testes e saídas
	for (i = 0; i < tam1; i++)
	{
		if (s1[i] > s2[i]) return 1;
		else if (s1[i] < s2[i]) return -1;
		cont++;
	}
	if (cont  == tam2) return 0;
	else if (cont < tam2) return -1;
	else if (cont > tam2) return 1;
}

int main(void)
{
	//declaração de variáveis
	int quant, i;
	char str1[MAX], str2[MAX];
	
	//leitura da quantidade de testes e limpeza do \n
	scanf("%d", &quant);
	if (quant <= 0) return 0;
	getchar();
	
	//leitura dos valores e chamada da função
	for (i = 0; i < quant; i++)
	{
		fgets(str1, MAX, stdin);
		clear(str1);

		fgets(str2, MAX, stdin);
		clear(str2);
		
		//saída	
		printf("%d\n", strcmpnerd(str1, str2));
	}
}
