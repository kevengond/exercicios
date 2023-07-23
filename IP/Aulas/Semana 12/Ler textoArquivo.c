#include <stdlib.h>
#include <stdio.h>
int main ()
{
  FILE * pFile;
  int c;
  int n = 0;
	//Abrir um arquivo tipo texto apenas para leitura sequencial
  pFile=fopen ("Arquivo.txt","rt");
	//Testar se o arquivo existe
  if (pFile==NULL){
    printf("Arquivo nao foi encontrado - Terinando o programa.\n");
    exit(1);
  }
	//Leitura caractere por caractere
  c = fgetc (pFile);
  while (c!=EOF) {
    putchar (c);
    c=fgetc(pFile);
  }
  // Fechando o arquivo.
  fclose (pFile);
  return 0;
}