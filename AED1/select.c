#include <stdio.h>

void troca(int *m, int *mi)
{
    int temp = *m;
    *m = *mi;
    *mi = temp;
}

void selectionSort(int v[], int tam1)
{

    int i, j, key;

    for (i = 0; i < tam1 - 1; i++)
    {

        key = i;

        for (j = i + 1; j < tam1; j++)
        {

            if (v[j] < v[key])
            {
                key = j;
            }
        }
        if (key != i)
        {
            troca(&v[key], &v[i]);
        }
    }
}
void printArray(int v[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", v[i]);
    printf("\n");
}

int main()
{

    int tam, i, j;

    printf("Entre com o tamanho do vetor\n");

    scanf("%d", &tam);

    int v[tam];
    printf("Entre com os elementos do vetor\n");
    for (i = 0; i < tam; i++)
    {
        scanf("%d", &v[i]);
    }
    selectionSort(v, tam);

    printf("Array ordenado\n");
    printArray(v, tam);
    return 0;
}
