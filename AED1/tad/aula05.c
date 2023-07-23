/*************************************************************************************/
/*                               conjunto.h                                           */
/*************************************************************************************/
#include <stdio.h>
#include <stdlib.h>

typedef struct Conjunto Conjunto;

int criaConjunto(struct Conjunto **c);

void quicksort(int *number, int first, int last);

void organizaConjunto(struct Conjunto **c);

int valido(struct Conjunto **c);

int conjuntoVazio(struct Conjunto **c);

int insereElementoConjunto(int elemento, struct Conjunto **c);

int excluirElementoConjunto(int elemento, struct Conjunto **c);

int tamanhoConjunto(struct Conjunto **c);

int maior(int elemento, struct Conjunto **c); // determinar a quantidade de elementos do conjunto C que s�o maiores que x.
// O valor 0 (zero) indica que todos os elementos de C s�o maiores que x.

int menor(int elemento, struct Conjunto **c); // determinar a quantidade de elementos do conjunto C que s�o menores que x.
// O valor 0 (zero) indica que todos os elementos de C s�o menores que x.

int pertenceConjunto(int elemento, struct Conjunto **c);

int conjuntosIdenticos(struct Conjunto **c1, struct Conjunto **c2);

int subconjunto(struct Conjunto **c1, struct Conjunto **c2); // comparar se c1 � subconjunto de c2

Conjunto complemento(struct Conjunto **c1, struct Conjunto **c2); // retornando um conjunto que cont�m os elementos de C2 que n�o pertencem a C1.
// Se todos os elementos de C2 est�o em C1, ent�o deve retornar um conjunto vazio.

Conjunto uniao(struct Conjunto **c1, struct Conjunto **c2);

Conjunto interseccao(struct Conjunto **c1, struct Conjunto **c2);

Conjunto diferenca(struct Conjunto **c1, struct Conjunto **c2); // retornando um conjunto que cont�m elementos de C1 que n�o pertencem a C2.
// Se todos os elementos de C1 est�o em C2 deve retornar um conjunto vazio.

Conjunto conjuntoPartes(struct Conjunto *c);

void mostraConjunto(struct Conjunto **c, int ordem); /*Mostrar, no dispositivo de sa�da, os elementos de C.
Se ordem for igual a CRESCENTE = 1, os elementos de C devem ser mostrados em ordem crescente.
Se ordem for igual a DECRESCENTE = 0, os elementos de C devem ser mostrados em ordem decrescente. */

int copiarConjunto(struct Conjunto **c1, struct Conjunto **c2);

int destroiConjunto(struct Conjunto **c);

void imprime_conjunto(Conjunto *c, int conjNum);

int mostra_numero_conjuntos(struct Conjunto **c, int numConj);

/*************************************************************************************/
/*                               conjunto.c                                          */
/*************************************************************************************/

//#include "conjunto.h"

typedef struct Conjunto
{
    unsigned int tamanhoConjunto;
    int *elementoConjunto;
};

int criaConjunto(struct Conjunto **c)
{

    if (valido(&(*c)))
    {
        return 0;
    }

    (*c) = NULL;
    (*c) = (Conjunto *)malloc(sizeof(Conjunto));

    if ((*c) != NULL)
    {
        (*c)->elementoConjunto = NULL;
        (*c)->elementoConjunto = (int *)malloc(sizeof(int));
        (*c)->elementoConjunto[0] = 0;

        if ((*c)->elementoConjunto != NULL)
        {
            (*c)->tamanhoConjunto = 0;

            return 1;
        }
    }

    return 0;
}

void quicksort(int *number, int first, int last)
{
    int i, j, pivot, temp;

    if (first < last)
    {
        pivot = first;
        i = first;
        j = last;
        while (i < j)
        {
            while (number[i] <= number[pivot] && i < last)
                i++;
            while (number[j] > number[pivot])
                j--;

            if (i < j)
            {
                temp = number[i];
                number[i] = number[j];
                number[j] = temp;
            }
        }

        temp = number[pivot];
        number[pivot] = number[j];
        number[j] = temp;
        quicksort(number, first, j - 1);
        quicksort(number, j + 1, last);
    }
}

