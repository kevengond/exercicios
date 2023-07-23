#include <stdio.h>

//função para a freaquência
void freq(int vt[], int q);

int main(void)
{
	//declaração de variáveis
	int quant, i;

	//leitura da quantidade de elementos do vetor
	scanf("%d", &quant);
	if (quant < 1 || quant > 1000000) return 1;

	//declaração do vetor
	int vet[quant]; 

	//leitura dos números 
	for (i = 0; i < quant; i++) scanf("%d", &vet[i]);

	//chamada da função 
	freq(vet, quant);
}

//cálculos das frequências dos números e saída 
void freq(int vt[], int q)
{
	int mf, aux, cont = 0, cont_aux = 0, i, j;

	for (i = 0; i < q; i++)
	{
		aux = vt[i];
		for (j = 0; j < q; j++)
		{
			if (vt[j] == aux)
			{
				cont++;
			}
		}
		if (cont_aux < cont)
		{
			mf = vt[i];
			cont_aux = cont;
		}
		cont = 0;
	}

	printf("%d\n", mf);
	printf("%d\n", cont_aux);
}	


