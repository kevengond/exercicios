#include <stdio.h>
#include <string.h>

//quantidade máxima de bits
enum {BITMAX  = 32};

int main(void)
{
	//declaração de variáveis
	int num, i, cont = 0, caso;
	
	//leitura dos números em decimal e saída em binário
	while (scanf("%d", &num) != EOF)
	{
		short int vetbin[BITMAX];
		memset(vetbin, 0, sizeof(vetbin));

		cont = 0;
		caso = 0;

		while (num)
		{
			vetbin[cont] = num % 2;
			num /= 2;
			cont++;
		}	

		for (i = BITMAX - 1; i >= 0; i--) 
		{
			if (vetbin[i]) caso = 1;
			if (caso) printf("%hd", vetbin[i]);	
		}	
		printf("\n");
	}
}
			
