#include <stdio.h>

int main(void)
{
    // declaração de variáveis
    double aux;
    int quant, i, j = 0;
    
    //leitura da quantidade de casos de teste
    scanf("%d", &quant);
    i = quant;

    //delcaração de vetores para temperaturas em celcius e Fahrenheit
    double cel[quant], fah[quant];
    
    //contas 
    while (i--)
    {
        scanf("%lf", &aux);
        fah[j] = aux;

        cel[j] = (float) (aux - 32) * 5 / 9;

       j++;
    }
    
    //saida dos valores
   for (j = 0; j < quant; j++)
   {
       printf("%.2lf FAHRENHEIT EQUIVALE A %.2lf CELSIUS\n", fah[j], cel[j]);
   }

   return 0;
}
