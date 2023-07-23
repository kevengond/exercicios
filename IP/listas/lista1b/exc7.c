#include <stdio.h>

int main(void)
{
    int x, y;

    scanf("%d", &x);

    if (x < 1)
        printf("Y = %d\n", x);
    else if (x == 10)
        printf("Y = %d\n", 0);
    else 
        printf("Y = %d\n", x * x); 

    return 0;
}

