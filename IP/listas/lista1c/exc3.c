#include <stdio.h>

int main(void)
{
    //declaração de variáveis
   int num = 5, i;
    
    //letura do número 
   while (num <= 5 || num >= 2000) scanf("%d", &num);
    
    //saída do valor ao quadrado
   for (i = 2; i <= num; i += 2)
   {
        printf("%d^2 = %d\n",i, i * i);
   }

    return 0;
}


