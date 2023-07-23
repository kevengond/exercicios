#include <stdio.h>

int main(void)
{
	//declaração de variáveis
	int alunos, min_pres, i, cont = 0;
	
	//leitura da quantidade de alunos na sala e da quantidade mínima para a aula
	scanf("%d %d", &alunos, &min_pres);
	if ((alunos < 0 || alunos > 1000) || (min_pres < 0 || min_pres > 1000)) return 1;

	//declaraçõa do vetor de aluno	
	int vet[alunos];

	//leitura das chegadas e contagem dos adiantados/no horário correto
	for (i = 0; i < alunos; i++)
	{
		scanf("%d", &vet[i]);
		if (vet[i] <= 0) cont++;
	}

	//teste se terá aula e a lista de presença 
	if ( cont >= min_pres)
	{	

		printf("NAO\n");
		
		for (i = alunos - 1; i >= 0 ; i--)
		{
			if (vet[i] <= 0) printf("%d\n", i + 1);
		}
	}
	else printf("SIM\n");
}	



