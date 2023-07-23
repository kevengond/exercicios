#include <stdio.h>
#include <string.h>

//função que fará os testes de validade
int valid(int cpf[]);

enum {TAM_CPF = 11};

int main(void)
{
	//declaração das variáveis 
	int j, i, quant, validade;
	
	//leitura da quantidade de cpfs que serão lidos	
	scanf("%d", &quant);
	
	//delcaração do vetor que armazena o cpf	
	int cpf[TAM_CPF];

	//leitura e teste de validade dos cpfs	
	for (i = 0; i < quant; i++)
	{
		for (j = 0; j < TAM_CPF; j++) scanf("%d", &cpf[j]);

		if (valid(cpf)) printf("CPF valido\n");
		else printf("CPF invalido\n");
	}
}

//testes de validade
int valid(int cpf[])
{
	int i, aux = 0, p10, p11;

	for (i = 0; i < TAM_CPF; i++) aux += cpf[i];
	if (aux % 11) return 0;
	
	aux = 0;
	for (i = 0; i < TAM_CPF - 2; i++) aux += (cpf[i] * (i + 1));
	
	p10 = aux % 11;
	if (p10 == 10) p10 = 0;
	
	aux = 0;
	for (i = 0; i < TAM_CPF - 2; i++) aux += (cpf[i] * (TAM_CPF - 2 - i)); 

	p11 = aux % 11;
	if (p11 == 10) p11 = 0;
	
	if (p10 == cpf[TAM_CPF - 2] && p11 == cpf[TAM_CPF - 1]) return 1;
	return 0;
}

