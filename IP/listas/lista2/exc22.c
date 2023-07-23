#include <stdio.h>
#include <string.h>
 
//constantes para as quantidades máximas e mínimas
#define MAX 10000
#define MIN 1

//função para selecionar os números
void selecnum(char num[], int d_num, int d_rest);

int main(void)
{
    //declarçaão de variávies
    int d_num, d_rest;
    
    //leitura da quantidade de dígitos colocados e a quantidade restante, com os seus
    //testes de validade
    scanf("%d %d", &d_num, &d_rest);
    if (d_num < MIN || d_num > MAX || d_num <= d_rest || d_rest < MIN) return 1;
    getchar();
    
    //cálculos e saída do maior número possível enquanto a quandidade colocada de 
    //dígitos e o restante for != de 0
    while (d_num != 0 && d_rest != 0)
    {
        //declarção do vetor que ifá armazenar o resultado e sua limpeza
        char num[d_rest + 1];
        memset(num, 0, sizeof(num));    
   
       	//chamada da função	
	selecnum(num, d_num, d_rest);
    
        //saída
        printf("%s\n", num);
    
        //leitura novamente    
        scanf("%d %d", &d_num, &d_rest);
        getchar();
    }
}
//função para a seleção dos números
void selecnum(char num[], int d_num, int d_rest)
{
	//declaração de variáveis
	int top, clc, i;
	char dig;

  	//cálculos    
    	top = -1;
        clc = 0;
        for (i = 0; i < d_num; i++)
        {
            scanf("%c", &dig); 
            
            while(top > -1 && clc < d_num - d_rest && dig > num[top])
            {
                top--;
                clc++;
            }
 
            if (top + 1 < d_rest) num[++top] = dig;
        }
        num[++top] = 0;
}

