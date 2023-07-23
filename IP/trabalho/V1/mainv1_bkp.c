/*----------------------------------------------
 * 		Trabalho final
 * Nome: Diego Enrique da Silva Lima
 * Matrícula: 202014182
 * E-mail: diegoenrique@outlook.com.br
 * ------------------------------------------*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

//Constantes base para o funcionamento do sistema
#define WIN 0
#define LUX 1

#define LWIN system("cls")
#define LLUX system("clear")

//constantes para diferenciar o CRUD de alunos com o de disciplinas
#define ALU 0
#define DIS 1

#define A_DIS "Disciplinas"
#define A_ALU "Alunos"


//outras constantes para o funcionamento
enum {CARAC_A = 16, SI_UF = 2, T_BUFF_CHAR = 1000, T_BUFF_INT = 20};

//variável para o sistema operacional
int SO;

//declaração de tipos para as disciplinas, endereços e alunos
typedef struct dis
{
    int id;
    char nome_dis[T_BUFF_CHAR];
    int semestre;
    int ano;
}disciplina;

typedef struct end
{
    char rua[T_BUFF_CHAR];
    char bai[T_BUFF_CHAR];
    int cep;
    char cty[T_BUFF_CHAR];
    char uf[SI_UF];
}endereco;

typedef struct alu
{
    int matri;
    char nome[T_BUFF_CHAR];
    int idade;
    int quant_dis;
    int m_dis[T_BUFF_INT];
    endereco ende;
}aluno;

//protótipos das funções
int sistema(void);
int menu_princ(void);
void ger_disc(void);
void ger_alu(void);
void inserir(int tipo);
void pesquisar(int tipo);
aluno pesq_alu(int pesq);
disciplina pesq_dis(int pesq);
void remover(int tipo);
void atuali(int tipo);
void clear(char str[]);
void limp_tela();
int confirm();

int main(void)
{
    int resp;

    setlocale(LC_ALL, "portuguese-brazilian");

    SO = sistema();
    resp = menu_princ();

    while (resp != 3)
    {
        switch (resp)
        {
            case 1:
                ger_disc();
                break;
            case 2:
                ger_alu();
                break;
        }

        resp = menu_princ();
    }

    exit(0);
}

//função para descobrir o sistema operacional para o funcionamento correto do programa
int sistema(void)
{
    int res = -1;

    while (res < 1 || res > 2)
    {
        printf("--------------------------------------\n");
        printf("               AJUSTES                \n");
        printf("--------------------------------------\n");
        printf(" Escolha o Sistema Operacional:\n\n");
        printf(" 1 - Windows\n");
        printf(" 2 - UNIX/Linux\n");
        printf("--------------------------------------\n");
        printf("OPCAO: ");
        scanf("%d", &res);

    }
    res--;
    if (res == WIN)
    {
        LWIN;
        return 0;
    }
    LLUX;
    return 1;
}

//função que exibe o menú principal
int menu_princ(void)
{
    int res = -1;

    while (res < 1 || res > 3)
    {
        printf("--------------------------------------\n\n");
        printf("              SGCA - INF              \n\n");
        printf("--------------------------------------\n");
        printf(" Esolha uma das seguintes opçõess:\n\n");
        printf(" 1 - Gerenciar Disciplinas\n");
        printf(" 2 - Gerenciar Alunos\n");
        printf(" 3 - Sair\n");
        printf("--------------------------------------\n");
        printf("OPCAO: ");
        scanf("%d", &res);

        limp_tela();
    }

    return res;
}

//função para o menú das disciplinas
void ger_disc(void)
{
    int res = 0;

    while (res != 5)
    {
        res = 0;
        while (res < 1 || res > 5)
        {
            printf("--------------------------------------\n\n");
            printf("     GERENCIADOR DE DISCIPLINAS       \n\n");
            printf("--------------------------------------\n");
            printf(" Esolha uma das seguintes opções:\n\n");
            printf(" 1 - Inserir Disciplina\n");
            printf(" 2 - Pesquisar Disciplina\n");
            printf(" 3 - Atualizar Disciplina\n");
            printf(" 4 - Remover Disciplina\n");
            printf(" 5 - Sair\n");
            printf("--------------------------------------\n");
            printf("OPCAO: ");
            scanf("%d", &res);
	        limp_tela();

        }


        switch (res)
        {
            case 1:
                inserir(DIS);
                break;
            case 2:
		        pesquisar(DIS);
                break;
            case 3:
                atuali(DIS);
                break;
            case 4:
                remover(DIS);
                break;
        }

	limp_tela();
    }
}

//função para o menú de alunos
void ger_alu(void)
{
   int res = 0;

    while (res != 5)
    {
        res = 0;
        while (res < 1 || res > 5)
        {
            printf("--------------------------------------\n\n");
            printf("        GERENCIADOR DE ALUNOS         \n\n");
            printf("--------------------------------------\n");
            printf(" Esolha uma das seguintes opções:\n\n");
            printf(" 1 - Inserir Aluno\n");
            printf(" 2 - Pesquisar Aluno\n");
            printf(" 3 - Atualizar dados do Aluno\n");
            printf(" 4 - Remover Aluno\n");
            printf(" 5 - Sair\n");
            printf("--------------------------------------\n");
            printf("OPCAO: ");
            scanf("%d", &res);

	        limp_tela();
        }


        switch (res)
        {
            case 1:
                inserir(ALU);
                break;
            case 2:
		pesquisar(ALU);
                break;
            case 3:
                atuali(ALU);
                break;
            case 4:
                remover(ALU);
                break;
        }

	limp_tela();
    }

}

//função para a inserção de conteúdo no arquivos
void inserir(int tipo)
{
    disciplina aux_dis;
    aluno aux_alu;

    char buff_nome_arquivo[CARAC_A];
    char buff_char[T_BUFF_CHAR];
    int quant_arq, quant_disc, i, j, buff_int, tam;

    printf("--------------------------------------\n\n");

    if (tipo)
    {
         strcpy(buff_nome_arquivo, A_DIS);
         printf("Quantidade de disciplinas a serem inseridas: ");
         memset(&aux_dis, 0, sizeof(aux_dis));
    }
    else
    {
        strcpy(buff_nome_arquivo, A_ALU);
        printf("Quantidade de alunos a serem inseridos: ");
        memset(&aux_alu, 0, sizeof(aux_alu));
    }

    scanf("%d", &quant_arq);
    limp_tela();
    printf("--------------------------------------\n\n");


    FILE *arquiv = fopen(buff_nome_arquivo, "ab");
    if (!arquiv)
    {
        fprintf(stderr, "Arquivo %s não pode ser aberto\n", buff_nome_arquivo);
        exit(1);
    }

    for (i = 0; i < quant_arq; i++)
    {
	if (tipo)
	{
		printf("Digite o ID da disciplina: ");
		scanf("%d", &aux_dis.id);
		getchar();

		printf("Digite o nome da disciplina: ");
		fgets(aux_dis.nome_dis, T_BUFF_CHAR, stdin);
		clear(aux_dis.nome_dis);

		aux_dis.semestre = 0;
		while (aux_dis.semestre < 1 || aux_dis.semestre > 2)
		{
			printf("Digite o semestre (1 - Para o primeiro | 2 - Para o segundo): ");
			scanf("%d", &aux_dis.semestre);
		}

		printf("Digite o ano: ");
		scanf("%d", &aux_dis.ano);

	    fwrite(&aux_dis, sizeof(aux_dis), 1, arquiv);

		printf("\n");
	}
	else
	{
		printf("Digite a matrícula do aluno(a): ");
		scanf("%d", &aux_alu.matri);
		getchar();

		printf("Digite o nome do aluno(a): ");
		fgets(aux_alu.nome, T_BUFF_CHAR, stdin);
		clear(aux_alu.nome);

		printf("Digite a idade do aluno(a): ");
		scanf("%d", &aux_alu.idade);

		printf("Digite a quantidade de disciplinas que está matriculado(a): ");
		scanf("%d", &aux_alu.quant_dis);

		for (j = 0; j < aux_alu.quant_dis; j++)
		{
			printf("Digite o ID da %d disciplina: ", j + 1);
			scanf("%d", &aux_alu.m_dis[j]);
		}
		getchar();

		printf("Digite a rua onde mora: ");
		fgets(aux_alu.ende.rua, T_BUFF_CHAR, stdin);
		clear(aux_alu.ende.rua);

		printf("Digite o bairro: ");
		fgets(aux_alu.ende.bai, T_BUFF_CHAR, stdin);
		clear(aux_alu.ende.bai);

		printf("Digite o CEP: ");
		scanf("%d", &aux_alu.ende.cep);
		getchar();

		printf("Digite a Cidade: ");
		fgets(aux_alu.ende.cty, T_BUFF_CHAR, stdin);
		clear(aux_alu.ende.cty);

		printf("Digite a Unidade Federativa (UF): ");
		fgets(aux_alu.ende.uf, SI_UF +1, stdin);
		clear(aux_alu.ende.uf);

		fwrite(&aux_alu, sizeof(aux_alu), 1, arquiv);

		printf("\n");
	}
    }

    fclose(arquiv);

}

//função para a limpeza do \n no buff_char
void clear(char str[])
{
      	int c = strlen(str);
	if (str[c - 1] == '\n') str[c - 1] = 0;
	else while(getchar() != '\n');
}

//função para a pesquisa nos arquivos (aqui ocorre a saída)
void pesquisar(int tipo)
{
    disciplina aux_dis;
    aluno aux_alu;

    int pesq, j;

    printf("--------------------------------------\n\n");

 	if (tipo)
    {
        printf("Digite o ID da Disciplina: ");
    }
    else
    {
        printf("Digite o numero de matrícula do Aluno: ");
    }


    scanf("%d", &pesq);
    limp_tela();

    if (tipo) aux_dis = pesq_dis(pesq);
    else aux_alu = pesq_alu(pesq);
    getchar();

    if (tipo && aux_dis.id == pesq)
    {
        printf("--------------------------------------\n\n");
        printf(" ID da disciplina: %d\n", aux_dis.id);
        printf(" Nome: %s\n", aux_dis.nome_dis);
        printf(" Semestre: %d\n", aux_dis.semestre);
        printf(" Ano: %d\n", aux_dis.ano);

        printf("\n\n (Aperte tecla Enter para sair)\n\n");
        printf("--------------------------------------\n\n");
        getchar();
    }
    else if (!tipo && aux_alu.matri == pesq)
    {
        printf("--------------------------------------\n\n");
        printf(" Matrícula do aluno(a): %d\n", aux_alu.matri);
        printf(" Nome do aluno(a): %s\n", aux_alu.nome);
        printf(" Idade: %d\n", aux_alu.idade);
        printf(" Quantidade de Disciplinas matriculadas: %d\n\n", aux_alu.quant_dis);
        for (j = 0; j < aux_alu.quant_dis; j++)
        {
            aux_dis = pesq_dis(aux_alu.m_dis[j]);

            if (aux_dis.id)
            {
                printf(" ID da disciplina: %d\n", aux_alu.m_dis[j]);
                printf(" Nome: %s\n", aux_dis.nome_dis);
                printf(" Semestre: %d\n", aux_dis.semestre);
                printf(" Ano: %d\n", aux_dis.ano);
                printf("\n");
            }
            else
            {
                printf(" ID da disciplina: %d\n", aux_alu.m_dis[j]);
                printf(" Disciplina Inexistente\n");
                printf("\n");
            }
        }
        printf(" Rua onde mora: %s\n", aux_alu.ende.rua);
        printf(" Bairro: %s\n", aux_alu.ende.bai);
        printf(" CEP: %d\n", aux_alu.ende.cep);
        printf(" Cidade onde mora: %s\n", aux_alu.ende.cty);
        printf(" UF: %s\n", aux_alu.ende.uf);

        printf("\n\n (Aperte tecla Enter para sair)\n\n");
        printf("--------------------------------------\n\n");
        getchar();


    }
    else if (tipo && pesq != aux_dis.id)
    {
        printf("--------------------------------------\n\n");
        printf(" Disciplina Inexistente\n");

        printf("\n\n (Aperte a tecla Enter para sair)\n\n");
        printf("--------------------------------------\n\n");
        getchar();

    }
    else
    {
        printf("--------------------------------------\n\n");
        printf(" Aluno Inexistente\n");

        printf("\n\n (Aperte a tecla Enter para sair)\n\n");
        printf("--------------------------------------\n\n");
        getchar();


    }
}

//função para a pesquisa por disciplinas (pesquisa de fato)
disciplina pesq_dis(int pesq)
{
    disciplina aux_dis;
    int j;

    FILE *arquiv = fopen(A_DIS, "rb");
    if (!arquiv)
    {
        fprintf(stderr, "Erro de execução - Verifique se existe um arquivo contendo as Disciplinas\n");
        exit(1);
    }

    aux_dis.id = -1;
    while(!feof(arquiv) && (aux_dis.id != pesq))
    {
        fread(&aux_dis, sizeof(disciplina), 1, arquiv);
    }

    fclose(arquiv);
    if (aux_dis.id == pesq) return aux_dis;
    else
    {
        aux_dis.id = 0;
        return aux_dis;
    }
}

//função para pesquisa de alunos (ocorre a pesquisa de fato)
aluno pesq_alu(int pesq)
{
    aluno aux_alu;
    int j;

    FILE *arquiv = fopen(A_ALU, "rb");
    if (!arquiv)
    {
        fprintf(stderr, "Erro de execução - Verifique se existe um arquivo contendo os Alunos\n");
        exit(1);
    }

    aux_alu.matri = -1;
    while (!feof(arquiv) && (aux_alu.matri != pesq))
    {
        fread(&aux_alu, sizeof(aluno), 1, arquiv);
    }

    fclose(arquiv);
    if (aux_alu.matri == pesq) return aux_alu;
    else
    {
        aux_alu.matri = 0;
        return aux_alu;
    }
}

//função para a remoção de conteúdo
void remover(int tipo)
{
    int pesq, inicio;
    char buff_nome_arquivo[CARAC_A];
    disciplina aux_dis;
    aluno aux_alu;

    printf("--------------------------------------\n\n");

    if (tipo)
    {
         strcpy(buff_nome_arquivo, A_DIS);
         printf("Digite o ID da Disciplina: ");
    }
    else
    {
        strcpy(buff_nome_arquivo, A_ALU);
        printf("Digite a Matrícula do Aluno: ");
    }

    scanf("%d", &pesq);
    getchar();
    printf("--------------------------------------\n\n");
    limp_tela();

    FILE *arquiv = fopen(buff_nome_arquivo, "r+b");
    if (!arquiv)
    {
        fprintf(stderr, "O arquivo %s não pode ser aberto\n", buff_nome_arquivo);
        exit(1);
    }

    if (tipo)
    {
        aux_dis.id = -1;
        while(!feof(arquiv) && (aux_dis.id != pesq))
        {
            inicio = ftell(arquiv);
            fread(&aux_dis, sizeof(disciplina), 1, arquiv);
        }

        if (aux_dis.id == pesq)
        {
            if (confirm())
    		{
    		    memset(&aux_dis, ' ', sizeof(aux_dis));
    		    fseek(arquiv, inicio, SEEK_SET);
    		    fwrite(&aux_dis, sizeof(aux_dis), 1, arquiv);
    		}
        }
        else
        {
            printf("--------------------------------------\n\n");
            printf(" Disciplina Inexistente\n");

            printf("\n\n (Aperte a tecla Enter para sair)\n\n");
            printf("--------------------------------------\n\n");
            getchar();
        }


    }
    else
    {
        aux_alu.matri = -1;
        while (!feof(arquiv) && (aux_alu.matri != pesq))
        {
            inicio = ftell(arquiv);
            fread(&aux_alu, sizeof(aluno), 1, arquiv);
        }

        if (aux_alu.matri == pesq)
        {
            if (confirm())
    		{
    		    memset(&aux_alu, ' ', sizeof(aux_alu));
    		    fseek(arquiv, inicio, SEEK_SET);
    		    fwrite(&aux_alu, sizeof(aux_alu), 1, arquiv);
    		}
        }
        else
        {
            printf("--------------------------------------\n\n");
            printf(" Aluno Inexistente\n");

            printf("\n\n (Aperte a tecla Enter para sair)\n\n");
            printf("--------------------------------------\n\n");
            getchar();
        }
    }

    fclose(arquiv);

}

//função para a atualização do conteúdo
void atuali(int tipo)
{
    int pesq, inicio, resp, j;
    char buff_nome_arquivo[CARAC_A];
    disciplina aux_dis, aux_sub_dis;
    aluno aux_alu, aux_sub_alu;

    printf("--------------------------------------\n\n");

    if (tipo)
    {
         strcpy(buff_nome_arquivo, A_DIS);
         printf("Digite o ID da Disciplina: ");
         memset(&aux_sub_dis, 0, sizeof(aux_sub_dis));
    }
    else
    {
        strcpy(buff_nome_arquivo, A_ALU);
        printf("Digite a Matrícula do Aluno: ");
        memset(&aux_sub_alu, 0, sizeof(aux_sub_alu));
    }

    scanf("%d", &pesq);
    getchar();
    limp_tela();

    FILE *arquiv = fopen(buff_nome_arquivo, "r+b");
    if (!arquiv)
    {
        fprintf(stderr, "O arquivo %s não pode ser aberto\n", buff_nome_arquivo);
        exit(1);
    }

    if (tipo)
    {
        aux_dis.id = -1;
        while(!feof(arquiv) && (aux_dis.id != pesq))
        {
            inicio = ftell(arquiv);
            fread(&aux_dis, sizeof(disciplina), 1, arquiv);
        }

        if (aux_dis.id == pesq)
        {
            printf("--------------------------------------\n\n");

            printf("Digite o ID da disciplina: ");
    		scanf("%d", &aux_sub_dis.id);
    		getchar();

    		printf("Digite o nome da disciplina: ");
    		fgets(aux_sub_dis.nome_dis, T_BUFF_CHAR, stdin);
    		clear(aux_sub_dis.nome_dis);

    		aux_sub_dis.semestre = 0;
    		while (aux_sub_dis.semestre < 1 || aux_sub_dis.semestre > 2)
    		{
    			printf("Digite o semestre (1 - Para o primeiro | 2 - Para o segundo): ");
    			scanf("%d", &aux_sub_dis.semestre);
    		}

    		printf("Digite o ano: ");
    		scanf("%d", &aux_sub_dis.ano);

    		limp_tela();

    		if (confirm())
    		{
    		    fseek(arquiv, inicio, SEEK_SET);
    		    fwrite(&aux_sub_dis, sizeof(aux_dis), 1, arquiv);
    		}

        }
        else
        {
            printf("--------------------------------------\n\n");
            printf(" Disciplina Inexistente\n");

            printf("\n\n (Aperte a tecla Enter para sair)\n\n");
            printf("--------------------------------------\n\n");
            getchar();
        }


    }
    else
    {
        aux_alu.matri = -1;
        while (!feof(arquiv) && (aux_alu.matri != pesq))
        {
            inicio = ftell(arquiv);
            fread(&aux_alu, sizeof(aluno), 1, arquiv);
        }

        if (aux_alu.matri == pesq)
        {
            printf("--------------------------------------\n\n");
            printf("Digite a matrícula do aluno(a): ");
		    scanf("%d", &aux_sub_alu.matri);
		    getchar();

		    printf("Digite o nome do aluno(a): ");
		    fgets(aux_sub_alu.nome, T_BUFF_CHAR, stdin);
		    clear(aux_sub_alu.nome);

		    printf("Digite a idade do aluno(a): ");
		    scanf("%d", &aux_sub_alu.idade);

		    printf("Digite a quantidade de disciplinas que está matriculado(a): ");
		    scanf("%d", &aux_sub_alu.quant_dis);

		    for (j = 0; j < aux_sub_alu.quant_dis; j++)
		    {
			    printf("Digite o ID da %d disciplina: ", j + 1);
			    scanf("%d", &aux_sub_alu.m_dis[j]);
		    }
		    getchar();

		    printf("Digite a rua onde mora: ");
		    fgets(aux_sub_alu.ende.rua, T_BUFF_CHAR, stdin);
		    clear(aux_sub_alu.ende.rua);

		    printf("Digite o bairro: ");
		    fgets(aux_sub_alu.ende.bai, T_BUFF_CHAR, stdin);
		    clear(aux_sub_alu.ende.bai);

		    printf("Digite o CEP: ");
		    scanf("%d", &aux_sub_alu.ende.cep);
		    getchar();

		    printf("Digite a Cidade: ");
		    fgets(aux_sub_alu.ende.cty, T_BUFF_CHAR, stdin);
		    clear(aux_sub_alu.ende.cty);

		    printf("Digite a Unidade Federativa (UF): ");
		    fgets(aux_sub_alu.ende.uf, SI_UF +1, stdin);
		    clear(aux_sub_alu.ende.uf);

		    limp_tela();

    		if (confirm())
    		{
    		    fseek(arquiv, inicio, SEEK_SET);
    		    fwrite(&aux_sub_alu, sizeof(aux_alu), 1, arquiv);
    		}
        }
        else
        {
           printf("--------------------------------------\n\n");
           printf(" Aluno Inexistente\n");

            printf("\n\n (Aperte a tecla Enter para sair)\n\n");
            printf("--------------------------------------\n\n");
            getchar();
        }
    }

    fclose(arquiv);

}

void limp_tela()
{
	if (SO) LLUX;
	else LWIN;
}

int confirm()
{
    char resp = ' ';

    while (resp != 's' && resp != 'S' && resp != 'n' && resp != 'N')
    {
        printf("--------------------------------------\n\n");
        printf("Tem certeza? - Os dados não poderão ser recuperados [S-s/N-n]: ");
        scanf("%c", &resp);
        limp_tela();
    }
    if (resp == 'n' || resp == 'N') return 0;
    else return 1;
}
