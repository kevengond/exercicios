#include <stdio.h>

int main(void)
{
	//declaração de variáveis
	int lin, col, i, j, ini0, cont;
	
	//leitura da quantidade de linhas e colunas
	scanf("%d %d", &lin, &col);
	
	//cálculos e saída
	ini0 = 1;
	cont = 1;
	for (i = 0; i < lin; i++)
	{
		for (j = 0; j < col; j++)
		{
			//se o início deve ser 0
			if (ini0)
			{
				if (!(j % 2)) printf("0 ");
				else printf("%d ", cont++);
			}
			else //se o início deve ser diferente de 0 
			{
				if (!(j % 2)) printf("%d ", cont++);
				else printf("0 ");
			}
		}
		printf("\n");

		if (ini0) ini0 = 0;
		else ini0 = 1;
	}
}

