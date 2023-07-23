#include <stdio.h>
#include <string.h>
#include <math.h>

//declaração de constantes para a quantidade de leds em cada número
#define UM 2
#define DS 5
#define TR 5
#define QT 4
#define CC 5
#define SI 6
#define ST 3
#define OT 7
#define NV 6
#define ZR 6  

int main(void)
{
	//delcaração de variáveis
	int quant, i, tam, j, tot;
	char vet[100];

	//leitura da quantidade de testes
	scanf("%d", &quant);
	if (quant < 1 || quant > 1000) return 1;
	getchar();

	//leitura dos valores 
	for (i = 0; i < quant; i++)
	{
		tot = 0;
		
		//leitura do valor 
		fgets(vet, 100 , stdin);

		//tamamnho do valor
		tam = strlen(vet);
	
		//cálculos	
		for (j = 0; j < tam; j++)
		{
			switch (vet[j])
			{
				case '1':
					tot += UM;
					break;
				case '2':
				case '3':
				case '5':  
					tot += CC;
					break;
				case '4':
					tot += QT;
					break;
				case '8':
					tot += OT;
					break;
				case '7':
					tot += ST;
					break;
				case '6':
				case '9':
				case '0':
					tot += ZR;
					break;
			}
		}
		//saída da quantidade de leds	
		printf("%d leds\n", tot);

	}
}

