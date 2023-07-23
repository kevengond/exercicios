#include <stdio.h>
#include <stdlib.h>
int main ()
{
  FILE * pFile1, *pFile2;
  char linha[500];
  int n = 0;
  pFile1=fopen ("Arquivo.txt","rt");
  if (pFile1==NULL){
   printf("Arquivo nao foi encontrado - Terinando o programa.\n");
   exit(1);
  }
  pFile2=fopen("Copia.txt", "wt");
	if (pFile2==NULL){
		printf("Arquivo de saida nao foi criado - Terinando o programa.\n");
		exit(1);
  }


	n=fscanf(pFile1,"%[^\n]", linha);
  while (n!=EOF) {
		fgetc(pFile1); // para consumir o \n
    fprintf(pFile2,"%s\n",linha);
		n=fscanf(pFile1,"%[^\n]", linha);
  }
  fclose (pFile1);
  fclose(pFile2);
  return 0;
}