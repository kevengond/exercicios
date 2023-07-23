#include <stdio.h>

//Constantes com as quantidades máximas e mínimas permitidas
enum {MAX = 100, MIN = 0};

int main(void)
{
	//declaração de variáveis
	int quant, i, j, menor, maior, q_num, num;
	
	//leiutra da quantidade de testes
	scanf("%d", &quant);

	for (i = 0; i < quant; i++)
	{
		//Auxiliares para as quantidades máximas e mínimas 
		maior = MIN;
		menor = MAX - 1;
	
		//leitura da quantidade de números que serão lidos
		scanf("%d", &q_num);

		for (j = 0; j < q_num; j++)
		{
			//leitura do número
			scanf("%d", &num);
			
			//comparações com o maior par e o menor ímpar
			if (num > maior && num % 2 == 0) maior = num;
			if (num < menor && num % 2 != 0) menor = num;
		}
		
		//saídas
		if (maior != MIN) printf("%d\n", maior);
		else printf("Nao ha valores pares.\n");

		if (menor != MAX - 1) printf("%d\n", menor);
		else printf("Nao ha valores impares.\n");
	}
}
