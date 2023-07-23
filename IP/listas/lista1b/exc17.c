#include <stdio.h>

enum {QUANT = 4};

int main(void)
{
    int i, j;
    double n[QUANT], aux;
    
    for (i = 0; i < QUANT; i++)
    {
        scanf("%lf", &n[i]);
    }
    
    for (i = 0; i < QUANT - 1; i++)
    {
       for (j = 0 ; j < QUANT - i - 1; j++)
       {
           if (n[j] > n[j +  1])
           {
               aux = n[j];
               n[j] = n[j + 1];
               n[j + 1] = aux;
           }
       }
    }
    
    for (i = 0; i < QUANT; i++)
    {
        printf("%.2lf", n[i]);
        if (i < QUANT - 1)
        {
            printf(", ");
        }
    }
    printf("\n");
    
    return 0;
}