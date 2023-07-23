#include <stdio.h>
#include <math.h>

int main(void)
{
    unsigned num, dia, mes, ano;
    
    scanf("%u", &num);
    
    dia = num / (int)pow(10, 6);
    mes = (num / (int)pow(10, 4)) - (dia * pow(10, 2));
    ano = num - (dia * pow(10,6)) - (mes * pow(10, 4));
    
    if (mes == 2)
    {
        if  (dia >= 1 && dia <= 28)
        {
            printf("%u de fevereiro de %u\n", dia, ano);
        }
        else 
        {
            printf("Data invalida!\n");   
        }
    }
    else if (mes >= 1 && mes <= 7)
    {
        if (mes % 2 == 0 && (dia >= 1 && dia <= 31))
        {
            switch (mes)
            {
                case 4:
                    printf("%u de abril de %u\n", dia, ano);
                    break;
                case 6:
                    printf("%u de junho de %u\n", dia, ano);  
                    break;
            }
        }
        else if (mes % 2 != 0 && (dia >= 1 && dia <= 30))
        {
            switch (mes)
            {
                case 1:
                    printf("%u de janeiro de %u\n", dia, ano);
                    break;
                case 3:
                    printf("%u de março de %u\n", dia, ano);
                    break;
                case 5:
                    printf("%u de maio de %u\n", dia, ano);
                    break;
                case 7:
                    printf("%u de julho de %u\n", dia, ano);
                    break;
            }
        }
        else
        {
            printf("Data invalida!\n");
        }
    }
    else if (mes > 7 && mes <= 12)
    {
      if (mes % 2 != 0 && (dia >= 1 && dia <= 31))
        {
            switch (mes)
            {
                case 9:
                    printf("%u de setembro de %u\n", dia, ano);
                    break;
                case 11:
                    printf("%u de novembro de %u\n", dia, ano);  
                    break;
            }
        }
        else if (mes % 2 == 0 && (dia >= 1 && dia <= 30))
        {
            switch (mes)
            {
                case 8:
                    printf("%u de agosto de %u\n", dia, ano);
                    break;
                case 10:
                    printf("%u de outubro de %u\n", dia, ano);
                    break;
                case 12:
                    printf("%u de dezembro de %u\n", dia, ano);
                    break;
            }
        }
        else
        {
            printf("Data invalida!\n");
        }  
    }
    else
    {
        printf("Data invalida!\n");
    }

    return 0;
}