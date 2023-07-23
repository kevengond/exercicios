#include <stdio.h>

int main(void)
{
    int i, j;
    double n[3], aux;
    
    for (i = 0; i < 3; i++)
        scanf("%lf", &n[i]);
        
    for (i = 0; i < 3 - 1; i++)
    {
        for (j = 0; j < 3 - 1 - i; j++)
        {
            if (n[j + 1] < n[j])
            {
                aux = n[j];
                n[j] = n[j + 1];
                n[j + 1] = aux;
            }
        }
    }
    
    printf("%.2lf, %.2lf, %.2lf\n", n[0], n[1], n[2]);
    
    return 0;
}