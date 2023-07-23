#include <stdio.h>

//constantes com as quantidades máximas permitidas para os casos de testes
//e a quantidade de frações
enum {QTMAX = 30, QFMAX = 50};

//função para pesquisa das frações equivalentes
void pesq(int qfrac, int *frac);

int main(void)
{
    //declaração de variáveis
    int qtest, qfrac, i, j;

    //leitura dos casos de teste e teste de validade
    scanf("%d", &qtest);
    if (qtest > QTMAX) return 1;

    //leitura das frações e pesquisa
    for (i = 0; i < qtest; i++)
    {
        //leitura da quantidade de frações em cada caso de teste e teste
        //de validade
        scanf("%d", &qfrac);
        if (qfrac > QFMAX) return 1;

        //declaração de um vetor de frações
        int frac[qfrac * 2];

        //leitura das frações
        for (j = 0; j < qfrac * 2; j+=2)
        {
           scanf("%d/%d", &frac[j], &frac[j+1]);
        }

        //chamada da função para a pesquisa das frações equivalentes
        pesq(qfrac, frac);
    }
}

// função para o encontro das frações equivalentes
void pesq(int qfrac, int *frac)
{
    //declarações de variáveis
    static int test = 1;
    int i, j, cont = 0;

    //saída do caso
    printf("Caso de teste %d\n", test);

    //pesquisa e saída se houver equivalentes
    for (i = 0; i < qfrac * 2; i+=2)
    {
        for (j = i; j < qfrac * 2; j+=2)
        {
            if (((double)frac[i] / frac[i+1]) == ((double)frac[j] / frac[j+1]) && i != j)
            {
                printf("%d/%d equivalente a %d/%d\n", frac[i], frac[i+1], frac[j], frac[j+1]);
                cont++;
            }
        }
    }
    //caso não tenha equivalentes
    if (!cont) printf("Nao ha fracoes equivalentes na sequencia\n");
    test++;
}