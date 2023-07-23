#include <stdio.h>
 
int main(void)
{
    char sexo;
    int idade;
    
    scanf("%c %d", &sexo, &idade);
    
    printf("Bem ");
    if(sexo == 'F' || sexo == 'f')
    {
        printf("vinda! ");
    }
    else 
    {
        printf("vindo! ");
    }
    
    printf("Voce deve se instalar no alojamento ");
    
    if (sexo == 'F' || sexo == 'f')
    {
        if (idade >= 11 && idade <= 13)
        {
            printf("5 do bloco A\n");
        }
        else if (idade > 13 && idade < 16)
        {
            printf("6 do bloco A\n");
        }
        else 
        {
            printf("7 do bloco A\n");
        }
    }
    else
    {
        if (idade >= 11 && idade <= 12)
        {
            printf("1 do bloco B\n");
        }
        else if (idade  > 12 && idade <= 16)
        {
            printf("2 do bloco B\n");
        }
        else 
        {
            printf("3 do bloco B\n");
        }
    }
 
 
    return 0;    
}
