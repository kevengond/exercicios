#include <stdio.h>
#include <stdlib.h>

// TAD - Variaveis globais
typedef struct no No;
typedef struct head Head;

// Estruturas de dados
struct no
{
    int data;
    struct no *prox;
};

struct head
{
    No *inicio;
};

// Prototipos
No *criaFila(int *data);
void insereElemento(Head *h, int *data);
int removeElemento(Head *h);
void mostraFila(Head *h);


int main()
{

    int quant_inic, aux, rep, aux2;
   
    Head *h = NULL;
    h = (Head *)malloc(sizeof(Head));
    h->inicio = NULL;
    Head *h1 = NULL;
    h1 = (Head *)malloc(sizeof(Head));
    h1->inicio = NULL;

    scanf("%d", &quant_inic);

    if (quant_inic < 1 || quant_inic > 60000)
    {
        return 0;
    }
    while (quant_inic--)
    {
        scanf("%d", &aux);
        insereElemento(h, &aux);
    }

    scanf("%d", &rep);

    if (rep < 1 || rep > quant_inic)
    {
        return 0;
    }
     while (rep--)
    {
        scanf("%d", &aux1);
        insereElemento(h1, &aux1);
    }
    
   
    Comparar_remove(h,h1);

   
    
    mostraFila(h);

    return 0;
}

No *criaFila(int *data)
{
    No *no = NULL;

    no = (No *)malloc(sizeof(No));
    if (no)
    {
        no->data = *data;
        no->prox = NULL;
    }

    return no;
}

void insereElemento(Head *h, int *data)
{
    No *x = criaFila(data);

    if (h == NULL || x == NULL)
        return;
    if (h->inicio == NULL)
        h->inicio = x;
    else
    {
        No *a = h->inicio;
        while (a->prox != NULL)
        {
            a = a->prox;
        }
        a->prox = x;
    }
}

int removeElemento(Head *h)
{
    if (h == NULL)
    {
        return -1;
    }

    No *aux = h->inicio;
    h->inicio = aux->prox;
    free(aux);
}

void mostraFila(Head *h)
{
    No *aux;

    aux = h->inicio;
    while (aux != NULL)
    {

        printf("%d ", aux->data);
        aux = aux->prox;
                
    }
}

/*void Comparar_remove(Head *l1, Head *l2)
{
    No *aux, *aux 1;

    aux = l1->inicio;
    aux1 = l2->inicio;
    while (l1 != NULL)
    {
        if(aux->prox == aux->prox)
        {
            removeElemento(l1);
        }
    
        aux = aux->prox;
        aux1 = aux1->prox;
    }
}
*/