#include <stdio.h>
#include <string.h>

//constantes com as quantidades máximas de casas e a quantidade de casas para o número 3
enum {TMAX = 7, TR = 5};

//função para a limpeza do \n
void clear(char str[])
{
	int c = strlen(str);
	if (str[c - 1] == '\n') str[c - 1] = 0;
}

int main(void)
{
	//declaração de variáveis
	int quant, i, tam, cont1, cont2;
	char num[TMAX];
	
	//leitura dos casos de testes e teste de validade
	scanf("%d", &quant);
	if (quant > 1000) return 1;
	getchar();
	
	//leitura dos valores e cálculos
	for (i = 0; i < quant; i++)
	{
		cont1 = 0;
		cont2 = 0;
		//leitura 
		fgets(num, TMAX, stdin);
		clear(num);
		
		tam = strlen(num);
		
		//cálculos e saída	
		if (tam == TR) printf("3\n");
		else 
		{
			if (num[0] == 'o') cont1++;
			else if (num[0] == 't') cont2++;	
			if (num[1] == 'n') cont1++;
			else if (num[1] == 'w') cont2++;
			if (num[2] == 'e') cont1++;
			else if (num[2] == 'o') cont2++;
		
			if (cont1 >= 2) printf("1\n");
			else if (cont2 >= 2) printf("2\n");
		}
	}
}

		