void organizaConjunto(struct Conjunto **c)
{
    quicksort((*c)->elementoConjunto, 0, (*c)->tamanhoConjunto - 1);
}

int valido(struct Conjunto **c)
{
    if ((*c) != NULL)
    {
        return 1;
    }
    return 0;
}

int conjuntoVazio(struct Conjunto **c)
{
    if (valido(&(*c)))
    {
        if ((*c)->tamanhoConjunto == 0)
        {
            return 1;
        }
    }

    return 0;
}

int insereElementoConjunto(int elemento, struct Conjunto **c)
{
    int i;

    if ((*c) != NULL)
    {

        for (i = 0; i < (*c)->tamanhoConjunto; i++)
        {
            if (elemento == (*c)->elementoConjunto[i])
            {
                return 0;
            }
        }

        (*c)->tamanhoConjunto++;
        (*c)->elementoConjunto = (int *)realloc((*c)->elementoConjunto, (*c)->tamanhoConjunto * sizeof(int));

        if ((*c)->elementoConjunto != NULL)
        {
            (*c)->elementoConjunto[(*c)->tamanhoConjunto - 1] = elemento;
            return 1;
        }
        else
        {
            (*c)->tamanhoConjunto--;
            return 0;
        }
    }
    return 0;
}

int excluirElementoConjunto(int elemento, struct Conjunto **c)
{
    int i;

    if ((*c) != NULL)
    {
        for (i = 0; i < (*c)->tamanhoConjunto; i++)
        {
            if ((*c)->elementoConjunto[i] == elemento)
            {
                (*c)->tamanhoConjunto--;
                if ((*c)->tamanhoConjunto != i)
                {
                    (*c)->elementoConjunto[i] = (*c)->elementoConjunto[(*c)->tamanhoConjunto];
                }
                (*c)->elementoConjunto = (int *)realloc((*c)->elementoConjunto, (*c)->tamanhoConjunto * sizeof(int));
                return 1;
            }
        }
    }
    return 0;
}

int tamanhoConjunto(struct Conjunto **c)
{
    if (valido(&(*c)))
    {
        return (*c)->tamanhoConjunto;
    }
}

int maior(int elemento, struct Conjunto **c)
{
    int quant = 0;
    int i;

    if (valido(&(*c)))
    {
        for (i = 0; i < (*c)->tamanhoConjunto; i++)
        {
            if ((*c)->elementoConjunto[i] > elemento)
            {
                quant++;
            }
        }
        if (quant == (*c)->tamanhoConjunto)
        {
            return 0;
        }
    }
    return quant;
}

int menor(int elemento, struct Conjunto **c)
{
    int quant = 0;
    int i;

    if (valido(&(*c)))
    {
        for (i = 0; i < (*c)->tamanhoConjunto; i++)
        {
            if ((*c)->elementoConjunto[i] < elemento)
            {
                quant++;
            }
        }
        if (quant == (*c)->tamanhoConjunto)
        {
            return 0;
        }
    }
    return quant;
}

int pertenceConjunto(int elemento, struct Conjunto **c)
{
    int i;

    if (valido(&(*c)))
    {
        for (i = 0; i < (*c)->tamanhoConjunto; i++)
        {
            if ((*c)->elementoConjunto[i] == elemento)
            {
                return 1;
            }
        }
    }
    return 0;
}

int conjuntosIdenticos(struct Conjunto **c1, struct Conjunto **c2)
{
    int i;

    if (valido(&(*c1)) && valido(&(*c2)))
    {
        if ((*c1)->tamanhoConjunto == (*c2)->tamanhoConjunto)
        {
            organizaConjunto(&(*c1));
            organizaConjunto(&(*c2));

            for (i = 0; i < (*c1)->tamanhoConjunto; i++)
            {
                if ((*c1)->elementoConjunto[i] != (*c2)->elementoConjunto[i])
                {
                    return 0;
                }
            }
            return 1;
        }
    }

    return 0;
}

