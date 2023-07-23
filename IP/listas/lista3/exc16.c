#include <stdio.h>
#include <string.h>

//constante com a quantidade máxima de caracteres
enum {N = 257};

//função para a limpeza da string
void str_clean(char str[], char lim[]);

int main(void)
{
	char str[N]; // string original
	char clr[N]; // lista de caracteres indesejados
	
	//leitura da string e dos caracteres a serem retirados
	scanf("%[^\n]", str);
	scanf("\n%[^\n]", clr);
	
	//chamada da função de limpeza
	str_clean(str, clr);
	
	//saída
	printf("%s\n", str);
	
	return 0;
}

//função de limpeza
void str_clean(char str[], char lim[])
{
	//declaração de variáveis
	int tam_a, tam_n, i, j, cont, k = 0;
		
       //decoberta do tamanho da string antiga e da string nova	
	tam_a = strlen(str);
	tam_n = tam_a - strlen(lim);
	
	//declaração de uma string auxiliar
	char n_str[tam_n + 1];
	
	//limpeza e amazenamento na auxiliar
	for (i = 0; str[i]; i++)
	{
		cont = 0;

		for (j = 0; lim[j]; j++)
		{
			if (str[i] == lim[j]) cont++;
		}
		if (cont == 0) 
		{
			n_str[k] = str[i];
			k++;
		}
	}
	n_str[k] = 0;
	
	//Passagem para a string original	
	strcpy(str, n_str);
}


	

