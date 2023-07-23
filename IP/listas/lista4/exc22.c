#include <stdio.h>

//Constante com a ordem do tabuleiro
enum {ORDG = 9};

//função para verificar a validade
int valid(int tab[ORDG][ORDG]);

int main(void)
{
	//declaração de variáveis
	int tab[ORDG][ORDG], i, j, res;
	
	//leitura dos dados
	for (i = 0; i < ORDG; i++)
	{
		for (j = 0; j < ORDG; j++)
		{
			scanf("%d", &tab[i][j]);
		}
	}
	
	//chamada da função
	res = valid(tab);
	
	//saída
	if (res) printf("valido\n");
	else printf("invalido\n");
}
//função para verificar a validade do jogo passado
int valid(int tab[ORDG][ORDG])
{
	//declaração de validade
	int i, j, rep, cont = 0, k;
	
	//verificação das linhas
	for (i = 0; i < ORDG; i++)
	{
		rep = 0;
		k = 0;
		while (k < ORDG)
		{
			for (j = 0; j < ORDG; j++)
			{
				if (tab[i][k] == tab[i][j]) 
				{
					rep++; 
				}
			}
			k++;
		}
		if (rep > 9) return 0;
	}

	//verificação das colunas
	for (i = 0; i < ORDG; i++)
	{
		rep = 0;
		k = 0;
		while (k < ORDG)
		{
			for (j = 0; j < ORDG; j++)
			{
				if (tab[j][k] == tab[k][i]) 
				{
					rep++;
				}
			}
			k++;
		}
		if (rep > 9) return 0;
	}

	return 1;
}
