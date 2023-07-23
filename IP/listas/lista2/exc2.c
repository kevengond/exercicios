#include <stdio.h>

int main(void)
{
	//declaração das variáveis 
	int num, i, num_base, cont = 0;
	
	//leitura da quantidade de elementos do vetor e teste de validade 
	scanf("%d", &num);	
	while (num < 1 || num > 1000) scanf("%d", &num);
	
	//declarção do vetor
	int vet[num];
	
	//leitura dos números do vetor
	for (i = 0; i < num; i++) scanf("%d", &vet[i]);
	
	//leitura do número base 
	scanf("%d", &num_base);
	
	//quantidade de elementos do vetor maiores que o número base
	for (i = 0; i < num; i++) if (vet[i] >= num_base) cont++;
	
	printf("%d\n", cont);
}
