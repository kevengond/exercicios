#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//quantidade máxima de caracteres permitida
enum {MAX = 1000};

//declaração das structs para as mercadorias e clientes
typedef struct mr
{
	int cod;
	float pre;
	char *nome;
}mercadoria;

typedef struct cli
{
	char *nome_cli;
	int cod_mer;
	int quant;
}cliente;

//função para a limpeza do \n na string
void clear(char str[])
{
	int c = strlen(str);
	if (str[c - 1] == '\n') str[c - 1] = 0;
}

int main(void)
{
	//declaração de variáveis
	int quant_mer, quant_cli, i, j;
	char buff[MAX];
	
	//leitura da quantidade de mercadorias
	scanf("%d", &quant_mer);
	if (quant_mer < 1 || quant_mer > 20) return 1;
	
	//declaraçã de um vetor mercadorias
	mercadoria mercado[quant_mer];
	
	//leitura dos dados das mercadorias
	for (i = 0; i < quant_mer; i++)
	{
		scanf("%d %f", &mercado[i].cod, &mercado[i].pre);
		getchar();
		fgets(buff, MAX, stdin);
		clear(buff);

		mercado[i].nome = (char *) malloc(sizeof(char) * (strlen(buff) + 1));
		strcpy(mercado[i].nome, buff);
	}
	
	//leitura da quantidade de clientes	
	scanf("%d", &quant_cli);
	if (quant_cli < 1 || quant_cli > 100) return 1;
	getchar();
	
	//declaração de um vetor de clientes
	cliente clientes[quant_cli];
	
	//leitura dos dados dos clientes
	for (i = 0; i < quant_cli; i++)
	{
		fgets(buff, MAX, stdin);
		clear(buff);

		clientes[i].nome_cli = (char *) malloc(sizeof(char) * (strlen(buff) + 1));
		strcpy(clientes[i].nome_cli, buff);

		scanf("%d %d", &clientes[i].cod_mer, &clientes[i].quant);
		getchar();
	}

	saída e liberação da memória alocada
	for (i = 0; i < quant_cli; i++)
	{
		printf("Pedido de Compra do Cliente: %d\n", i + 1);
		printf("Nome do cliente: %s\n", clientes[i].nome_cli);
		
		for (j = 0; j < quant_mer; j++)
		{
			if(clientes[i].cod_mer == mercado[j].cod)
			{
				printf("Nome da mercadoria: %s\n", mercado[j].nome);
				printf("Quantidade: %d\n", clientes[i].quant);
				printf("Valor da Mercadoria: %.2f\n", mercado[j].pre);
				printf("Valor total da Compra: %.2f\n", mercado[j].pre * clientes[i].quant);
			}
		}
		
		free(clientes[i].nome_cli);
		printf("\n");
	}

	for (i = 0; i < quant_mer; i++) free(mercado[i].nome);
}

