#include <stdio.h>

int main(void)
{
    //declaração de variáveis
    double par = 0, imp = 0, res_p = 0, res_i = 0;
    int num, cont_p = 0, cont_i = 0;

    // leitura inicial e teste se for igual a 0
    scanf("%d", &num);
    if(num == 0)
    {
        return 1;
    }

    // verificação e somatória dos ímpares e pares
    while (num != 0)
    {

        if (!((int)num % 2))
        {
            par += num;
            cont_p++;
        }
        else
        {
            imp += num;
            cont_i++;
        }
        scanf("%d", &num);
    }

    // verifição se houve números ímpares e pares e cálculos dos resultados
    if (imp == 0) res_i = 0;
    if (par == 0) res_p = 0;
    if (par != 0) res_p = par / cont_p;
    if (imp != 0) res_i = imp / cont_i;

    // saída
    printf("MEDIA PAR: %.2lf\n", res_p);
    printf("MEDIA IMPAR: %.2lf\n", res_i);

    return 0;
}
