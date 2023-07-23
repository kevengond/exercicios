#include <stdio.h>
#include <stdlib.h>

typedef struct no No;
typedef struct head Head;

// Estruturas de dados
struct no {
    int senha;
    struct no* prox;
};

struct head {
    No* inicio;
};

NO* criafila(int* senha){
    No* no=NULL;

    no = (No*)malloc(sizeof(No));
    if(no){
        no->senha= *senha;
        no->prox= NULL;
    }
    return no;

}
void insereElemento(Head *h, int* senha){
    No* senha=criafila(senha);

    if((h==NULL)||senha==NULL) return;

    if(h->inicio ==NULL) h->inicio=senha;

    else{
        No* a = h->inicio;
        while(a->prox!=NULL){
            a=a->prox;
            
        }
        a->prox = senha;
    }
}

int removeElemento(Head* h) {
if(h==NULL){
    return -1;
}

  No* aux = h->inicio;
  h->inicio=aux->prox;
  free(aux);
}









int main(){

    int quant_inic, aux;

    Head* h= NULL;
    h = (Head*) malloc(sizeof(Head));
    scanf("%d",&quant_inic);

    if(quant_inic<1||quant_inic>60000){
        return 0;

    }
    while(quant_inic--){
        scanf("%d", &aux);
        insereElemento(h, &aux);
    }

    mostraFila(h);





























}