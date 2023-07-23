#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct aluno{
	int matricula;
	float nota;
	int tamNome;
	char* nome;
} TAluno;
int leAlunos(FILE * f, TAluno* p);
int alocaNome(TAluno* p, char*buff);
int gravaAlunos(FILE* f, TAluno* p, int numAlunos);

int main ()
{
/*Este progrmama le os dados de tres alunos em um vetor e depois grava seus dados em arquivo. O programa armazena no campo nome da struct que representa um aluno apenas o espaco de memoria suficiente para armazenar o nome do aluno mais o delimitador de cadeia de caracteres.
  Repare que o tamanho do nome faz parte da struct. Isso e nessario para
	que a leitura do arquivo seja correta, pois cada nome de aluno tera um numero de caracteres diferente */
	char buffer[10000];
  FILE * pFile;

	TAluno vet[3];
	int i;
  pFile=fopen ("MeuArquivo","r+b"); //Abre o arquivo para leitura e escrita com acesso aleatorio
	if (!pFile) {
    fprintf(stderr, "Arquivo MeuArquivo nao pode ser aberto - terminando o programa\n");
		exit(1);
	}




	for(i=0; i<3;i++){
		printf("Digite a matricula do aluno\n");
		scanf("%d", &vet[i].matricula);
		printf("Digite a nota do aluno\n");
		scanf("%f", &vet[i].nota);
		printf("Digite o nome do aluno\n");
		getchar();
		scanf("%[^\n]", buffer);
		getchar();
		if(!alocaNome(&vet[i], buffer)){
			fprintf(stderr, "Nao ha memoria suficiente para executar o programa\n");
			exit(1);
		}
	}
	if(!gravaAlunos(pFile, vet, 3)){
		fprintf(stderr, "Erro durante a gravação de arquivo\n");
		exit(1);
	}
	fclose(pFile);
		return 0;
}
int alocaNome(TAluno* p, char* buff){
	p->nome=(char*) malloc(sizeof(char)*(1+strlen(buff)));
	if (!p) {
    return(0);
	}
	strcpy(p->nome, buff);
	p->tamNome=strlen(buff);
	return(1);

}
int gravaAlunos(FILE * f, TAluno* p, int numAlunos){

	int i=0;
	for (i=0; i<numAlunos; i++) {
			fwrite(&(p[i].matricula), sizeof(int),1, f);
			fwrite(&(p[i].nota), sizeof(float),1,f);
			fwrite(&(p[i].tamNome),sizeof(int),1,f);
			fwrite(p[i].nome,p[i].tamNome,1,f);
		}
	if (ferror(f)) {
    return(0);
	}
	return(1);
}

int leAlunos(FILE * f, TAluno* p){

	int i=0;
	int tam=2;
	if(p=(TAluno*)malloc(p,sizeof(TAluno*tam))==NULL){
		fprintf(stderr,"Nao ha memoria suficiente\n");
		return(0);
	}
	while (!feof(f)) {
		if(i<tam){
			fread(&(p[i].matricula), sizeof(int),1, f);
			fread(&(p[i].nota), sizeof(float),1,f);
			fread(&(p[i].tamNome), sizeof(int),1,f);
			p[i].nome= (char*)malloc(sizeof(char)*(p[i].tamNome+1));
			if (!p[i].nome) {
				fprintf(stderr, "Nao ha memoria suficiente para o programa\n");
				return(0);
			}
			fread(p[i].nome,p[i].tamNome,1,f);
			p[i].nome[p[i].tamNome]='\0';
			i++;
		}
		else{
			tam*=2;
			p=(TAluno*)realloc(p,sizeof(TAluno*tam));
			if(!p){
				fprintf(stderr, "Nao ha memoria suficiente para o programa\n");
				return(0);
			}
		}
	}
	return(i-1);
}