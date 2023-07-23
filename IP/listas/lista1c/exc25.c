#include <stdio.h>

void imp(int num) // função para saída de n ao cubo
{
    //declaração de variáveis
    int i, j, cont, k = 1;
    // saída dos ímpares consecutivos
    for (i = 1; i <= num; i++)
    {
        cont = 0;
        printf("%d*%d*%d = ", i, i, i);
        while (cont < (i * i * i))
        {
            j = 2 * k - 1;
            cont += j;
            printf("%d", j);
            k++;
            if (cont == (i * i * i)) break;
            printf("+");

        }
        printf("\n");
    }
}
// função main para a leitura do número
int main(void)
{
    int num;
    // teste para número inválido
    scanf("%d", &num);
    if (num <= 0) return 1;

    imp(num);

}
