#include <stdio.h>
#include <string.h>

//constantes com a quantidade máxima de caracteres
enum {M_MAX = 31, C_MAX = 51};

//declaração de structs para as mercadorias e clientes
typedef struct mr
{
	int cod;
	float pre;
	char nome[M_MAX];
}mercadoria;

typedef struct cli
{
	char nome_cli[C_MAX];
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
	
	//leitura da quantidade de mercadorias
	scanf("%d", &quant_mer);
	if (quant_mer < 1 || quant_mer > 20) return 1;
	
	//declaração de um vetor de mercadorias
	mercadoria mercado[quant_mer];
	
	//leitura dos dados das mercadorias
	for (i = 0; i < quant_mer; i++)
	{
		scanf("%d %f", &mercado[i].cod, &mercado[i].pre);
		getchar();
		fgets(mercado[i].nome, C_MAX, stdin);
		clear(mercado[i].nome);
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
		fgets(clientes[i].nome_cli, C_MAX, stdin);
		clear(clientes[i].nome_cli);

		scanf("%d %d", &clientes[i].cod_mer, &clientes[i].quant);
		getchar();
	}

	//saída e liberação das memórias	
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

		printf("\n");
	}
}