int subconjunto(struct Conjunto **c1, struct Conjunto **c2)
{
    int i;

    if (valido(&(*c1)) && valido(&(*c2)))
    {
        if ((*c1)->tamanhoConjunto > (*c2)->tamanhoConjunto)
        {
            return 0;
        }

        organizaConjunto(&(*c1));
        organizaConjunto(&(*c2));

        for (i = 0; i < (*c1)->tamanhoConjunto; i++)
        {
            if (!pertenceConjunto((*c1)->elementoConjunto[i], &(*c2)))
            {
                return 0;
            }
        }

        return 1;
    }
}

Conjunto complemento(struct Conjunto **c1, struct Conjunto **c2)
{
    struct Conjunto c3;
    struct Conjunto *ponteiroC3;
    int i;
    int menor;
    int flag;

    c3.elementoConjunto = NULL;
    c3.tamanhoConjunto = 0;

    ponteiroC3 = &c3;

    if (valido(&(*c1)) && valido(&(*c2)))
    {
        organizaConjunto(&(*c1));
        organizaConjunto(&(*c2));

        for (i = 0; i < (*c2)->tamanhoConjunto; i++)
        {
            if (!pertenceConjunto((*c2)->elementoConjunto[i], &(*c1)))
            {
                insereElementoConjunto((*c2)->elementoConjunto[i], &ponteiroC3);
            }
        }

        return c3;
    }
}

Conjunto uniao(struct Conjunto **c1, struct Conjunto **c2)
{
    struct Conjunto c3;
    struct Conjunto *ponteiroC3;
    int i;
    int menor;
    int flag;

    c3.elementoConjunto = NULL;
    c3.tamanhoConjunto = 0;

    ponteiroC3 = &c3;

    if (valido(&(*c1)) && valido(&(*c2)))
    {
        organizaConjunto(&(*c1));
        organizaConjunto(&(*c2));

        for (i = 0; i < (*c2)->tamanhoConjunto; i++)
        {
            if (!pertenceConjunto((*c2)->elementoConjunto[i], &(*c1)))
            {
                insereElementoConjunto((*c2)->elementoConjunto[i], &ponteiroC3);
            }
            insereElementoConjunto((*c1)->elementoConjunto[i], &ponteiroC3);
        }

        return c3;
    }
}

Conjunto interseccao(struct Conjunto **c1, struct Conjunto **c2)
{
    struct Conjunto c3;
    struct Conjunto *ponteiroC3;
    int i;
    int menor;
    int flag;

    c3.elementoConjunto = NULL;
    c3.tamanhoConjunto = 0;

    ponteiroC3 = &c3;

    if (valido(&(*c1)) && valido(&(*c2)))
    {
        organizaConjunto(&(*c1));
        organizaConjunto(&(*c2));

        for (i = 0; i < (*c2)->tamanhoConjunto; i++)
        {
            if (pertenceConjunto((*c2)->elementoConjunto[i], &(*c1)))
            {
                insereElementoConjunto((*c2)->elementoConjunto[i], &ponteiroC3);
            }
        }

        return c3;
    }
}

Conjunto diferenca(struct Conjunto **c1, struct Conjunto **c2)
{
    struct Conjunto c3;
    struct Conjunto *ponteiroC3;
    int i;
    int menor;
    int flag;

    c3.elementoConjunto = NULL;
    c3.tamanhoConjunto = 0;

    ponteiroC3 = &c3;

    if (valido(&(*c1)) && valido(&(*c2)))
    {
        organizaConjunto(&(*c1));
        organizaConjunto(&(*c2));

        for (i = 0; i < (*c2)->tamanhoConjunto; i++)
        {
            if (!pertenceConjunto((*c1)->elementoConjunto[i], &(*c2)))
            {
                insereElementoConjunto((*c1)->elementoConjunto[i], &ponteiroC3);
            }
        }

        return c3;
    }

    return c3;
}

