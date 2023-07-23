#include <stdio.h>
#include <string.h>

//quantidade máxima de caracteres por string
enum {MAX = 201};

int main(void)
{
	//declaração de variáveis e a string
	int i, j, tam, cont;
	char str[MAX];

	//leitura e verificação enquanto não chegar ao fim do arquivo
	while (scanf("%[^\n]", str) != EOF)
	{
		//zerar o contador a cada cíclo
		cont = 0;
		
		//limpeza do \n lido
		getchar();
		
		//saber o tamanho da string lida para o for
		tam = strlen(str);
		
		//comparação 
		for (i = 0; i < tam / 2; i++)
		{
			if (str[i] == str[tam - 1 - i]) cont++;
		}
	
		//saída
		if (cont == tam / 2) printf("sim\n");
		else printf("nao\n");
	}
}

