#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct aluno{
	int matricula;
	float nota;
	int tamNome;
	char* nome;
} TAluno;

void imprimeAlunos(TAluno* p, int numAlunos);
int leAlunos(FILE* f, TAluno* p, int numAlunos);

int main ()
{
/*Este programa le campo por campo do vetor de struct TAluno armazenado pelo
programa gravaVecStruct.c e os armazena em um vetor de TAlunos. Em seguida, o
programa percorre o vetor, imprimindo os dados dos alunos armazendados em disco. */
	char buffer[10000];
  FILE * pFile;

	TAluno* vet;
	int i;
  pFile=fopen ("MeuArquivo","rb");
	if (!pFile) {
    fprintf(stderr, "Arquivo MeuArquivo nao pode ser aberto - terminando o programa\n");
		exit(1);
	}

	if(!leAlunos(pFile, vet,3)){
		fprintf(stderr, "Erro durante a leitura de arquivo\n");
		exit(1);
	}
	imprimeAlunos(vet,3);
	fclose(pFile);
		return 0;
}
void imprimeAlunos(TAluno* p, int numAlunos){
	int i;
	for(i=0;i<numAlunos;i++){
	  printf("Aluno %d\n", i+1);
		printf("Matricula: %d\n", p[i].matricula);
		printf("Nota: %.2f \n", p[i].nota);
		printf("Nome: %s\n", p[i].nome);
		printf("\n");
	}
}
int leAlunos(FILE * f, TAluno* p, int numAlunos){

	int i=0;
	for (i=0; i<numAlunos; i++) {
			fread(&(p[i].matricula), sizeof(int),1, f);
			fread(&(p[i].nota), sizeof(float),1,f);
			fread(&(p[i].tamNome), sizeof(int),1,f);
			p[i].nome= (char*)malloc(sizeof(char)*(p[i].tamNome+1));
		  if (!p[i].nome) {
			  fprintf(stderr, "Nao ha memoria suficiente para o programa\n");
				exit(1);
		  }
			fread(p[i].nome,p[i].tamNome,1,f);
			p[i].nome[p[i].tamNome]='\0';
		}
	if (ferror(f)) {
    return(0);
	}
	return(1);
}