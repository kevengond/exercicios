#include <stdio.h>
#include <string.h>

int tamanho(int res)
{
	int cont = 0;
	
	while (res != 0)
	{
		res /= 10;
		cont++;
	}

	return cont;
}

int main(void)
{
	//delcaração de variáveis
	int num1, num2, res, tam, i;
	
	//leitura dos números e teste de validade
	scanf("%d %d", &num1, &num2);
	if (num1 < 1 || num2 < 1) return 1;
	getchar();
	
	//cãlculos e saída do valor
	while (num1 != 0 && num2 != 0)
	{
		res = num1 + num2;

		tam = tamanho(res);
		
		char num[tam + 1];
		
		sprintf(num, "%d", res);

		for (i = 0; i < tam; i++)
		{
			if (num[i] != '0') printf("%c", num[i]);
		}
		printf("\n");

		scanf("%d %d", &num1, &num2);
	}
}	
