#include <stdio.h>
#include <stdlib.h>
int main ()
{
  FILE * pFile1, *pFile2;
  int c;
  int n = 0;
  
  pFile1=fopen ("Arquivo.txt","rt");
  if (pFile1==NULL){
   printf("Arquivo nao foi encontrado - Terinando o programa.\n");
   exit(1);
  }
  
  pFile2=fopen("Copia.txt", "wt");
  c = fgetc (pFile1);
  while (c!=EOF) {
    fputc (c, pFile2);
    c=fgetc(pFile1);
  }
  
  fclose (pFile1);
  fclose(pFile2);
  return 0;
}