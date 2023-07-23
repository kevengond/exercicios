#include <stdio.h>

//constantes com os valores máximos de caracteres no nome do curso e no nome do aluno
enum {CMAX = 101, NMAX = 501};

//declarar um tipo para os cursos
typedef struct cur
{
    int cod;
    double v_cred;
    char curso[CMAX];
} cursos;

//delcaração de um tipo para os alunos
typedef struct reg
{
    char nome[NMAX];
    int cod_c;
    int cred;
}registro;

int main(void)
{
    //declaração de variáveis
    int quant_c, quant_a, i, j;
    double aux;

    //leitura da quantidade de cursos
    scanf("%d", &quant_c);

    //vetor de cursos
    cursos cr[quant_c];

    //leitura dos campos de cada curso disponível
    for (i = 0; i < quant_c; i++)
    {
        scanf("%d %lf", &cr[i].cod, &cr[i].v_cred);
        getchar();
        scanf("%[^\n]", cr[i].curso);
        getchar();
    }

    //leitura da quantidade de alunos na instituição
    scanf("%d", &quant_a);
    if (quant_a < 1 || quant_a > 1000) return 2;
    getchar();

    //vetor de alunos
    registro alu[quant_a];

    //leitura dos campos de cada aluno
    for (i = 0; i < quant_a; i++)
    {
        scanf("%[^\n]", alu[i].nome);
        getchar();
        scanf("%d %d", &alu[i].cod_c, &alu[i].cred);
        getchar();
    }

    //saída esperada para cada aluno
    for (i = 0; i < quant_a; i++)
    {
        printf("Aluno(a): %s ", alu[i].nome);

        for (j = 0; j < quant_c; j++)
        {
            if (alu[i].cod_c == cr[j].cod)
            {
                printf("Curso: %s ", cr[j].curso);
                aux = cr[j].v_cred;
            }
        }

        printf("Num. Creditos: %d ", alu[i].cred);

        printf("Valor Credito: %.2lf ", aux);

        printf("Mensalidade: %.2lf\n", aux * alu[i].cred);
    }
}