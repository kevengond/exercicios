// Esta implementação é otimizada para parar quando toda a cadeia estiver ordenada

#include <stdio.h>

#define TAM 5

void troca (int *v1, int *v2)
{
    int aux = *v1;
    *v1 = *v2;
    *v2 = aux;
}

int bubble(int *arr, int tam)
{
    int aux, cont = 0;
    for (int i = 1; i < tam; i++)
    {
        int ok = 0;
        for (int j = 0; j < tam - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                troca(&arr[j], &arr[j + 1]);
                ok = 1;
            }
            cont++;
        }
        if (ok == 0) break;
    }
    return (cont);
}
int main(void)
{
    int arr[TAM], cont;

    for (int i = 0; i < TAM; i++)
    {
        scanf("%d", &arr[i]);
    }

    cont = bubble(arr, TAM);

    for (int i = 0; i < TAM; i++) printf("%d ", arr[i]);
    printf("\n");
    printf("quantidade de ciclos: %d\n", cont);
}
