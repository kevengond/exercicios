//
//  bublesort.c
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
void bubble(int v[], int n){
	int  i,j;
	for (i=1; i<n; i++) {
		for (j=0; j<n-i; j++) {
			if (v[j]>v[j+1]) {
				troca(&v[j], &v[j+1]);
			}
		}
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
	bubble(vet,TAMVET);
	//imprime vetor ordenado
	imprimeVet(vet,TAMVET);
	return(0);
}
