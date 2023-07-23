#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//declaração de um tipo de estrutura de alunos
typedef struct alu
{
    char *nome;
    int matri;
    int dia;
    int mes;
    int ano;
} tab;

//funções para a ordenção dos alunos e a comparação das idades
void bubble(tab alu[], int quant);
int ComparaDataNasc(tab alu1, tab alu2);

int main(void)
{
    //delcaração de variáveis
    int quant, i, j;
    char buff[200];

    //leitura da quantidade de alunos
    scanf("%d", &quant);
    if (quant < 1 || quant > 30) return 1;

    //delclaração de um vetor de alunos
    tab alu[quant];

   //leitura dos dados dos alunos
    for (i = 0; i < quant; i++)
    {
        scanf("%d %d %d %d", &alu[i].matri, &alu[i].dia, &alu[i].mes, &alu[i].ano);
        getchar();
        scanf("%[^\n]", buff);
        getchar();
        alu[i].nome = (char *) malloc(sizeof(buff));
        strcpy(alu[i].nome, buff);

    }

    //chamada da função bubble sort para a ordenação
    bubble(alu, quant);

    //saída e liberação de memória
    for (i = 0; i < quant; i++)
    {
        printf("Matric.: %d Nome: %s Data Nasc: %d/%d/%d \n", alu[i].matri, alu[i].nome, alu[i].dia, alu[i].mes, alu[i].ano);
        free(alu[i].nome);
    }
}

//bubble sort para a ordenação com o diferencial de que a troca dos valores
//ocorre dentro da função e que a comparação entre os valores se da pela função
//que está sendo pedida pelo enunciado
void bubble(tab alu[], int quant)
{
   int i, j;
   tab aux;

   for (i = 1; i < quant; i++)
   {
       for (j = 0; j < quant - i; j++)
       {
           if (ComparaDataNasc(alu[j], alu[j+1]))
           {
               aux = alu[j];
               alu[j] = alu[j+1];
               alu[j+1] = aux;
           }
       }
   }
}

//fução pedida para a comparação das idades dos alunos
int ComparaDataNasc(tab alu1, tab alu2)
{
   if (alu1.ano > alu2.ano) return 0;
   else if (alu1.ano == alu2.ano && alu1.mes > alu2.mes) return 0;
   else if (alu1.ano == alu2.ano && alu1.mes == alu2.mes && alu1.dia > alu2.dia) return 0;
   return 1;
}