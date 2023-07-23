#include <stdio.h>

#define RES 'R'
#define COM 'C'
#define IND 'I'

int main(void)
{
    unsigned conta_cl;
    double cons, cust;
    char cl;

    scanf("%u %lf %c", &conta_cl, &cons, &cl);

    printf("CONTA = %u\n", conta_cl);

    if (cl == RES)
    {
        cust = cons * 0.05 + 5;
        printf("VALOR DA CONTA = %.2lf\n", cust);
    }
    else if (cl == COM)
    {
        cust = (cons - 80) * 0.25 + 500;
        printf("VALOR DA CONTA = %.2lf\n", cust);
    }
    else if (cl == IND)
    {
        cust = (cons - 100) * 0.04 + 800;
        printf("VALOR DA CONTA = %.2lf\n", cust);
    }

    return 0;
}

