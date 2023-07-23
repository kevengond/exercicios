#include <stdio.h>
#include <ctype.h>
 
//constante com a quantidade máxima de caracteres
enum {QMAX = 51};

//função para a manipulação da string
void mani(char str[]);
 
int main(void)
{
    //declaração de variáveis
    char str[QMAX];
    
    //leitura dos valores e retirada do \n
    while (scanf("%[^\n]", str) != EOF)
    {
	getchar();
	
	//chamada para a função que irá fazer a manipulação
	mani(str);
	
	//saída
	printf("%s\n", str);
      
    }
}

//função que irá manipular a string, convertendo maiúsculas e minúsculas
void mani(char str[])
{
	//declaração de variávies
	int i, e_mai = 1;
	
	//inverter os valores 
        for (i = 0; str[i]; i++)
        {
            if (isalpha(str[i]))
	    {
		//se é para ser maiúscula mas está minúscula 
		if (e_mai && islower(str[i])) str[i] = toupper(str[i]);
		//se é para ser minúscula mas está maiúscula
		if (!e_mai && isupper(str[i])) str[i] = tolower(str[i]);
		
		//inverter o auxiliar a cada cíclo
		if (e_mai) e_mai = 0;
		else e_mai = 1;
	    }
        }
}
