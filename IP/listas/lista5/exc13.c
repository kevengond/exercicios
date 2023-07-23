#include <stdio.h>

typedef struct rac
{
    int num;
    int deno;
}racional;

racional raciona(int a, int b);
racional soma(racional r1, racional r2);
racional negativo(racional r2);
racional mult(racional r1, racional r2);
racional divi(racional r1, racional r2);
int MMC(int a, int b);
int MDC(int a, int b);
void reduzFracao(racional *r);

int main(void)
{
    int a, b, c, d;
    char ope;

    while (scanf("%d %d %c %d %d", &a, &b, &ope, &c, &d) != EOF)
    {
        if (b <= 0 || d <= 0) return 1;

        racional r1, r2, res;

        r1 = raciona(a, b);
        r2 = raciona(c, d);

        switch (ope)
        {
            case '+':
                res = soma(r1, r2);
                printf("%d %d\n", res.num, res.deno);
                break;
            case '-':
                r2 = negativo(r2);
                res = soma(r1, r2);
                printf("%d %d\n", res.num, res.deno);
                break;
            case '*':
                res = mult(r1, r2);
                printf("%d %d\n", res.num, res.deno);
                break;
            case '/':
                res = divi(r1, r2);
                printf("%d %d\n", res.num, res.deno);
                break;
        }
    }
}

racional raciona(int a, int b)
{
    racional raci;
    raci.num = a;
    raci.deno = b;
    return raci;
}

int MMC(int a, int b)
{
    int rest1, rest2;
    int cont = 1, num = 2;

    while (a > 1 || b > 1)
    {
        rest1 = a % num;
        rest2 = b % num;

        if (rest1 == 0 || rest2 == 0)
        {
            if (rest1 == 0) a /= num;
            if (rest2 == 0) b /= num;

            cont *= num;
            num--;
        }
        num++;
    }

    return cont;
}

int MDC(int a, int b)
{
    int rest1, rest2;
    int cont = 1, num = 2;

    while (a > 1 && b > 1)
    {
        rest1 = a % num;
        rest2 = b % num;

        if (rest1 == 0 && rest2 == 0)
        {
            a /= num;
            b /= num;

            cont *= num;
            num--;
        }
        else if (rest1 == 0)
        {
            a /= num;
            num--;
        }
        else if (rest2 == 0)
        {
            b /=num;
            num--;
        }
        num++;
    }

    return cont;
}

void reduzFracao(racional *res)
{
    int res_mdc;
    int inver = 0;
    if (res->num < 0)
    {
        res->num *= -1;
        inver = 1;
    }

    if (res->num > res->deno)
    {
        res_mdc = MDC(res->num, res->deno);
    }
    else res_mdc = MDC(res->deno, res->num);

    if (inver) res->num *= -1;

    res->num /= res_mdc;
    res->deno /= res_mdc;
}

racional soma(racional r1, racional r2)
{
   racional res;
   int res_mmc;

   int inver = 0;
   if (r2.num < 0)
    {
        r2.num *= -1;
        inver = 1;
    }

   res_mmc = MMC(r1.deno, r2.deno);

    if (inver) r2.num *= -1;

   res.num = ((res_mmc / r1.deno) * r1.num) + ((res_mmc / r2.deno) * r2.num);
   res.deno = res_mmc;

   reduzFracao(&res);

   return res;
}


racional negativo(racional r2)
{
    r2.num *= -1;
    return r2;
}


racional mult(racional r1, racional r2)
{
    racional res;

    res.num = r1.num  * r2.num;
    res.deno = r1.deno * r2.deno;

    reduzFracao(&res);

    return res;
}

racional divi(racional r1, racional r2)
{
    racional res;

    res.num = r1.num * r2.deno;
    res.deno = r1.deno * r2.num;

    reduzFracao(&res);

    return res;
}