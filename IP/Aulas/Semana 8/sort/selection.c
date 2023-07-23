//
//  selectionSort.c
//
//
//  Created by Thierson Couto Rosa on 02/10/18.
//
//

#include <stdio.h>
#define TAMVET 5

void troca (int *x, int* y){
	int aux;
	aux=*x;
	*x=*y;
	*y=aux;
}
void selection(int v[6], int n){
	int menor, indmenor, i,j;
	for (i=0; i<n-1; i++) {
    menor = v[i];
		indmenor=i;
		for (j=i; j<n; j++) {
			if (v[j]<menor) {
				menor=v[j];
				indmenor=j;
			}
		}
		troca(&v[i],&v[indmenor]);
	}
}
void imprimeVet(int* v, int n){
	int i;
	for (i=0; i<n; i++) {
    printf("%d ", v[i]);
	}
	printf("\n");
}

int main(){
	int vet[TAMVET],i;
	//Ler o vetor
	for (i=0; i<TAMVET; i++) {
    scanf("%d", &vet[i]);
	}
	//imprime o vetor lido
	imprimeVet (vet,TAMVET);
	selection(vet,TAMVET);
	//imprime vetor ordenado
	imprimeVet(vet,TAMVET);
	return(0);
}




