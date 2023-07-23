#include <stdio.h>

int main(void)
{
    int horas, i = 0;
    double price = 0;

    scanf("%d", &horas);
   
    for(i = 0; i < 3; i++)
    {
        price += 5;
        horas--;
    }

    price += (horas / 3) * 10;
    
    printf("O VALOR A PAGAR E = %.2lf\n", price);
    
    return 0;
}

