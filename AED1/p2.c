#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STR_MAX_LEN 100
#define SUCESSO 1
#define FALHA 0
enum casas
{
    centena = 1,
    dezena,
    unidade
};

typedef struct Rua *PonteiroRua;
typedef struct head Head;

typedef struct Rua
{
    char direcao;
    char *nome;
    int tamanhoNome;
    PonteiroRua prox;
} Rua;

typedef struct head
{
    Rua *inicial;
} cabeca;

PonteiroRua criaCaminho();
void insereRua(Head *caminho, Rua NovaRua);
void inverteDirecaoCaminho(Head* caminho);
int FormataNome(Rua* rua);
char* NumeroPorExtenso(int tamanhoNome, char* nome);
char* AlocaMemoriaParaNome(char* nome,int TamanhoNovo);
void reverse(PonteiroRua *caminho);


#include <stdio.h>
#include <stdlib.h>
#include <string.h>



// cria a pilha que representa o caminho
//@param *caminho caminho a ser seguido
//@return 1 sucesso ao criar o caminho -1 para falha
PonteiroRua criaCaminho()
{
    Rua *no = NULL;

    no = (Rua *)malloc(sizeof(Rua));

    if (no)
    {
        no->direcao = 0;
        no->nome = NULL;
        no->tamanhoNome = 0;
        no->prox = NULL;
    }

    return no;
}
// insere uma rua no caminho
//@param *caminho a se seguir
//@param rua rua a ser adicionada
//@return 1 caso sucesso -1 caso falha
void insereRua(Head *caminho, Rua novaRua) //recebe a nova rua a ser inserida
{
    Rua *x = criaCaminho();

    x->direcao = novaRua.direcao;
    
    x->nome = (char*)malloc(sizeof(char)*novaRua.tamanhoNome);
    strcpy(x->nome, novaRua.nome);
    x->tamanhoNome = novaRua.tamanhoNome;

    if (caminho->inicial == NULL)
    {
        caminho->inicial = x;
    }
    else
    {
        Rua *h = caminho->inicial;
        while (h->prox != NULL)
        {
            h = h->prox;
        }
        h->prox = x;
    }
}
// inverte o caminho direita vira esquerda e vise versa
//@param *caminho a ser invertido
//@retorna um endereço para o caminho de volta
void inverteDirecaoCaminho(Head* caminho)
{
    PonteiroRua proximaRua = NULL;
    proximaRua = (caminho->inicial)->prox;
    while(1)
    {
        if(proximaRua->prox == NULL)
        {
            switch (proximaRua->direcao)
            {
            case 'e':
                printf("Vire a DIREITA na sua CASA\n");
                break;
            case 'd':
                printf("Vire a ESQUERDA na sua CASA\n");
                break;

            } 
            break;
        }
        else
            switch(proximaRua->direcao)
            {
                case 'e':
                    printf("Vire a DIREITA na rua %s\n", proximaRua->nome);
                    break;
                case 'd':
                    printf("Vire a ESQUERDA na rua %s\n", proximaRua->nome);
                    break;
            }
        proximaRua = proximaRua->prox;
    }
}

