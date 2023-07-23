//
//  alocacaoDinamicaNomes.c
/* Esse programa é um exemplo de como é possível alocar espaço suficiente para caber uma string. O programa le nomes dos alunos de uma turma. Cada nome é inicialmente armazenado em um buffer de entrada que é um vetor de caracteres grande o suficiente para armazenar qualquer nome. Uma vez lido  o nome do aluno i, alocamos dinamicamente, através da função malloc(), um espaço de memória suficiente apenas para armazenar o nome do aluno lido mais o caractere terminador de cadeia \0. Verificamos se a chamada à função malloc() conseguiu reservar espaço para o nome. Se tiver conseguido, copiamos, através da função strcpy() a string no buffer para a área alocada. o vetor que armazena os diversos nomes da turma é um vetor denominado turma e o seu tipo tem que ser **char ( isto é, ponteiro para ponteiro de char) porque a área dinâmicamente alocada deve ser tratada como uma string que na linguagem C é tratada como um ponteiro para char. Após o nome ser copiado do buffer para a área alocada, outro  o nome do aluno i+1 pode ser lido no buffer, sobrepondo o nome do aluno i que estava lá.*/
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#define TAM_TURMA 5
#define TAM_MAX_NOME 1000

char *turma[TAM_TURMA];
char buffer[TAM_MAX_NOME];

void imprimeEnd(int i){
	printf("%s\n", turma[i]);
}
int main(){
	int i=0;
	  printf ("O endereco do primeiro elemento do vetor turma e: %p\n",turma);
		printf("O endereco do segundo elemento do vetor turma e: %p\n",turma+1);

		while(i<TAM_TURMA){
			//ler o nome no buffer primeiro
			printf("Digite o nome do aluno numero %d\n", i);
			scanf("%[^\n]", buffer);
			getchar(); // consome o \n

			// Obter o tamanho do nome no buffer
			int tamNome=strlen(buffer);

			//Tentar alcocar espaco para armazenar o nome no vetor
			turma[i]=(char*)malloc(tamNome+1);
			if(turma[i]==0){//nao houve memoria suficiente para alcoar
				printf("Erro: não há memoria suficiente para armazenar os nomes\n");
				printf("Execução interrompida por falta de mória\n");
				exit(1);
			}
			else{
				// Copiar o nome no buffer para o espaco cujo endereço esta
				// em turma[i]
				strcpy(turma[i], buffer);
				printf("O endereco de %s e: %p\n",turma[i],turma[i]);
				i++;
			}
		}
		/*printf ("Digite a posicao a ser alterada\n");
		scanf("%d", &i);
		printf ("Digite um novo nome para a posicao\n");
		scanf("%s", buffer);
		imprimeEnd(i);
		if(strlen(buffer)<= strlen(turma[i])){
			strcpy(turma[i],buffer);
			imprimeEnd(i);
		}
		else{
			turma[i]=(char*)realloc(turma[i],strlen(buffer)+1);
			strcpy(turma[i],buffer);
			imprimeEnd(i);
		}
		*/
	for (i=0; i<TAM_TURMA; i++) {
    imprimeEnd(i);
		free(turma[i]);
	}
}
