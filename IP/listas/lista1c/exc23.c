#include <stdio.h>

int luc10(double p_com, double p_ven)//função para retorno do lucro menor de 10%
{
    int quant = 0;
    double luc = p_ven - p_com;

    if (luc < p_com * 0.1) quant++;

    return quant;
}

int luc12(double p_com, double p_ven)//função para retorno do lucor ou igual 10% ou menor igual 20%
{
    int quant = 0;
    double luc = p_ven - p_com;

    if (luc >= p_com * 0.1 && luc <= p_com * 0.2) quant++;

    return quant;
}

int luc20(double p_com, double p_ven)//função para retorno do lucro maior de 20%
{
    int quant = 0;
    double luc = p_ven - p_com;

    if (luc > p_com * 0.2) quant++;

    return quant;
}

int mluc(unsigned long cod, double luc)//função para retorno de cod de maior lucro
{
    static double maior = 0;
    static unsigned long mcod = 0;

    if (luc > maior)
    {
        mcod = cod;
        maior = luc;
    }

    return mcod;
}

int mven(unsigned long cod, double nven)//função para retorno do código de maior venda
{
    static int mven = 0;
    static unsigned long mcod = 0;

    if (nven > mven)
    {
        mven = nven;
        mcod = cod;
    }

    return mcod;
}

int main(void)
{
    // declaração das variáveis
    unsigned long cod_mer, cod_mluc, cod_mven;
    double pre_com, pre_ven, t_com = 0, t_ven = 0;
    int nven, luc_10 = 0, luc_1020 = 0, luc_20 = 0;

    // leitura e cálculos até o final do arquivo
    while (scanf("%lu %lf %lf %d", &cod_mer, &pre_com, &pre_ven, &nven) != EOF)
    {
        luc_10 += luc10(pre_com, pre_ven);
        luc_1020 += luc12(pre_com, pre_ven);
        luc_20 += luc20(pre_com, pre_ven);
        cod_mluc = mluc(cod_mer, pre_ven - pre_com);
        cod_mven = mven(cod_mer, nven);
        t_com += pre_com * nven;
        t_ven += pre_ven * nven;

    }
    // saídas
    printf("Quantidade de mercadorias que geraram lucro menor que 10%%: %d\n", luc_10);
    printf("Quantidade de mercadorias que geraram lucro maior ou igual a 10%% e menor ou igual a 20%%: %d\n", luc_1020);
    printf("Quantidade de mercadorias que geraram lucro maior do que 20%%: %d\n", luc_20);
    printf("Codigo da mercadoria que gerou maior lucro: %lu\n", cod_mluc);
    printf("Codigo da mercadoria mais vendida: %lu\n", cod_mven);
    printf("Valor total de compras: %.2lf, valor total de vendas: %.2lf e percentual de lucro total: %.2lf%%\n", t_com, t_ven, ((t_ven - t_com) / t_com) * 100);
    return 0;
}

