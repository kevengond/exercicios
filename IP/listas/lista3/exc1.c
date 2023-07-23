#include <stdio.h>
#include <string.h>

//constante para quantidade de letras permitidas em um caso de teste
enum {CAR = 102};

//funções utilizadas 
void clean(char str[]);
void mix(char str[]);

int main(void)
{
	//delcaração de variáveis
	int quant, i;
	char str[CAR];
	
	//leitura da quantidade de testes
	scanf("%d", &quant);
	getchar();

	//leitura dos casos de teste e mix	
	for (i = 0; i < quant; i++)
	{
		fgets(str, CAR, stdin);
		clean(str);
	
		//chamada para a função mix	
		mix(str);
	}

}

//função que retira o último \n da string
void clean(char str[])
{
	int c = strlen(str);

	if (str[c - 1] == '\n') str[c - 1] = 0;
}

//criará duas strings com o teste pego e fará o mix entre elas
void mix(char str[])
{
	//declaração de variáveis
	int c = strlen(str), esp, i, menor, tam2;
	
	//descoperda do primeiro espaço
	for (esp = 0; str[esp] != ' '; esp++);
	
	//declaração dos vetores que guardarão as duas strings
	char aux1[esp], aux2[c - esp];
	
	//separação da primeira string
	for (i = 0; i < esp; i++) aux1[i] = str[i];
	
	//separação da segunda string
	for (i = 0; i < (c - esp); i++) aux2[i] = str[esp + 1 + i];

	//descoberta do tamanho da segunda string e a troca do \n por espaço	
	tam2 = strlen(aux2);
	if (aux2[tam2] == 0) aux2[tam2] == ' ';
	
	//descoberta da menor string	
	menor = (esp < tam2) ? esp : tam2;
	
	//saída da primeira parte dos valores
	for (i = 0; i < menor; i++)
	{
		printf("%c%c", aux1[i], aux2[i]);
	}
	
	//se a primeira string for menor
	if (menor == esp)
	{	
		menor = tam2 - esp;
		for (i = 0; i < menor; i++) printf("%c", aux2[esp + i]);
		printf("\n");
	}
	else	//se a segund string for menor 
	{
		menor = esp - tam2;
		for (i = 0; i < menor; i++) printf("%c", aux1[tam2 + i]);
		printf("\n");
	}	
}

