#include <stdio.h>

//constantes com as quantidades permitidas para cada imagem
enum {MAXL = 10, MIN = 1, MAX = 320};

//função para a procura do logotipo
int procura(int od_i, int od_l, int img[od_i][od_i], int logo[od_l][od_l]);

int main(void)
{
	//declaração de constantes
	int ord_log, i, j, ord_img, res;
	
	//leitura da ordem do logotipo e teste de validade
	scanf("%d", &ord_log);
	if (ord_log < MIN || ord_log > MAXL) return 1;
	
	//declaração do logo
	int logo[ord_log][ord_log];
	
	//leitura dos valores do logotipo
	for (i = 0; i < ord_log; i++)
	{
		for (j = 0; j < ord_log; j++)
		{
			scanf("%d", &logo[i][j]);
		}
	}
	
	//leitura da ordem da imagem e teste de validade
	scanf("%d", &ord_img);
	if (ord_img < MIN || ord_img > MAX) return 2;
	
	//declaração da imagem
	int img[ord_img][ord_img];
	
	//leitura dos valores da imagem	
	for (i = 0; i < ord_img; i++)
	{
		for (j = 0; j < ord_img; j++)
		{
			scanf("%d", &img[i][j]);
		}
	}
	
	//chamada da função para procura
	res = procura(ord_img, ord_log, img, logo);
	
	//saída
	if (res) printf("sim\n");
	else printf("nao\n");
}

//função se retorna se a imagem está presente ou não
int procura(int od_i, int od_l, int img[od_i][od_i], int logo[od_l][od_l])
{
	//declaração de variáveis
	int i, j, k, l, cont;
	
	//procura e cálcuos
	for (i = 0; i < od_i - od_l + 1; i++)
	{
		for (j = 0; j < od_i - od_l + 1; j++)
		{
				cont = 0;
				for (k = 0; k < od_l; k++)
				{
					for (l = 0; l < od_l; l++)
					{
						if (img[i+k][j+l] == logo[k][l])
						{
							cont++;
						}
					}
				}
				if (cont == (od_l * od_l)) //caso enconte 
				{
					return 1;	
				}
		}
	}
	return 0; //caso contrário
}

