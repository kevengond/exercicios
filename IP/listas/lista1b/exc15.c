#include <stdio.h>

int main(void)
{
    unsigned num, aux, dig = 0, i;
    unsigned v[4];
    
    scanf("%u", &num);
    
    if (num > 100000)
    {
        printf("NUMERO INVALIDO\n");
        return 1;
    }
    
    aux = num;
    while (aux > 0)
    {
        aux /= 10;
        dig++;
    }
    
    if (dig == 1)
    {
        printf("PALINDROMO\n");
    }
    else if (dig == 2)
    {
        if (num % 10 == num / 10)
        {
            printf("PALINDROMO\n");
        }
        else
        {
            printf("NAO PALINDROMO\n");
        }
    }
    else if (dig == 3)
    {
        if (num % 10 == num / 100)
        {
            printf("PALINDROMO\n");
        }
        else
        {
            printf("NAO PALINDROMO\n");
        }
    }
    else if (dig == 4)
    {
        if (num % 10 == num / 1000)
        {
            num /= 10;
            num -= ((num / 100) * 100);
            
            if (num % 10 == num / 10)
            {
                printf("PALINDROMO\n");
            }
            else
            {
                printf("NAO PALINDROMO\n");
            }
        }
        else
        {
            printf("NAO PALINDROMO\n");  
        }
    }
    else
    {
        if (num % 10 == num / 10000)
        {
            num /= 10;
            num -= ((num / 1000) * 1000);
            
            if (num % 10 == num / 100)
            {
                printf("PALINDROMO\n");
            }
            else
            {
                printf("NAO PALINDROMO\n");
            }
        }
        else
        {
            printf("NAO PALINDROMO\n");  
        } 
    }
    
    return 0;
}