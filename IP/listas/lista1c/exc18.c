#include <stdio.h>

int main(void)
{
    // declaração de variáveis
    double valor_merc, valor_ini, valor_final, pre_v, cust, luc, melhor_v = 0, melhor_l = 0;
    int ing, melhor_i = 0;

    // leitura de dados e teste par números inválidos
    scanf("%lf %lf %lf", &valor_merc, &valor_ini, &valor_final);
    if (valor_ini >= valor_final)
    {
        printf("INTERVALO INVALIDO.\n");
        return 1;
    }
    // cálculos e saidas iniciais
    pre_v = valor_ini;
    while (pre_v <= valor_final)
    {
        // caso o valor de mercado seja maior que o valor variável
        if (pre_v < valor_merc)
        {
            ing = 120 + (25 * ((valor_merc - pre_v) / 0.5));
            cust = 200 + 0.05 * ing;
            luc = (ing * pre_v) - cust;

            if (luc > melhor_l)
            {
                melhor_l = luc;
                melhor_i = ing;
                melhor_v = pre_v;
            }

            printf("V: %.2lf, N: %d, L: %.2lf\n", pre_v, ing, luc);
        }
        else if (pre_v == valor_merc) //caso o valor de mercado seja igual ao valor variável
        {
            ing = 120;
            cust = 200 + 0.05 * ing;
            luc = (ing * pre_v) - cust;

            if (luc > melhor_l)
            {
                melhor_l = luc;
                melhor_i = ing;
                melhor_v = pre_v;
            }

            printf("V: %.2lf, N: %d, L: %.2lf\n", pre_v, ing, luc);
        }
        else //caso o valor de mercado seja menor que o valor variável
        {
            ing = 120 - (30 * ((pre_v - valor_merc) / 0.5));
            cust = 200 + 0.05 * ing;
            luc = (ing * pre_v) - cust;

            if (luc > melhor_l)
            {
                melhor_l = luc;
                melhor_i = ing;
                melhor_v = pre_v;
            }

            printf("V: %.2lf, N: %d, L: %.2lf\n", pre_v, ing, luc);
        }
        pre_v++;
    }
    // saida resumo
    printf("Melhor valor final: %.2lf\n", melhor_v);
    printf("Lucro: %.2lf\n", melhor_l);
    printf("Numero de ingressos: %d\n", melhor_i);

    return 0;
}