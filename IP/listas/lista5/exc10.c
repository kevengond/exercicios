#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


//constantes com as quantidades máximas permitidas para os casos de testes
//e a quantidade de frações
enum {QTMAX = 30, QBUFF = 100};

//função para pesquisa das frações equivalentes
void pesq(int qfrac, int *frac);

int main(void)
{
    //declaração de variáveis
    int qtest, i, k, cont;
    char buff[QBUFF];
    int buff_n[QBUFF];

    //leitura dos casos de teste e teste de validade
    scanf("%d", &qtest);
    if (qtest > QTMAX) return 1;
    getchar();

    //leitura das frações e pesquisa
    for (i = 0; i < qtest; i++)
    {
        scanf("%[^\n]", buff);
        getchar();

        cont = 0;
        k = 0;
        int ant_b = 0;
        int ant_e = 0;
        int aux = 0, t = 0;
        while (buff[k])
        {
            aux = 0;
            if (buff[k] == '/')
            {
                for (t = ant_e; t < k; t++)
                {
                    aux += (buff[t] - 48) * (int)pow(10,k - t -1);
                }
                buff_n[cont] = aux;
                ant_b = k + 1;
                cont++;
            }
            else if (buff[k] == ' ')
            {
                for (t = ant_b; t < k; t++)
                {
                    aux += (buff[t] - 48) * (int)pow(10,k - t -1);
                }
                buff_n[cont] = aux;
                ant_e = k + 1;
                cont++;
            }
            k++;
        }
                for (t = ant_b; t < k; t++)
                {
                    aux += (buff[t] - 48) * (int)pow(10,k - t -1);
                }
                buff_n[cont] = aux;
                ant_e = k + 1;
                cont++;

        //alocação de memória e passagem dos elementos
        int *frac = (int *) malloc(sizeof(int) * cont);
        for (k = 0; k < cont; k++) frac[k] = buff_n[k];

        //chamada da função para a pesquisa das frações equivalentes
        pesq(cont, frac);

        free(frac);
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
    for (i = 0; i < qfrac - 1; i+=2)
    {
        for (j = i; j < qfrac - 1; j+=2)
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