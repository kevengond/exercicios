#include <stdio.h>
#include <math.h>

//declaração de uma struct de número complexo
struct Complex
{
    double real;
    double img;
};

//declaração de uma struc de raizes de uma equação
struct RaizEqu2
{
    struct Complex r1;
    struct Complex r2;
};

//funções para o cálculo das raízes e sáida dos resultados
struct RaizEqu2 calcula_raiz_equ_2( float a, float b, float c);
void complex_print(struct Complex res);

int main(void)
{
    //declaração de variáveis
    float a, b, c;
    struct RaizEqu2 res;

    //leitura dos coeficientes
    scanf("%f %f %f", &a, &b, &c);

    //chamada da função para o cálculos das raízes e
    //retorno do resultado
    res = calcula_raiz_equ_2(a, b, c);

    //saídas
    printf("x1 = ");
    complex_print(res.r1);

    printf("x2 = ");
    complex_print(res.r2);
}

//função para o cálculo das raízes
struct RaizEqu2 calcula_raiz_equ_2( float a, float b, float c)
{
    //declaração de variáveis
   float delt, rdelt, comp = 0;
   struct RaizEqu2 res;

    //calculo do delta
   delt = pow(b, 2) - 4 * a * c;

   // Caso o delta seja negativo, as raízes são complexas (i = sqrt(-1))
   if (delt < 0)
   {
       delt *= -1;
       rdelt = sqrt(delt);

       res.r1.real = (-1 * b) / (2 * a);
       res.r1.img = (rdelt / (2 * a));

       res.r2.real = (-1 * b) / (2 * a);
       res.r2.img = -1 * (rdelt / (2 * a));
   }
   else //caso contrário as raízes são reais
   {
       rdelt = sqrt(delt);

       res.r1.real = ((-1 * b) + rdelt) / (2 * a);
       res.r1.img = 0;

       res.r2.real = ((-1 * b) - rdelt) / (2 * a);
       res.r2.img = 0;

   }

   //retorno do resultado das operações em uma struct
   return res;
}

//função para a saída dos resultados
void complex_print(struct Complex res)
{
    if (res.img == 0 && res.real == 0) printf("0.00"); //caso a parte imaginária e real sejam 0
    else if (res.real != 0) //caso a parte real seja diferente de 0
    {
        printf("%.2lf", res.real);
        if (res.img != 0)//caso a parte imaginária seja diferente de 0
        {
            if (res.img > 0) printf("+");

            if (res.img == -1) printf("-i");
            else if (res.img == 1) printf("i");
            else if (res.img != 1 || res.img != -1) printf("%.2lfi", res.img);
        }
    }
    else //caso a parte real seja igual a 0
    {
      if (res.img != 0)
        {
            if (res.img > 0 && res.img != 1) printf("+");

            if (res.img == -1) printf("-i");
            else if (res.img == 1) printf("i");
            else if (res.img != 1 || res.img != -1) printf("%.2lfi", res.img);
        }
    }

    printf("\n");
}