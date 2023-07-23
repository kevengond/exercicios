#include <stdio.h>

//funções para a leitura, união e intersecção dos conjuntos
void leitura(int conj[], int tam);
void uniao(int cja[], int cjb[], int tama, int tamb);
void intersec(int cja[], int cjb[], int tama, int tamb);

int main(void)
{
	//declaração de variáveis
	int quanta, quantb;

	//leitura das quantidades e teste de validade	
	quantb = 0;
	quanta = 0;
	while (quanta < 1 || quanta > 100) scanf("%d", &quanta);
	while (quantb < 1 || quantb > 100) scanf("%d", &quantb);

	//declaração dos conjuntos	
	int conja[quanta], conjb[quantb];
	
	//chamada para a leitura dos conjuntos
	leitura(conja, quanta);
	leitura(conjb, quantb);

	//chamada para a união e intersecção dos conjuntos
	uniao(conja, conjb, quanta, quantb);
	intersec(conja, conjb, quanta, quantb);

}

//função de leitura
void leitura(int conj[], int tam)
{
	//declaração de veriávies
	int i, j, cont;

	//leitura com o teste de validade
	for (i = 0; i < tam; i++)
		{
			cont = i;
			scanf("%d", &conj[i]);
			for (j = 0; j < i; j++) 
			{
				if (conj[j] == conj[i]) i--;
			}
		}
}

//função de união
void uniao(int cja[], int cjb[], int tama, int tamb)
{
	//declaração de variávies
	int i, j, cont, vet[tama + tamb], tam = 0;

	printf("(");
	
	//"união" da primeira parte	
	for (i = 0; i < tama; i++)
	{
		vet[i] =  cja[i];
	}
	
	//comparação de igualdade e junção na "união"
	for (i = 0; i < tamb; i++)
	{
		cont = 0;
		for (j = 0; j < tama; j++) 
		{
			if (cja[j] == cjb[i]) cont++; 
		}
		if (cont == 0) 
		{
			vet[tama + tam] =  cjb[i];
			tam++;
		}
	}
	
	//saída
	for (j = 0; j < tama + tam; j++)
	{
		printf("%d", vet[j]);
		if (j < tama + tam - 1) printf(",");
	}
	printf(")\n");
}

//função de intersecção
void intersec(int cja[], int cjb[], int tama, int tamb)
{ 
	//declaração de variávies
	int i, j, maior, vet[tama + tamb], cont, tam = 0;
	
	//busca pelo conjunto de maior tamanho
	maior = (tama > tamb) ? tama : tamb;
	
	printf("(");
	
	//caso o conjunto A seja maior 
	if (tama == maior)
	{
		//compara e coloca o valor na intersecção
		for (i = 0; i < tama; i++)
		{
			cont = 0;
			for (j = 0; j < tamb; j++)
			{
				if (cja[i] == cjb[j]) cont++;
			}
			if (cont != 0) 
			{
				vet[tam] = cja[i]; 
				tam++;
			}
		} 
	       	//saída	
		for (j = 0; j < tam; j++)
		{
			printf("%d", vet[j]);
			if (j < tam - 1) printf(",");
		}
		printf(")\n");

	}
	else //caso o conjunto B seja maior 
	{
		//compara e coloca o valor na intersecção
		for (i = 0; i < tamb; i++)
		{
			cont = 0;
			for (j = 0; j < tama; j++)
			{
				if (cjb[i] == cja[j]) cont++;
			}
			if (cont != 0)
			{
				vet[tam] = cjb[i];
				tam++;
			}
		} 
		//saída
		for (j = 0; j < tam; j++)
		{
			printf("%d", vet[j]);
			if (j < tam - 1) printf(",");
		}		
		printf(")\n");
	} 

}




