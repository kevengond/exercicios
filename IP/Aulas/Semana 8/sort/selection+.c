// esse é a minha implementação do selection sort
#include <stdio.h>

#define TAM 5

void troca(int *v1, int *v2)
{
    int aux = *v1;
    *v1 = *v2;
    *v2 = aux;
}

int selection(int *arr, int tam)
{
    int idx_min, cont = 0;
    short int vt = 0;

    for (int i = 0; i < tam - 1; i++)
    {
        idx_min = i;
        for (int j = i + 1; j < tam; j++)
        {
           if (arr[idx_min] > arr[j]) idx_min = j;
           cont++;
           vt = 1;
        }
        if (vt) //aqui se não houver um número maior, não ocorre troca
        {
            troca( &arr[i], &arr[idx_min]);
            vt = 0;
        }
    }
    return cont;
}

int main(void)
{
    int arr[TAM];

    for(int i = 0; i < TAM; i++) scanf("%d", &arr[i]);

    int cont = selection(arr, TAM);

    for (int i = 0; i < TAM; i++) printf("%d ", arr[i]);
    printf("\n");
    printf("quantidade de ciclos: %d\n", cont);
}
