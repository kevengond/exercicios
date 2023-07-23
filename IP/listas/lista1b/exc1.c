#include <stdio.h>

#define MED 6
#define PRV 3

int main(void)
{
    //variaveis
    double n1, n2, n3, med;

    //entrada de dados
    scanf("%lf %lf %lf", &n1, &n2, &n3);
    
    //calculos
    med = (n1 + n2 + n3) / PRV;

    //Saida 
    printf("MEDIA = %.2lf\n", med);
    if (med >= MED)
    {
        printf("APROVADO\n");
    }
    else
    {
        printf("REPROVADO\n");
    }

    return 0;
}
