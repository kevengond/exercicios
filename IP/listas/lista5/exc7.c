#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//constantes (os dois primeiros para ter uma noçao dos máximos permitidos) com as quantidades de
//caracteres permitidos
enum {CMAX = 101, NMAX = 501, BMAX = 1000};

//declarar um tipo para os cursos
typedef struct cur
{
    int cod;
    double v_cred;
    char *curso;
} cursos;

//delcaração de um tipo para os alunos
typedef struct reg
{
    char *nome;
    int cod_c;
    int cred;
}registro;

int main(void)
{
    //declaração de variáveis
    char buff[BMAX];
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
        scanf("%[^\n]", buff);
        getchar();
        cr[i].curso = (char *) malloc(sizeof(buff));
        strcpy(cr[i].curso, buff);
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
        scanf("%[^\n]", buff);
        getchar();
        alu[i].nome = (char *) malloc(sizeof(buff));
        strcpy(alu[i].nome, buff);
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

    //liberação da memória alocada
    for (i = 0; i < quant_a; i++) free(alu[i].nome);
    for (i = 0; i < quant_c; i++) free(cr[i].curso);
}