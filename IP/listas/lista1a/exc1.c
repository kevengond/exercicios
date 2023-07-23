#include <stdio.h>


int main(void)
{
    double sal_min, consumo, cust_kw;

    scanf("%lf %lf", &sal_min, &consumo);

    cust_kw =  0.007 * sal_min;

    printf("Custo por kW: R$ %.2lf \n", cust_kw);
    printf("Custo do consumo: R$ %.2lf \n", cust_kw * consumo);
    printf("Custo com desconto: R$ %.2lf \n", (cust_kw * consumo) * 0.9);

    return 0;
}
