#include <stdio.h>

int main(void)
{
    int n1, n2, n3, aux, i;
    char p[3];
    
    scanf(" %d %d %d", &n1, &n2, &n3);
    scanf(" %c %c %c", &p[0], &p[1], &p[2]);
    
    if (n1 > n2)
    {
        aux = n1;
        n1 = n2;
        n2 = aux;
    }
    if (n2 > n3)
    {
        aux = n2;
        n2 = n3;
        n3 = aux;
    }
    if (n1 > n2)
    {
        aux = n1;
        n1 = n2;
        n2 = aux;
    }
    
    for (i = 0; i < 3; i++)
    {
        if (p[i] == 'A')
        {
            printf("%d ", n1);
        }
        else if (p[i] == 'B')
        {
            printf("%d ", n2);
        }
        else 
        {
            printf("%d ", n3);
        }
    }
    printf("\n");
    
    return 0;
}