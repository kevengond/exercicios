#include <stdio.h>
#include <math.h>

//Protótipos
void ordem(int ord); // escrever a ordem
void decom(int num, int ord); // decompor o numero
void numpot(int num, int ord); // colocar os numeros em potencia de 10

int main(void)
{
    // variaveis main
    int num, aux, ord = 0;

    // leitura do numero
    scanf("%d", &num);

     aux = num;

    // Descubririr a ordem do numero (será usada para as outras funções)
    while (aux > 0)
    {
        aux /= 10;
        ord++;
    }

    // Descubrir se o número é válido
    if (num < 0 || ord > 4)
    {
        printf("Numero invalido!\n");
        return 1;
    }
    
    // funçoes
    if (ord != 0)
    {
        ordem(ord);
        decom(num, ord);
        numpot(num, ord);
    }
        
    return 0;
}


// Printf() da ordem do numero
void ordem(int ord)
{
    switch (ord)
    {
        case 1:
            printf("(primeira ordem) ");
            break;
        case 2:
            printf("(segunda ordem) ");
            break;
        case 3:
            printf("(terceira ordem) ");
            break;
        case 4:
            printf("(quarta ordem) ");
            break;
    }
}


//Decompor o número
void decom(int num, int ord)
{
    //variáveis da função
    int dig, i, aux, aux2, primer = 0;
    aux = num;
    aux2 = ord;
    
    printf("%d = ", num); //irá colocar o numero e o igual (número =)
    
    //Decompor e colocar as unidades dezenas e centenas e unidades de milhar 
    for (i = (ord - 1); i >= 0; i--)
    {
        dig = aux / (int)pow(10, i);
        aux %= (int)pow(10, i);
        
        if(dig > 0)
        {
            if (primer)
              printf(" + "); // para colocar o + entre eles sem ser o primeiro
            else
              primer = 1;
            switch(aux2)
            {
                case 1:
                    printf("%d unidade", dig);
                    aux2--;
                    break;
                case 2:
                    printf("%d dezena", dig);
                    aux2--;
                    break;
                case 3:
                    printf("%d centena", dig);
                    aux2--;
                    break;
                case 4:
                    printf("%d unidade de milhar", dig);
                    aux2--;
                    break;
            }
               
            if (dig > 1 && aux2 != 4)
                printf("s"); //colocar o s caso os númeos sejam maiores que 1
        }
        else
            aux2--;
    }
}


//colocar o número em função de potência de 10
void numpot(int num, int ord)
{
    //variaveis da função
    int dig, aux, primer = 0, i;
    
    aux = num;
    printf(" = "); 
    for (i = (ord - 1); i >= 0; i--)
    {
        dig = aux / (int)pow(10, i);
        aux %= (int)pow(10, i);
        if (dig != 0)
        {
            if (primer)
                  printf(" + ");
            else
              primer = 1;
                
            printf("%d", dig * (int)pow(10, i));
        }
    }
    printf("\n"); //quebra de linha final
    
}





