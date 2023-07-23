#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// declaração de um tipo polinômio
typedef struct pol
{
    double num;
    int expo;
} polinom;

//funções para a soma e subtração dos polinômios
void som(int termos1, int termos2, polinom pl1[], polinom pl2[]);
void sub(int termos1, int termos2, polinom pl1[], polinom pl2[]);

int main(void)
{
    //declaração de variáveis
    int quant, i, j, termos1, termos2;
    char ope;
    
    //leitura da quantidade de operações
    scanf("%d", &quant);

    for (i = 0; i < quant; i++)
    {
        //limpeza do \n da quantidade de operações e leitura da operação (+/-)
        getchar();
        ope = getchar();
    
        //leitura da quantidade de termos do primeiro polinômio
        scanf("%d", &termos1);
        if (termos1 > 50) return 1;
    
        //declaração de um polinômio
        polinom pl1[termos1];
        
        //leitura dos valores
        for (j = 0; j < termos1; j++)
        {
            scanf("%lf %d", &pl1[j].num, &pl1[j].expo);
        }
    
        //leitura da quantidade de termos do segundo polinômio
        scanf("%d", &termos2);
        if(termos2 > 50) return 2;
        
        //declaração do polinômio
        polinom pl2[termos2];
        
        //leitura dos valores para o segundo polinôio
        for (j = 0; j < termos2; j++)
        {
            scanf("%lf %d", &pl2[j].num, &pl2[j].expo);
        }
        
        //teste e chamada das funções para as operações 
        if (ope == '+') som(termos1, termos2, pl1, pl2);
        else sub(termos1, termos2, pl1, pl2);
    }
}

// função soma
void som(int termos1, int termos2, polinom pl1[], polinom pl2[])
{
    // declaração de variáveis
    int i, maior, j, k;
    double num1, num2;
    int expo1, expo2;
    polinom soma[termos1 + termos2];
    
    //busca do maior expoente 
    maior = (pl1[0].expo > pl2[0].expo) ? pl1[0].expo : pl2[0].expo;
    
    //procura dos elementos de acordo com o expoente e soma 
    for (j = maior; j >= 0; j--)
    {
        //limpeza dos valores já estabelecidos (necessário)
        expo1 = -1;
        expo2 = -1;
        
        //procura no polinômio 1 
        for (k = 0; k < termos1; k++)
        {
            if (pl1[k].expo == j)
            {
                num1 = pl1[k].num;
                expo1 = j;
            }
        }
        
        //procura no polinômio 2 
        for (k = 0; k < termos2; k++)
        {
            if (pl2[k].expo == j)
            {
                num2 = pl2[k].num;
                expo2 = j;
            }
        }
        
        //saída  
        if (expo2 == expo1 && expo2 == j)
        {
            if (num1 + num2 > 0) printf("+");
            if (num1 + num2 != 0)
            {
            printf("%.2lf", num1 + num2);
            if (j > 0) printf("X^%d", j);
            }
        }
        else if (expo2 > expo1 && expo2 == j)
        {
            if (num2 > 0) printf("+");
            if (num2 != 0)
            { 
            printf("%.2lf", num2);
            if (j > 0) printf("X^%d", j);
            }
                
        }
        else if (expo1 > expo2 && expo1 ==j)
        {
            if (num1 > 0) printf("+");
            if (num1 != 0)
            {
                printf("%.2lf", num1);
                if (j > 0) printf("X^%d", j);
            }
                
        }
    }
    printf("\n");
}

//função subração
void sub(int termos1, int termos2, polinom pl1[], polinom pl2[])
{
    // declaração de variáveis
    int i, maior, j, k;
    double num1, num2;
    int expo1, expo2;
    polinom soma[termos1 + termos2];
    
    //busca do maior expoente 
    maior = (pl1[0].expo > pl2[0].expo) ? pl1[0].expo : pl2[0].expo;
    
    //procura dos elementos de acordo com o expoente e operação 
    for (j = maior; j >= 0; j--)
    {
        //limpeza dos valores já estabelecidos (necessário assim como na soma)
        expo1 = -1;
        expo2 = -1;
        
        //procura no polinômio 1 
        for (k = 0; k < termos1; k++)
        {
            if (pl1[k].expo == j)
            {
                num1 = pl1[k].num;
                expo1 = j;
            }
        }
       
        //procura no polinômio 2 
        for (k = 0; k < termos2; k++)
        {
            if (pl2[k].expo == j)
            {
                num2 = pl2[k].num * -1;
                expo2 = j;
            }
        }
       
        //saída 
        if (expo2 == expo1 && expo2 == j)
        {
            if (num1 + num2 > 0) printf("+");
            if (num1 + num2 != 0)
            {
                printf("%.2lf", num1 + num2);
                if (j > 0) printf("X^%d", j);
            }
        }
        else if (expo2 > expo1 && expo2 == j)
        {
            if (num2 > 0) printf("+");
            if (num2 != 0)
            {
                printf("%.2lf", num2);
                if (j > 0) printf("X^%d", j);
            }
        }
        else if (expo1 > expo2 && expo1 ==j)
        {
            if (num1 > 0) printf("+");
            if (num1 != 0)
            {
                printf("%.2lf", num1);
                if (j > 0) printf("X^%d", j);
            }
        }
    } 
    printf("\n");
}