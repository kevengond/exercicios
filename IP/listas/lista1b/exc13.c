#include <stdio.h>

int main(void)
{
    unsigned cc, dr, rt, cont = 0;
    
    scanf("%u %u %u", &cc, &dr, &rt);
    
    if (cc < 7)
    {
        cont++;
    }
    if (  cont == 1 && dr > 50)
     {
         cont++;
     }
    if (cont == 2  && rt > 80000)
    {
        cont++;
    }   
    
    if (cont == 1)
    {
        printf("ACO DE GRAU = 8\n");
    }
    else if (cont == 2)
    {
        printf("ACO DE GRAU = 9\n");   
    }
    else if (cont == 3)
    {
        printf("ACO DE GRAU = 10\n");
    }
    else
    {
        printf("ACO DE GRAU = 7\n");
    } 
    
    return 0;
}