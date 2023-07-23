#include <stdio.h>

//declaração de uma constante com a quantidade máxima de cidades
enum {QUANT = 6};
	
//funções para armazenar os valores na tabela e cálculo da distância entre as cidades
int viagem(int tam, int rot[]);
void formatab(int cty[QUANT][QUANT]);

int main(void)
{
	//declaração de variáveis
	int tam, i, dist;
	
	//leitura do tamanho da viagem
	scanf("%d", &tam);
	
	//declaração do vetor de rotas
	int rot[tam];
	
	//leitura da rota
	for(i = 0; i < tam; i++) scanf("%d", &rot[i]);
	
	//chamada da função que retorna a distância percorrida
	dist = viagem(tam, rot);
	
	//saída	
	if (dist) printf("%d\n", dist);
	else printf("rota invalida!\n");
}

//função que calcula a distância percorrida pelo trageto passado
int viagem(int tam, int rot[])
{
	//declaração de variáveis
	int i, j, cty[QUANT][QUANT], dist = 0;
	
	//chamada da função para armazenar as distâncias entre as cidades
	formatab(cty);
	
	//cálculos e retorno	
	for (i = 0; i < tam - 1; i++)
	{
		if (cty[rot[i]][rot[i + 1]] == -1)
		{
			return 0;
		}
		dist += cty[rot[i]][rot[i + 1]];
	}
	return dist;
}

//função que armazena a distância entre na matriz passada (OBS: O '-' seria -1
//para facilitar)
void formatab(int cty[QUANT][QUANT])
{
	cty[0][0] = 0;
	cty[0][1] = 63; 
	cty[0][2] = 210;
	cty[0][3] = 190;
	cty[0][4] = -1;
	cty[0][5] = 190;

	cty[1][0] = 63;
	cty[1][1] = 0;
	cty[1][2] = 160;
	cty[1][3] = 150;
	cty[1][4] = 95;
	cty[1][5] = 10;

	cty[2][0] = 210;
	cty[2][1] = 160;
	cty[2][2] = 0;
	cty[2][3] = 10; 
	cty[2][4] = 1; 
	cty[2][5] = 10;

	cty[3][0] = 190;
	cty[3][1] = 150;
	cty[3][2] = 10; 
	cty[3][3] = 0;
	cty[3][4] = 10;
	cty[3][5] = 20;

	cty[4][0] = 10;
	cty[4][1] = 95;
	cty[4][2] = 7;
	cty[4][3] = 21;
	cty[4][4] = 0;
	cty[4][5] = 80;

	cty[5][0] = 190;
	cty[5][1] = 2;
	cty[5][2] = -1;
	cty[5][3] = 41;
	cty[5][4] = 80;
	cty[5][5] = 0;
}
