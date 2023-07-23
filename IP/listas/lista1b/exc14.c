#include <stdio.h>

int main(void)
{
    int matri, dep;
    double sal_min, sal_fun, tax, liq;
    
    scanf("%d %lf %d  %lf %lf", &matri, &sal_min, &dep, &sal_fun, &tax);
    
    printf("MATRICULA = %d\n", matri);
    
    printf("IMPOSTO BRUTO = ");
    
    if (sal_fun > (sal_min * 12))
    {
        printf("%.2lf\n", sal_fun * 0.2);
        liq = (sal_fun * 0.2) - (dep * 300);
    }
    else if (sal_fun > (sal_min * 5))
    {
        printf("%.2lf\n", sal_fun * 0.08);
        liq = (sal_fun * 0.08) - (300 * dep);
    }
    else
    {
        printf("0.00\n");
        liq = 0 - (300 * dep);
    }
    
    printf("IMPOSTO LIQUIDO = %.2lf\n", liq);
    
    printf("RESULTADO = %.2lf\n", liq - (sal_fun * (tax / 100)));
    
    if ((liq - (sal_fun * (tax / 100)) < 0))
    {
    printf("IMPOSTO A RECEBER\n");
    }
    else if ((liq - (sal_fun * (tax / 100)) > 0))
    {
        printf("IMPOSTO A PAGAR\n");
    }
    else
    {
        printf("IMPOSTO QUITADO\n");
    }
    
    return 0;
}