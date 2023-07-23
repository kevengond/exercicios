#include <stdio.h>
 
int main(void)
{ 
    unsigned matri, htrab, filhos;
    double sal_hr, sal_fam;
    
    scanf("%u %u %lf %u %lf", &matri, &htrab, &sal_hr, &filhos, &sal_fam);
    
    printf("MATRICULA DO FUNCIONARIO = %u\n", matri);
    
    printf("SALARIO TOTAL = %.2lf\n", (htrab * sal_hr) + (sal_fam * filhos));
    
    printf("FILHOS = %d\n", filhos);
    
    
    
    return 0;
}
