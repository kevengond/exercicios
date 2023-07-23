#include <stdio.h>
#include <string.h>

int main(void)
{
	//declaração de variáveis
	int lin, col, ini1 = 1, i, j;
	
	//leitura da quantidade de linhas e colunas
	scanf("%d %d", &lin, &col);
	
	//declaração do tabuleiro e limpeza da memória
	int tab[lin][col];
	memset(tab, 0, sizeof(tab));
	
	//cálculos e saída	
	ini1 = 1;
	for (i = 0; i < lin; i++)
	{
		for (j = 0; j < col; j++)
		{
			if(ini1) //se o início deve ser 1
			{
				if (j % 2 == 0) tab[i][j] = 1;
			}
			else if (!ini1) //se o início deve ser diferente de 1
			{
				if (j % 2 != 0) tab[i][j] = 1;
			}
			printf("%d", tab[i][j]);
		}
		printf("\n");
		if (ini1) ini1 = 0;
		else ini1 = 1;
	}
}
