#include <stdio.h>

//constantes que serão usadas no programa
enum dados {PROV = 8, LIST = 5, PRESEN = 96, QMAX = 100, NMIN = 6};

int main(void)
{
    //declaração das variáveis
    unsigned matri[QMAX], pres[QMAX], i, j = 0;
    double prov[PROV], list[LIST], trab, res[QMAX], aux = 0;

    //primeira leitura da matrícula, notas e presença e também os primeiros cálculos
    scanf("%u", &matri[j]);
    for (i = 0; i < PROV; i++)
    {
        scanf("%lf", &prov[i]);
        aux += prov[i];
    }
    res[j] = (aux / PROV) * 0.7;
    aux = 0;

    for(i = 0; i < LIST; i++)
    {
        scanf("%lf", &list[i]);
        aux += list[i];
    }
    res[j] += (aux / LIST) * 0.15;
    aux = 0;

    scanf("%lf", &trab);
    res[j] +=(0.15 * trab);
    scanf("%u", &pres[j]);

    // loop dos cálculos e leituras restantes
    while (matri[j] != -1 && prov[0] != -1 && list[0] != -1 && trab != -1 && pres[j] != -1)
    {
        j++;
        scanf("%u", &matri[j]);
        for (i = 0; i < PROV; i++)
        {
            scanf("%lf", &prov[i]);
            aux += prov[i];
        }
        res[j] = (aux / PROV) * 0.7;
        aux = 0;

        for(i = 0; i < LIST; i++)
        {
            scanf("%lf", &list[i]);
            aux += list[i];
        }
        res[j] += (aux / LIST) * 0.15;
        aux = 0;

        scanf("%lf", &trab);
        res[j] +=(0.15 * trab);
        scanf("%u", &pres[j]);

    }

    //saída de dados
    for (i = 0; i < j; i++)
    {
        printf("Matricula: %u, Nota Final: %.2lf, Situacao Final: ", matri[i], res[i]);
        if (res[i] >= NMIN && pres[i] >= PRESEN)
        {
            printf("APROVADO\n");
        }
        else if ( res[i] < NMIN && pres[i] >= PRESEN)
        {
            printf("REPROVADO POR NOTA\n");
        }
        else if ( res[i] >= NMIN && pres[i] < PRESEN)
        {
            printf("REPROVADO POR FREQUENCIA\n");
        }
        else
        {
            printf("REPROVADO POR NOTA E POR FREQUENCIA\n");
        }
    }
}