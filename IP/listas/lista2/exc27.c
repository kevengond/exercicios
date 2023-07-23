#include <stdio.h>

//funções para criar um vetor, e ordenação
void criavet(int vt1[], int vt2[], int vt3[], int qt1, int qt2);
void bubble(int vt[], int tm);
void troca(int *p, int *q);

int main(void)
{
	//declaração de variáveis
	int qt1, qt2, i;
	
	//leitura da quantidade de elementos em cada vetor e testte de validade
	scanf("%d %d", &qt1, &qt2);
	if ((qt1 <= 0 || qt1 > 500000) || (qt2 <= 0 || qt2 > 500000)) return 1;

	//declaração dos vetores	
	int vt1[qt1], vt2[qt2], vt3[qt1 + qt2];
	
	//leitura dos valores do primeiro vetor
	for (i = 0; i < qt1; i++) scanf("%d", &vt1[i]);
	
	//leitura dos valores do seugundo vetor
	for (i = 0; i < qt2; i++) scanf("%d", &vt2[i]);

	//chamada da função para concatenar os vetores vt1 e vt2 em vt3 (criando o vetor vt3)	
	criavet(vt1, vt2, vt3, qt1, qt2);
	
	//bubblesort para ordenar o vetor vt3
	bubble(vt3, qt1 + qt2);
	
	//saída
	for (i = 0; i < (qt1 + qt2); i++) printf("%d\n", vt3[i]);

}

//função para criar um vetor a partir da concatenação de outros dois
void criavet(int vt1[], int vt2[], int vt3[], int qt1, int qt2)
{
	int i;

	for (i = 0; i < qt1; i++)
	{
		vt3[i] = vt1[i];
	}

	for (i = 0; i < qt2; i++)
	{
		vt3[qt1 + i] = vt2[i];
	}
}

//bubblesort para ordenar o vetor 
void bubble(int vt[], int tm)
{
	int i, j;

	for (i = 1; i < tm; i++)
	{
		for (j = 0; j < tm - i; j++)
		{
			if (vt[j] > vt[j + 1]) troca(&vt[j], &vt[j + 1]);
		}
	}
}

//troca dos valores
void troca(int *p, int *q)
{
	int aux = *p;
	*p = *q;
	*q = aux;
}
