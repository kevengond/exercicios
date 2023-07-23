#include <stdio.h>

void potmat(int ord, int k, double mat[ord][ord], double maux[ord][ord], double mat2[ord][ord]);

int main(void)
{
    //declaração de variáveis
    int ord, i, j, k;
    //leitura da ordem da matriz e da potência desejada
    scanf("%d", &ord);
    if (ord <= 0 || ord > 10) return 1;
    scanf("%d", &k);
    if (k <= 0) return 2;

    // declaração das matrizes que irão contem os valores iniciais,
    // os valores após as operações e de uma matriz auxiliar
    double mat[ord][ord], maux[ord][ord], mat2[ord][ord];

    //leitura dos valores
    for (i = 0; i < ord; i++)
    {
        for (j = 0;j < ord; j++)
        {
            scanf("%lf", &mat[i][j]);
            mat2[i][j] = mat[i][j];
        }
    }

    potmat(ord, k, mat, maux, mat2);

    return 0;
}

void potmat(int ord, int k, double mat[ord][ord], double maux[ord][ord], double mat2[ord][ord])
{
    int l, ciclos, i, j;
           double    aux;

    //cálculos da potência de matriz
    for (ciclos = 2; ciclos <= k; ciclos++)
        //Se ainda houver operações de múltiplicação a serem feitas
    {
        //cálculos e passagem para uma matriz auxiliar
        for (i = 0; i < ord; i++)
        {
            for (l = 0; l < ord; l++)
            {
                aux = 0;
                for (j = 0; j < ord; j++)
                {
                    aux += mat[i][j] * mat2[j][l];
                }
                maux[i][l] = aux;
            }
        }

        //aqui ocorre a passagem para a matriz
        for (i = 0; i < ord; i++)
        {
            for (j = 0; j < ord; j++)
            {
                mat2[i][j] = maux[i][j];
            }
        }
    }

    //saída
    for (i = 0; i < ord; i++)
    {
        for (j = 0; j < ord; j++)
        {
            printf("%.3lf ", mat2[i][j]);
        }
        printf("\n");
    }
}