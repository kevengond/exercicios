#include <stdio.h>

//função para a matriz (Ajudado pelo Gustavo)
void quadprint(int tam_fund, int col, int lin, int cor, int dist, int tipo, int mat[tam_fund][tam_fund]);

int main(void)
{
	//declaração de variáveis
	int tam_fund, cor_fund, cor, lin, col, tipo, dist, i, j, aux;
	
	//leitura do tamanho e cor do fundo
	scanf("%d %d", &tam_fund, &cor_fund);
	
	//declaração da matriz de fundo e colocação da cor	
	int mat[tam_fund][tam_fund];
	for (i = 0; i < tam_fund; i++)
	{
		for (j = 0; j < tam_fund; j++)
		{
			mat[i][j] = cor_fund;
		}
	}
	
	//leiutra dos quadrados e alocação no quadro 
	col = 0;
	lin = 0;
	while (col != -1 && lin != -1)
	{
		scanf("%d %d", &col, &lin);
		if (col == -1 || lin == -1) break;
		
		scanf("%d %d %d", &cor, &dist, &tipo);
		
		//chamada para a função 	
		quadprint(tam_fund, col, lin, cor, dist, tipo, mat);
	}	
	
	//saída	
	printf("P2\n");
	printf("%d %d\n", tam_fund, tam_fund);
	printf("255\n");
	for (i = 0; i < tam_fund; i++)
	{
		for (j = 0; j < tam_fund; j++)
		{
			printf("%d ", mat[i][j]);
		}
		printf("\n");
	}

	return 0;
}

//função para guardar os quadrados no fundo desejado (Ajudado pelo Gustavo)
void quadprint(int tam_fund, int col, int lin, int cor, int dist, int tipo, int mat[tam_fund][tam_fund])
{
	int i, j;

 if((dist*2) + 1 <=tam_fund && lin-dist>=0 && col-dist>=0 && lin+dist<=tam_fund - 1 && col+dist<=tam_fund - 1){
          
          if(tipo==1){
              
              for(i=lin-dist; i<=lin+dist; i++){
                  for(j=col-dist; j<=col+dist; j++){
                      
                      if(i==lin-dist || j==col-dist || i==lin+dist || j==col+dist){
                          mat[i][j]= cor;
                      }
                  }
              }
          }
          else{
              
              for(i=lin-dist; i<=lin+dist; i++){
                  for(j=col-dist; j<=col+dist; j++){
                      
                        mat[i][j]= cor;
                  }
              }
          }
      }
}