void mostraConjunto(struct Conjunto **c, int ordem)
{
    int i;

    if (valido(&(*c)))
    {
        organizaConjunto(&(*c));

        if (ordem == 1)
        {
            for (i = 0; i < (*c)->tamanhoConjunto; i++)
            {
                printf("%d ", (*c)->elementoConjunto[i]);
            }
        }
        if (ordem == 0)
        {
            for (i = (*c)->tamanhoConjunto - 1; i >= 0; i--)
            {
                printf("%d ", (*c)->elementoConjunto[i]);
            }
        }
    }
}

int copiarConjunto(struct Conjunto **c1, struct Conjunto **c2)
{
    int i;
    int aux;

    if (valido(&(*c1)) && valido(&(*c2)))
    {
        organizaConjunto(&(*c1));

        free((*c2)->elementoConjunto);
        (*c2)->elementoConjunto = (int *)malloc((*c1)->tamanhoConjunto * sizeof(int));

        if ((*c2)->elementoConjunto != NULL)
        {
            (*c2)->tamanhoConjunto = 0;
            for (i = 0; i < (*c1)->tamanhoConjunto; i++)
            {
                aux = (*c1)->elementoConjunto[i];
                (*c2)->elementoConjunto[i] = aux;
                (*c2)->tamanhoConjunto++;
            }
            return 1;
        }
    }

    return 0;
}

int destroiConjunto(struct Conjunto **c)
{
    if (valido(&(*c)))
    {

        free((*c)->elementoConjunto);
        (*c)->tamanhoConjunto = 0;
        free((*c));
        (*c) = NULL;

        return 1;
    }
    else
        return 0;
}

void imprime_conjunto(Conjunto *c, int conjNum)
{
    int i, j = 0;
    if (c != NULL)
    {
        printf("Conjunto %d = { ", conjNum + 1);
        for (i = 0; i < c->tamanhoConjunto; i++)
        {
            printf(" %d ", c->elementoConjunto[i]);
            if (i != (c->tamanhoConjunto) - 1)
                printf(",");
        }
        printf("}\n");
    }
}

int mostra_numero_conjuntos(struct Conjunto **c, int numConj)
{
    int i;
    printf("Conjuntos:\n\n");
    for (i = 0; i < 104; i++)
        imprime_conjunto(c[i], i);
    printf("\n\n");
}

/*************************************************************************************/
/*                               main.c                                          */
/*************************************************************************************/

//#include "conjunto.c"

