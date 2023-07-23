//
//  matrizesEponteiros.c
//
//
//  Created by Thierson Couto Rosa on 07/11/17.
//
//

#include <stdio.h>
void leMatrizInt1(int* mat,int lin, int col);
void leMatrizInt2(int mat[4][3],int lin, int col);



void imprimeMatInt(int* mat,int lin, int col);

int main(){
	int m[10][10];
	//Chamada a primeira versao da funcao leMatInt
	//leMatrizInt1(&m[0][0], 4,3);
	//Chamada a segunda versao da funcao LeMatInt
	leMatrizInt1(&m[0][0],4,3);
	imprimeMatInt(&m[0][0],4,3);

}

void leMatrizInt1(int* mat,int lin, int col){
	int i,j;
	for (i=0; i<lin; i++) {
    for (j=0; j<col; j++) {
			int aux=i*col;
			scanf("%d", mat+aux+j);
		}
	}
}

void leMatrizInt2(int mat[][3],int lin, int col){
	int i,j;
	for (i=0; i<lin; i++) {
    for (j=0; j<col; j++) {
			scanf("%d", &mat[i][j]);
		}
	}
}

void imprimeMatInt(int* mat,int lin, int col){
	int i,j;
	for (i=0; i<lin; i++) {
    for (j=0; j<col; j++) {
			int aux=i*col;
			printf("%d ", *(mat+aux+j) );
		}
		printf("\n");
	}
}
void leMatrizInt3(int **mat, int lin, int col){
	int i,j;
	for (i=0; i<lin; i++) {
    for (j=0; j<col; j++) {
			scanf("%d", &mat[i][j]);
		}
	}
}