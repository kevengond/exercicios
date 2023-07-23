#include <stdio.h>

int main(void)
{
    //declaração de variáveis
    int an = 0, a1, r, n_ele, i;

    //leitura dos dados
    scanf("%d %d %d", &a1, &r, &n_ele);

    //soma da pa
    for (i = 0; i < n_ele; i++)
    {
       an += (a1 + (r * i));
    }

    //saída do resultado da soma
    printf("%d\n", an);

    return 0;
}
