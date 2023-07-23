#include <stdio.h>
#include <string.h>
#include <math.h>

//declaração de constantes 
enum {QRES = 5, DQ_MAX = 2002};

//função para o teste de valida e cálculo das vogais
int test_pas(char vaux[]);

int main(void)
{
	//declaração do vetor que pegará as duas strings
	char vaux[DQ_MAX];
	
	//leitura da string	
	fgets(vaux, DQ_MAX, stdin);
	
	//chamada da função e retorno caso inválido	
	if (!test_pas(vaux))
	{
		printf("FORMATO INVALIDO!\n");
		return 1;
	}

}

//função para o teste e saída
int test_pas(char vaux[])
{
	//declaração de variáveis
	int i, cont = 0, tam, r1[QRES], r2[QRES];
	double som = 0;

	//retirada dos valores nos vetores	
	memset(r1, 0, sizeof(r1));
	memset(r2, 0, sizeof(r2));
	
	//verificação dos ;
	for (i = 0; vaux[i]; i++) 
	{
		if (vaux[i] == ';') 
		{
			cont++;
			tam = i;
			
		}
	}
	if (cont != 1) return 0;

	//cálculo das vogais na primeira string
	for (i = 0; i < tam; i++)
	{
		if (vaux[i] == 'a' || vaux[i] == 'A') r1[0] += 1;
		else if (vaux[i] == 'e' || vaux[i] == 'E') r1[1] += 1;
		else if (vaux[i] == 'I' || vaux[i] == 'i') r1[2] += 1;
		else if (vaux[i] == 'o' || vaux[i] == 'O') r1[3] += 1;
		else if (vaux[i] == 'u' || vaux[i] == 'U') r1[4] += 1;
	}

	//cálculo das vogais na segunda string
	for (i = tam; vaux[i]; i++)
	{
		if (vaux[i] == 'a' || vaux[i] == 'A') r2[0] += 1;
		else if (vaux[i] == 'e' || vaux[i] == 'E') r2[1] += 1;
		else if (vaux[i] == 'I' || vaux[i] == 'i') r2[2] += 1;
		else if (vaux[i] == 'o' || vaux[i] == 'O') r2[3] += 1;
		else if (vaux[i] == 'u' || vaux[i] == 'U') r2[4] += 1;
	}

	//saída dos resultados	
	printf("(%d,%d,%d,%d,%d)\n", r1[0], r1[1], r1[2], r1[3], r1[4]);
	printf("(%d,%d,%d,%d,%d)\n", r2[0], r2[1], r2[2], r2[3], r2[4]);
	
	//cálculo e saída da da distância entre A e B
	for (i = 0; i < QRES; i++)
	{
		som += pow(r1[i] - r2[i], 2);
	}

	som = sqrt(som);

	printf("%.2lf\n", som);
}
