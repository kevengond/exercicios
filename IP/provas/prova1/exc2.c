#include <stdio.h>
 
//fiz utilizando bubble sort
 
int main(void)
{
    double n[5], aux;
    int i, j;
    
    for (i = 0; i < 5; i++)
    {
        scanf("%lf", &n[i]);
    }
    
    for (i = 0; i < 5 - 1; i++)
    {
        for (j = 0; j < 5 - 1 - i; j++)
        {
            if (n[j] > n[j + 1])
            {
                aux = n[j];
                n[j] = n[j + 1];
                n[j + 1] = aux;
            }
        }
    }
    
    printf("%.2lf, %.2lf, %.2lf, %.2lf, %.2lf\n", n[0], n[1], n[2], n[3], n[4]);
    
    
    return 0;
}