int main()
{
    struct Conjunto *conjs[104] = {NULL};
    struct Conjunto aux;
    struct Conjunto *auxPonteiro;
    int opcao = 1;
    int i;
    int j;
    int ordem;
    int elemento;
    int numeroConjuntos = 0;

    while (opcao != 0)
    {
        
        printf("\n\n------------------------------------- Menu -------------------------------------\n");
        if (numeroConjuntos)
            mostra_numero_conjuntos(conjs, numeroConjuntos);
        printf("01 - criar conjunto.\n");
        printf("02 - verifica se conjunto e vazio.\n");
        printf("03 - mostrar conjunto.\n");
        printf("04 - inserir elemento no conjunto.\n");
        printf("05 - excluir elemento do conjunto\n");
        printf("06 - tamanho do conjunto.\n");
        printf("07 - verifica quantos elementos do conjunto sao maiores que x.\n");
        printf("08 - verifica quantos elementos do conjunto sao menores que x.\n");
        printf("09 - verificar se o elemento x pertence ao conjunto.\n");
        printf("10 - comparar se dois conjuntos, sao identicos.\n");
        printf("11 - identificar se um conjunto e subconjunto de outro.\n");
        printf("12 - gerar o complemento de um conjunto em relacao a outro.\n");
        printf("13 - gerar a uniao de dois conjuntos.\n");
        printf("14 - gerar a interseccao de dois conjuntos.\n");
        printf("15 - gerar a diferenca de dois conjuntos.\n");
        printf("16 - copiar um conjunto em outro.\n");
        printf("17 - excluir conjunto.\n");

        printf("00 - para parar o programa.\n");
        printf("\nDigite uma opcao: ");

        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("digite o indice do conjunto a ser criado 1 - 100: ");
            scanf("%d", &i);
            if (criaConjunto(&conjs[i - 1]))
            {
                printf("conjunto criado com sucesso!\n");
                numeroConjuntos++;
            }
            else
                printf("conjunto nao criado\n");

            break;
        case 2:
            printf("digite o indice do conjunto a ser verificado 1 - 100: ");
            scanf("%d", &i);
            if (conjuntoVazio(&conjs[i - 1]))
            {
                printf("conjunto e vazio!\n");
            }
            else
                printf("conjunto nao e vazio\n");

            break;
        case 3:
            printf("digite o indice do conjunto a ser mostrado 1 - 100: ");
            scanf("%d", &i);
            printf("digite a ordem, 1 - crescente ou 0 - decrescente: ");
            scanf("%d", &ordem);
            if (ordem == 1 || ordem == 0)
            {
                printf("mostrar conjunto no indice selecionado %d: ", i);
                mostraConjunto(&conjs[i - 1], ordem);
            }

            break;
        case 4:
            printf("digite o indice do conjunto a ser inserido o elemento 1 - 100: ");
            scanf("%d", &i);
            printf("digite o elemento a ser inserido: ");
            scanf("%d", &elemento);
            if (insereElementoConjunto(elemento, &conjs[i - 1]) == 1)
                printf("Elemento inserido com sucesso\n");
            else
            {
                printf("Erro na insercao\n");
            }

            break;
        case 5:
            printf("digite o indice do conjunto a ser retirado o elemento 1 - 100: ");
            scanf("%d", &i);
            printf("digite o elemento a ser retirado: ");
            scanf("%d", &elemento);
            excluirElementoConjunto(elemento, &conjs[i - 1]);

            break;
        case 6:
            printf("digite o indice do conjunto a ser verificado 1 - 100: ");
            scanf("%d", &i);
            printf("o tamanho do conjunto %d e: %d", i, tamanhoConjunto(&conjs[i - 1]));

            break;
        case 7:
            printf("digite o indice do conjunto a ser verificado o elemento 1 - 100: ");
            scanf("%d", &i);
            printf("digite o elemento a ser verificado: ");
            scanf("%d", &elemento);
            printf("\nexiste %d elementos no conjunto %d maior(es) que %d\n", maior(elemento, &conjs[i - 1]), i, elemento);

            break;
        case 8:
            printf("digite o indice do conjunto a ser verificado o elemento 1 - 100: ");
            scanf("%d", &i);
            printf("digite o elemento a ser verificado: ");
            scanf("%d", &elemento);
            printf("\nexiste %d elementos no conjunto %d menor(es) que %d\n", menor(elemento, &conjs[i - 1]), i, elemento);

            break;
        case 9:
            printf("digite o indice do conjunto a ser verificado o elemento 1 - 100: ");
            scanf("%d", &i);
            printf("digite o elemento a ser verificado: ");
            scanf("%d", &elemento);
            if (pertenceConjunto(elemento, &conjs[i - 1]))
            {
                printf("\no elemento %d pertence ao conjunto %d\n", elemento, i);
            }
            else
            {
                printf("\no elemento %d nao pertence ao conjunto %d\n", elemento, i);
            }

            break;
        case 10:
            printf("digite o indice do primeiro conjunto a ser comparado 1 - 100: ");
            scanf("%d", &i);
            printf("digite o indice do segundo conjunto a ser comparado 1 - 100: ");
            scanf("%d", &j);
            if (conjuntosIdenticos(&conjs[i - 1], &conjs[j - 1]))
            {
                printf("\nconjuntos identicos\n");
            }
            else
            {
                printf("\nconjuntos distintos\n");
            }

            break;
        case 11:
            printf("digite o indice do primeiro conjunto a ser comparado 1 - 100: ");
            scanf("%d", &i);
            printf("digite o indice do segundo conjunto a ser comparado 1 - 100: ");
            scanf("%d", &j);
            if (subconjunto(&conjs[i - 1], &conjs[j - 1]))
            {
                printf("o conjunto de indice %d e subconjunto do conjunto de indice %d\n", i, j);
            }
            else
            {
                printf("o conjunto de indice %d nao e subconjunto do conjunto de indice %d\n", i, j);
            }

            break;
        case 12:
            criaConjunto(&conjs[100]);

            printf("digite o indice do primeiro conjunto a ser complementado 1 - 100: ");
            scanf("%d", &i);
            printf("digite o indice do segundo conjunto 1 - 100: ");
            scanf("%d", &j);
            aux = complemento(&conjs[i - 1], &conjs[j - 1]);
            auxPonteiro = &aux;

            copiarConjunto(&auxPonteiro, &conjs[100]);
            if (valido(&conjs[100]))
                printf("o conjunto complemento e de indice 101.\n");

            break;
        case 13:
            criaConjunto(&conjs[101]);

            printf("digite o indice do primeiro conjunto a ser unido 1 - 100: ");
            scanf("%d", &i);
            printf("digite o indice do segundo conjunto 1 - 100: ");
            scanf("%d", &j);
            aux = uniao(&conjs[i - 1], &conjs[j - 1]);
            auxPonteiro = &aux;

            copiarConjunto(&auxPonteiro, &conjs[101]);
            if (valido(&conjs[101]))
                printf("o conjunto uniao e de indice 102.\n");

            break;
        case 14:
            criaConjunto(&conjs[102]);

            printf("digite o indice do primeiro conjunto a ser interseccionado 1 - 100: ");
            scanf("%d", &i);
            printf("digite o indice do segundo conjunto 1 - 100: ");
            scanf("%d", &j);
            aux = interseccao(&conjs[i - 1], &conjs[j - 1]);
            auxPonteiro = &aux;

            copiarConjunto(&auxPonteiro, &conjs[102]);
            if (valido(&conjs[102]))
                ;
            printf("o conjunto interseccao e de indice 103.\n");

            break;
        case 15:
            criaConjunto(&conjs[103]);

            printf("digite o indice do primeiro conjunto a ser diferenciado 1 - 100: ");
            scanf("%d", &i);
            printf("digite o indice do segundo conjunto 1 - 100: ");
            scanf("%d", &j);
            aux = diferenca(&conjs[i - 1], &conjs[j - 1]);
            auxPonteiro = &aux;

            copiarConjunto(&auxPonteiro, &conjs[103]);
            if (valido(&conjs[103]))
                printf("o conjunto diferente e de indice 104.\n");

            break;
        case 16:
            printf("digite o indice do conjunto a ser copiado 1 - 100: ");
            scanf("%d", &i);
            printf("digite o indice do conjunto que sera a copia 1 - 100: ");
            scanf("%d", &j);
            if (copiarConjunto(&conjs[i - 1], &conjs[j - 1]))
            {
                printf("copia realizada.\n");
            }
            else
                printf("copia nao realizada.\n");

            break;
        case 17:
            printf("digite o indice do conjunto a ser destruido 1 - 100: ");
            scanf("%d", &i);

            if (destroiConjunto(&conjs[i - 1]))
            {
                printf("conjunto %d destuido\n", i);
            }
            else
                printf("conjunto %d nao foi destuido\n", i);

            break;
        }
    }
}