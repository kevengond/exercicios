#include <stdio.h>

int main(void)
{
    // declaração das variáveis
    int nata, mortos = 0, masc = 0, fem = 0, m24 = 0, id;
    unsigned sexo;

    // leitura da natalidade
    scanf("%d", &nata);

    // loop com os devidos cálculos
    scanf("%u", &sexo);
    while (sexo != 2)
    {
        if (sexo) fem++;
        else masc++;
        mortos++;

        scanf("%d", &id);
        if (id <= 24) m24++;

        scanf("%u", &sexo);
    }

    // saída com os devidos cálculos
    printf("PORCENTAGEM DE MORTOS = %.2lf\n", ((float) mortos / nata) * 100);
    printf("PORCENTAGEM DE MASCULINOS MORTOS = %.2lf\n", ((float) masc / nata) * 100);
    printf("PORCENTAGEM DE FEMININOS MORTOS = %.2lf\n", ((float) fem / nata) * 100);
    printf("PORCENTAGEM DE MORTOS COM ATE 24 MESES DE VIDA = %.2lf\n", ((float) m24 / nata) * 100);

}
