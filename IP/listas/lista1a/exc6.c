#include <stdio.h>

#define HOR 3600
#define MIN 60

int main(void)
{
    int hor, min, seg;
    
    scanf("%d %d %d", &hor, &min, &seg);

    printf("O TEMPO EM SEGUNDOS E = %d\n", (hor * HOR) + (min * MIN) + seg);

    return 0;
}

