#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//constante com a quantidade máxima de caracteres suportado
enum {QMAX = 5};

//função que irá imprimir a saída
void divnum(int ini, int fim);

int main(void)
{
	//declaração de variáveis
	int quant, i, ini, fim;

	//leitura da quantidade de casos de teste
	scanf("%d", &quant);

	for (i = 0; i < quant; i++)
	{
		//leitura dos valores iniciais e finais
		scanf("%d %d", &ini, &fim);
		if (ini < 1 || ini > fim || fim > 12221) return 1; 
		//no sharif acusava o erro no teste de validade 
		
		//chamada para a função
		divnum(ini, fim);
	}
}

//função que irá imprimir os dígitos na ordem correta
void divnum(int ini, int fim)
{
	//delcaração de variávies
	int i, j, tam, aux;
	char num[QMAX];
	
	//imprime a primeira parte do número inicial a até o final	
	for (i = ini; i <= fim; i++) printf("%d", i);
	
	//cálculos e separação dos dígitos para saída
	for (i = fim; i >= ini; i--)
	{
		tam = sprintf(num, "%d", i);

		for (j = tam - 1; j >= 0; j--) printf("%c", num[j]);
	}	
	printf("\n");
}
