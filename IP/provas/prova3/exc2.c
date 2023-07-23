#include <stdio.h>
#include <string.h>

//quantidade máxima de caracteres nas strings
enum {MAX = 500};

//função para a limpeza do \n
void clear(char str[])
{
	int c = strlen(str);
	if (str[c - 1] == '\n') str[c - 1] = 0;
}

int main(void)
{
	//decalração de varíaveis e da string
	char str[MAX];
	int i;
	
	//leitura dos valores, limpeza e saída
	while (fgets(str, MAX, stdin))
	{
		clear(str);

		for (i = strlen(str) - 1; i >= 0; i--)
		{
			printf("%c", str[i]);
		}
		printf("\n");
	}
}


