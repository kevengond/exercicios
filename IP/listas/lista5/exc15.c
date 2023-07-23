#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//declaração de um tipo para as iterações
typedef struct itr
{
    int likes;
    int ret;
    int men;
}itera;

int main(void)
{
    //declaração de variáveis
    int ord, quant, i, j, usr1, usr2;
    int quant_lk, quant_rt, quant_men, fim;

    //leitura da ordem da matriz e a quantidade de usuários
    scanf("%d %d", &ord, &quant);

    //declaração da matriz de ponteiros de iterações
    itera *vet[ord][ord];

    //apontar para NULL
    for (i = 0; i < ord; i++)
    {
        for (j = 0; j < ord; j++)
        {
            vet[i][j] = NULL;
        }
    }

    for (i = 0; i < quant; i++)
    {
        // leitura do usuário 1 e asuario 2
        scanf("%d %d", &usr1, &usr2);

        //alocação de memória e teste
        vet[usr1][usr2] = (itera *) malloc(sizeof(itera));
        if (!vet[usr1][usr2]) exit(1);

        //leitura dos valores
        scanf("%d %d %d", &vet[usr1][usr2]->likes, &vet[usr1][usr2]->ret, &vet[usr1][usr2]->men);
    }

    //cálculos e saída
    for (i = 0; i < ord; i++)
    {
        fim = 0;
        quant_lk = 0;
        quant_rt = 0;
        quant_men = 0;

        for (j = 0; j < ord; j++)
        {
            if (vet[i][j] != NULL)
            {
            quant_lk += vet[i][j]->likes;
            quant_rt += vet[i][j]->ret;
            quant_men += vet[i][j]->men;
            fim = 1;
            }
        if (vet[i][j] != NULL) free(vet[i][j]);
        }

        if (fim) printf("Usuario %d - ",i);
        if (quant_lk)printf("num. likes: %d, ", quant_lk);
        if (quant_rt)printf("num. retweets: %d e ", quant_rt);
        if (quant_men)printf("num. mencoes: %d\n", quant_men);

    }

}