#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//recebe dois numeros em forma de string e os multiplica
//@param *num1 numero 1
//@param *num2 numero 2
//@param *resultado resultado
void multiplicacao(char *num1, char *num2);

//recebe os numeros do terminal e retorna o numero de algarismos do numero
//@param *numVect vetor de um numero
//@return tamanho do algarismo
int get_numbers(char *numVect);

int main()
{
    char num1[40], num2[40];
    int casos;

    scanf("%d%*c", &casos);
    
    if(casos<1||casos>50) return 0;

    while(casos--) {
        multiplicacao(num1, num2);
    }

    return 0;
}

void multiplicacao(char *num1, char *num2)
{
    //@RubensAugusto
    //por favor usem nomes que expliquem as variaveis ao inves de "ia", "b", "a" ,"ts"
    char resultado[1000] = {0};
    int tam1, tam2; // num de algarismos
    int i, j; //contadores
    int tempNum1, tempNum2; //numeros temporarios
    int numExcedente = 0;// o numero que ira para proxima casa decimal

    tam1 = get_numbers(num1);
    tam2 = get_numbers(num2);
    for(i = tam1-1;i >= 0;i--)
    {
        tempNum1 = num1[i] - '0';
        for(j = tam2-1;j >= -1;j--)
        {
            tempNum2 = j >= 0 ? num2[j] - '0' : 0;
            resultado[i+j+1] += tempNum1*tempNum2 + numExcedente;
            numExcedente = resultado[i+j+1] / 10;
            resultado[i+j+1] = resultado[i+j+1] % 10;
        }
    }

    resultado[tam1 + tam2] = '\0';
    for(i = 0; i < tam1+tam2; i++)
        resultado[i] += '0';
    printf("%s\n", resultado);
}
int get_numbers(char *numVect)
{ 
    scanf("%s", numVect);
    return strlen(numVect);
}