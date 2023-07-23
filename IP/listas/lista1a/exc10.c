#include <stdio.h>
#include <math.h> 

int main(void)
{
    int num, aux1, aux2, aux3, i;

    scanf("%d", &num);

    aux2 = num;

    for (i = 2; i >= 0; i--)
    {
        aux1 = aux2 / pow(10, i);
        aux2 %= (int) pow(10, i);
        if (i == 2)
            aux3 = aux1;
        else if (i == 1)
            aux3 += aux1 * 3;
        else
            aux3 += aux1 * 5;
    }

    printf("O NOVO NUMERO E = %d\n", (num * 10 + aux3 % 7));

    return 0;
}
    
