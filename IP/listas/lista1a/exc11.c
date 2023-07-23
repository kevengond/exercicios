#include <stdio.h>
#include <math.h>

int main(void)
{
    int num, aux1, aux2, aux3 = 0, i;

    scanf("%d", &num);

    if (num == 0 || !(num % 10) || !(num % 100))
        return 1;

    aux2 = num;

    for (i = 0; i <= 2; i++)
    {
        aux1 = aux2 / pow(10, 2 - i);
        aux2 %= (int) pow(10, 2 - i);
        aux3 += aux1 * pow(10, i);
    }

    printf("%d\n", aux3);

    return 0;
}