// formata o nome recebido da rua para a forma que deve ser imprimida ao final
//@param rua rua a ter o nome formatado
int FormataNome(Rua* rua)
{
    int i;
    int somenteNumero = 1;

    for (i = 0; i < rua->tamanhoNome; i++)
        if (rua->nome[i] >= 'a' && 'z' >= rua->nome[i])
        {
            rua->nome[i] -= 32;
            somenteNumero = 0;
        }
    if (somenteNumero)
        NumeroPorExtenso(rua->tamanhoNome, rua->nome);
}
char *AlocaMemoriaParaNome(char *nome, int TamanhoNovo)
{
    printf("test1\n");
    char* nomeNovo;

    nomeNovo = (char*)malloc(TamanhoNovo * sizeof(char));
    printf("test2\n");
    strcpy(nomeNovo, nome);
    printf("test3\n");
    free(nome);
    printf("teste\n");
    if (nomeNovo)
    {
        printf("funciona\n");
        return nomeNovo;
    }

    else
        return FALHA;
}
// transforma um numero normal para por extenso
//@param rua rua que tera o nome transformado em extenso
//@return 1 para sucesso e 0 para falha
char* NumeroPorExtenso(int tamanhoNome, char* nome)
{
    int i;
    char *nomeFormatado = (char*)malloc(sizeof(char));
    nomeFormatado[0] = '\0';
    int novoTamanho = 1;
    int casa;
    

    for (i = 0; i < tamanhoNome; i++)
    {
        if (tamanhoNome == 4) //ve o tamanho do numero, a maior casa que um numero pode ter é a centena
        {
            switch (i)//ve em qual casa o indice esta
            {
            case 0:
                casa = centena;
                break;
            case 1:
                casa = dezena;
                break;
            case 2:
                casa = unidade;
                break;
            }
        }
        else if (tamanhoNome == 3)//ve se o numero so vai até as dezenas 
        {
            switch (i)//ve em qual casa o indice esta
            {
            case 0:
                casa = dezena;
                break;
            case 1:
                casa = unidade;
                break;
            }
        }
        else
            casa = unidade;//se o numero na não tiver tamanho 4 e nem 3 ele so pode ser um numero unitario
        printf("teste 5\n");
        if (casa == centena)//caso a casa for a centena
        {
            if (nome[1] == '0' && nome[2] == '0')//caso a casa decimal e unidade sejam 0
            {
                novoTamanho += 3;
                nomeFormatado = AlocaMemoriaParaNome(nomeFormatado, novoTamanho);
                strcat(nomeFormatado, "CEM");
            }
            else
            {
                switch (nome[i] - 48)//para cada valor possivel para o algarismo da centena 
                {
                case 1:
                    novoTamanho += 5;
                    nomeFormatado = AlocaMemoriaParaNome(nomeFormatado, novoTamanho);
                    strcat(nomeFormatado, "CENTO");
                    break;
                case 2:
                    novoTamanho += 8;
                    nomeFormatado = AlocaMemoriaParaNome(nomeFormatado, novoTamanho);
                    strcat(nomeFormatado, "DUZENTOS");
                    break;
                case 3:
                    novoTamanho += 9;
                    nomeFormatado = AlocaMemoriaParaNome(nomeFormatado, novoTamanho);
                    strcat(nomeFormatado, "TREZENTOS");
                    break;
                case 4:
                    novoTamanho += 12;
                    nomeFormatado = AlocaMemoriaParaNome(nomeFormatado, novoTamanho);
                    strcat(nomeFormatado, "QUATROCENTOS");
                    break;
                case 5:
                    novoTamanho += 10;
                    nomeFormatado = AlocaMemoriaParaNome(nomeFormatado, novoTamanho);
                    strcat(nomeFormatado, "QUINHENTOS");
                    break;
                case 6:
                    novoTamanho += 11;
                    nomeFormatado = AlocaMemoriaParaNome(nomeFormatado, novoTamanho);
                    strcat(nomeFormatado, " SEISCENTOS");
                    break;
                case 7:
                    novoTamanho += 10;
                    nomeFormatado = AlocaMemoriaParaNome(nomeFormatado, novoTamanho);
                    strcat(nomeFormatado, "SETECENTOS");
                    break;
                case 8:
                    novoTamanho += 10;
                    nomeFormatado = AlocaMemoriaParaNome(nomeFormatado, novoTamanho);
                    strcat(nomeFormatado, "OITOCENTOS");
                    break;
                case 9:
                    novoTamanho += 10;
                    nomeFormatado = AlocaMemoriaParaNome(nomeFormatado, novoTamanho);
                    strcat(nomeFormatado, "NOVECENTOS");
                    break;
                }
                if(nome[1] != 0 && nome[2] != 0)//se a dezena e a unidade não forem zero, adicione " E " após adicionar a centena por escrito
                {
                    novoTamanho += 3;
                    nomeFormatado = AlocaMemoriaParaNome(nomeFormatado, novoTamanho);
                    strcat(nomeFormatado, " E ");
                }
            }
            
        }
        if (casa == dezena)//testa as dezenas
        {
            if ((nome[i] - 48) == 1)//caso especial em que a dezena é igual a um, logo não seguindo o padrão de nomeação
            {
                switch (nome[i + 1] - 1)
                {
                case 0:
                    novoTamanho += 3;
                    nomeFormatado = AlocaMemoriaParaNome(nomeFormatado, novoTamanho);
                    strcat(nomeFormatado, "DEZ");
                    break;
                case 1:
                    novoTamanho += 4;
                    nomeFormatado = AlocaMemoriaParaNome(nomeFormatado, novoTamanho);
                    strcat(nomeFormatado, "ONZE");
                    break;
                case 2:
                    novoTamanho += 4;
                    nomeFormatado = AlocaMemoriaParaNome(nomeFormatado, novoTamanho);
                    strcat(nomeFormatado, "DOZE");
                    break;
                case 3:
                    novoTamanho += 5;
                    nomeFormatado = AlocaMemoriaParaNome(nomeFormatado, novoTamanho);
                    strcat(nomeFormatado, "TREZE");
                    break;
                case 4:
                    novoTamanho += 8;
                    nomeFormatado = AlocaMemoriaParaNome(nomeFormatado, novoTamanho);
                    strcat(nomeFormatado, "QUATORZE");
                    break;
                case 5:
                    novoTamanho += 6;
                    nomeFormatado = AlocaMemoriaParaNome(nomeFormatado, novoTamanho);
                    strcat(nomeFormatado, "QUINZE");
                    break;
                case 6:
                    novoTamanho += 9;
                    nomeFormatado = AlocaMemoriaParaNome(nomeFormatado, novoTamanho);
                    strcat(nomeFormatado, "DEZESSEIS");
                    break;
                case 7:
                    novoTamanho += 9;
                    nomeFormatado = AlocaMemoriaParaNome(nomeFormatado, novoTamanho);
                    strcat(nomeFormatado, "DEZESSETE");
                    break;
                case 8:
                    novoTamanho += 7;
                    nomeFormatado = AlocaMemoriaParaNome(nomeFormatado, novoTamanho);
                    strcat(nomeFormatado, "DEZOITO");
                    break;
                case 9:
                    novoTamanho += 8;
                    nomeFormatado = AlocaMemoriaParaNome(nomeFormatado, novoTamanho);
                    strcat(nomeFormatado, "DEZENOVE");
                    break;
                }
            }
            else if((nome[i] - 48) != 0)//caso normal(inacabado)
            {
                switch (nome[i] - 48)
                {
                case 2:
                    novoTamanho += 5;
                    nomeFormatado = AlocaMemoriaParaNome(nomeFormatado, novoTamanho);
                    strcat(nomeFormatado, "VINTE");
                    break;
                case 3:
                    novoTamanho += 6;
                    nomeFormatado = AlocaMemoriaParaNome(nomeFormatado, novoTamanho);
                    strcat(nomeFormatado, "TRINTA");
                    break;
                case 4:
                    novoTamanho += 8;
                    nomeFormatado = AlocaMemoriaParaNome(nomeFormatado, novoTamanho);
                    strcat(nomeFormatado, "QUARENTA");
                    break;
                case 5:
                    novoTamanho += 9;
                    nomeFormatado = AlocaMemoriaParaNome(nomeFormatado, novoTamanho);
                    strcat(nomeFormatado, "CINQUENTA");
                    break;
                case 6:
                    novoTamanho += 8;
                    nomeFormatado = AlocaMemoriaParaNome(nomeFormatado, novoTamanho);
                    strcat(nomeFormatado, "SESSENTA");
                    break;
                case 7:
                    novoTamanho += 7;
                    nomeFormatado = AlocaMemoriaParaNome(nomeFormatado, novoTamanho);
                    strcat(nomeFormatado, "SETENTA");
                    break;
                case 8:
                    novoTamanho += 7;
                    nomeFormatado = AlocaMemoriaParaNome(nomeFormatado, novoTamanho);
                    strcat(nomeFormatado, "OITENTA");
                    break;
                case 9:
                    novoTamanho += 7;
                    nomeFormatado = AlocaMemoriaParaNome(nomeFormatado, novoTamanho);
                    strcat(nomeFormatado, "NOVENTA");
                    break;
                }
            } 
        } 
        if (casa == unidade)//caso das unidades(incabado)
        {
            printf("testee unidade\n");
            switch (nome[i] - 48)
            {
            case 0:
                if (tamanhoNome == 2)
                {
                    novoTamanho += 4;
                    nomeFormatado = AlocaMemoriaParaNome(nomeFormatado, novoTamanho);
                    strcat(nomeFormatado,"ZERO");
                }
                break;
            case 1:
                printf("funciona 1\n");
                novoTamanho += 2;
                nomeFormatado = AlocaMemoriaParaNome(nomeFormatado, novoTamanho);
                strcat(nomeFormatado, "UM");
                break;
            case 2:
                novoTamanho += 4;
                nomeFormatado = AlocaMemoriaParaNome(nomeFormatado, novoTamanho);
                strcat(nomeFormatado, "DOIS");
                break;
            case 3:
                novoTamanho += 4;
                nomeFormatado = AlocaMemoriaParaNome(nomeFormatado, novoTamanho);
                strcat(nomeFormatado, "TRES");
                break;
            case 4:
                novoTamanho += 6;
                nomeFormatado = AlocaMemoriaParaNome(nomeFormatado, novoTamanho);
                strcat(nomeFormatado, "QUATRO");
                break;
            case 5:
                novoTamanho += 5;
                nomeFormatado = AlocaMemoriaParaNome(nomeFormatado, novoTamanho);
                strcat(nomeFormatado, "CINCO");
                break;
            case 6:
                novoTamanho += 4;
                nomeFormatado = AlocaMemoriaParaNome(nomeFormatado, novoTamanho);
                strcat(nomeFormatado, "SEIS");
                break;
            case 7:
                novoTamanho += 4;
                nomeFormatado = AlocaMemoriaParaNome(nomeFormatado, novoTamanho);
                strcat(nomeFormatado, "SETE");
                break;
            case 8:
                novoTamanho += 4;
                nomeFormatado = AlocaMemoriaParaNome(nomeFormatado, novoTamanho);
                strcat(nomeFormatado, "OITO");
                break;
            case 9:
                novoTamanho += 4;
                nomeFormatado = AlocaMemoriaParaNome(nomeFormatado, novoTamanho);
                strcat(nomeFormatado, "NOVE");
                break;
            }

        }
    }

    printf("%s\n", nomeFormatado);
    return nomeFormatado;
}




int main()
{
    Head *caminho = (Head*)malloc(sizeof(Head));
    PonteiroRua proxRua;
    caminho->inicial = NULL;
    Rua novaRua;
    novaRua.nome = (char*)malloc(sizeof(char)*100);

    while(1) {
        novaRua.tamanhoNome = 100;
        scanf("%c %s%*c", &novaRua.direcao, novaRua.nome);

        insereRua(caminho, novaRua);
        if(strcmp(novaRua.nome, "e") == 0) break;
    }
    proxRua = caminho->inicial;
    while(proxRua->prox) {
        printf("%c %s\n", proxRua->direcao, proxRua->nome);
        proxRua = proxRua->prox;
    }
    
    inverteDirecaoCaminho(caminho);
    

    return 0;
}