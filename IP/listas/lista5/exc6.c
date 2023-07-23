#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//constante com a quantidade máxima de caracteres no buffer
enum {MAX = 200};

//função para a limpeza da string
void clear(char *str)
{
    int c = strlen(str);
    if (str[c - 1] == '\n') str[c - 1] = 0;
}

int main(void)
{
    //declaração de constantes
    char buff[MAX];
    int quant, i;

    //leitura da quantidade de casos de teste
    scanf("%d", &quant);
    getchar();

    for (i = 0; i < quant; i++)
    {
        //leitura dos nomes no buffer e limpeza do \n
        fgets(buff, MAX, stdin);
        clear(buff);

        //alocação de memória
        char *str = (char *) malloc(sizeof(buff));
        if (!str) return 1;

        //cópia da string do buffer para a área alocada
        strcpy(str, buff);

        //saída
        printf("%s\n", str);

        //liberação da memória alocada
        free(str);
    }

}