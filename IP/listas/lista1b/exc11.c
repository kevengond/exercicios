#include <stdio.h>
#include <math.h>

int main(void)
{
    double a, b, c, delt, x1, x2, aux;

    scanf("%lf %lf %lf", &a, &b, &c);

    delt = pow(b,2) - (4 * a * c);
    
    x1 = (-b + sqrt(delt)) / (2 * a);
    x2 = (-b - sqrt(delt)) / (2 * a);
    
    if (x1 > x2)
    {
        aux = x1;
        x1 = x2;
        x2 =aux;
    }
    
    if (delt > 0)
    {
        printf("RAIZES DISTINTAS\n");
        printf("X1 = %.2lf\n", x1);
        printf("X2 = %.2lf\n", x2);
    }
    else if (delt == 0)
    {
        printf("RAIZ UNICA\n");
        printf("X1 = %.2lf\n", x1);
    }
    else
    {
        printf("RAIZES IMAGINARIAS\n");
    }
}