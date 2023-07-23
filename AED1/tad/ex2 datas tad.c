/*************************/
/*                               data.h                                */
/*************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Data Data;

int valido(Data *d);
Data* criaData(unsigned int dia, unsigned int mes, unsigned int ano);
Data* copiaData(Data d);
void liberaData(Data *d);
Data* somaDiasData(Data d, unsigned int dias);
Data* subtrairDiasData(Data d, unsigned int dias);
void atribuirData(Data *d, unsigned int dia, unsigned int mes, unsigned int ano);
unsigned int obtemDiaData(Data d);
unsigned int obtemMesData(Data d);
unsigned int obtemAnoData(Data d);
unsigned int bissextoData(Data d);
int comparaData(Data d1, Data d2);
unsigned int numeroDiasDatas(Data d1, Data d2);
unsigned int numeroMesesDatas(Data d1, Data d2);
unsigned int numeroAnosDatas(Data d1, Data d2);
unsigned int obtemDiaSemanaData (Data d);
char* imprimeData(Data d, char *formato);

/*****************************/
/*                                    data.c                                       */
/*****************************/

//#include "data.h"

typedef struct Data{
    unsigned int dia;
    unsigned int mes;
    unsigned int ano;
};


int valido(Data *d){

    if (d != NULL && d->dia != 0 && d->mes != 0 && d->ano != 0){
        return 1;
    }

    return 0;
}

Data* criaData(unsigned int dia, unsigned int mes, unsigned int ano){
    Data *d;

    if(ano < 1900 || ano > 2200){
        return NULL;
    }
    if(mes < 1 || mes >12){
        return NULL;
    }
    if(dia < 1 || dia > 31){
        return NULL;
    }

    if((mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12)){
        d = (Data*) malloc(sizeof(Data));
        if(d != NULL){
            d->dia = dia;
            d->mes = mes;
            d->ano = ano;
        }
    }
    else{
        if((mes == 4 || mes == 6 || mes == 9 || mes == 11) && (dia <= 30)){
            d = (Data*) malloc(sizeof(Data));
            if(d!=NULL){
                d->dia = dia;
                d->mes = mes;
                d->ano = ano;
            }

        }
        else{
            if(((mes == 2) && (dia < 29)) || ((mes == 2 && ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0)) && (dia < 30)))){
                d = (Data*) malloc(sizeof(Data));
                if(d != NULL){
                    d->dia = dia;
                    d->mes = mes;
                    d->ano = ano;
                }
            }
        }
    }

    return d;
}

Data* copiaData(Data d){
    Data *d2;

    d2 = criaData(d.dia, d.mes, d.ano);

    if(valido(d2)){
        return d2;
    }

    return NULL;
}

void liberaData(Data *d){
    if(valido(d)){
        d->ano = 0;
        d->mes = 0;
        d->dia = 0;
        free(d);
        d = NULL;
    }
}

Data* somaDiasData(Data d, unsigned int dias){// acho q ta errado
    Data *d2;

    if(valido(&d)){
        d2 = criaData(d.dia, d.mes, d.ano);

        if(dias > 0){
            d2->dia += dias;

            while(d2->dia > 28 ){
                if((d2->mes == 1 || d2->mes == 3 || d2->mes == 5 || d2->mes == 7 || d2->mes == 8 || d2->mes == 10 || d2->mes == 12) && d2->dia >= 31){
                    d2->dia -= 31;
                    d2->mes++;
                }
                else{
                    if(d2->mes != 2 && d2->dia >=30){
                        d2->dia -= 30;
                        d2->mes++;
                    }
                    else{
                        if(bissextoData(d) && d2->dia >= 29){
                            d2->dia -= 29;
                            d2->mes++;
                        }
                        else{
                            if(d2->dia >= 29){
                                d2->dia -= 28;
                                d2->mes++;
                            }
                        }
                    }
                }
            }

            while(d.mes > 12){
                d.ano++;
                d.mes -= 12;
            }
        }

        return d2;
    }
}

Data* subtrairDiasData(Data d, unsigned int dias){// ta errado
    Data *d2;

    if(valido(&d)){
        d2 = criaData(d.dia, d.mes, d.ano);

        if(dias > 0){
            d2->dia -= dias;

            while(d2->dia < 0){
                if(d2->mes-1 == 1 || d2->mes-1 == 3 || d2->mes-1 == 5 || d2->mes-1 == 7 || d2->mes-1 == 8 || d2->mes-1 == 10 || d2->mes-1 == 0){
                    d2->dia += 31;
                    d2->mes--;
                }
                else{
                    if(d2->mes-1 != 2 && d2->dia >=30){
                        d2->dia -= 30;
                        d2->mes++;
                    }
                    else{
                        if(bissextoData(d) && d2->dia >= 29){
                            d2->dia -= 29;
                            d2->mes++;
                        }
                        else{
                            if(d2->dia >= 29){
                                d2->dia -= 28;
                                d2->mes++;
                            }
                        }
                    }
                }
            }

            while(d.mes > 12){
                d.ano++;
                d.mes -= 12;
            }
        }

        return d2;
    }
}

void atribuirData(Data *d, unsigned int dia, unsigned int mes, unsigned int ano){
    if(valido(d)){
        if(ano >= 1900 && ano <= 2200){
            if(mes >= 1 && mes <= 12){
                if(dia > 0 && dia <= 31){
                    if((mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12)){
                        d->dia = dia;
                        d->mes = mes;
                        d->ano = ano;
                    }
                    else{
                        if((mes == 4 || mes == 6 || mes == 9 || mes == 11) && (dia <= 30)){
                            d->dia = dia;
                            d->mes = mes;
                            d->ano = ano;
                        }
                        else{
                            if(((mes == 2) && (dia < 29)) || ((mes == 2 && ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0)) && (dia < 30)))){
                                d->dia = dia;
                                d->mes = mes;
                                d->ano = ano;
                            }
                        }
                    }
                }
            }
        }
    }
}

unsigned int obtemDiaData(Data d){
    return d.dia;
}

unsigned int obtemMesData(Data d){
    return d.mes;
}

unsigned int obtemAnoData(Data d){
    return d.ano;
}

unsigned int bissextoData(Data d){
    if(d.ano % 4 == 0 && d.ano % 100 != 0){
        return 1;
    }

    if(d.ano % 400 == 0 && d.ano % 100 == 0){
        return 1;
    }

    return 0;
}

unsigned int bissextoDataAtt(Data d, int l){
    if((d.ano+l) % 4 == 0 && (d.ano+l) % 100 != 0){
        return 1;
    }

    if((d.ano+l) % 400 == 0 && (d.ano+l) % 100 == 0){
        return 1;
    }

    return 0;
}

int comparaData(Data d1, Data d2){
    if(d1.ano < d2.ano){
        return -1;
    }
    else{
        if(d1.ano == d2.ano){
            if(d1.mes < d2.mes){
                return -1;
            }
            else{
                if(d1.mes == d2.mes){
                    if(d1.dia < d2.dia){
                        return -1;
                    }
                    else{
                        if(d1.dia == d2.dia){
                            return 0;
                        }
                        else return 1;
                    }
                }
                else return 1;
            }
        }
        else return 1;
    }
}

unsigned int numeroDiasDatas(Data d1, Data d2){ //falta arrumar quando os anos sao diferente
    unsigned int difAno;
    unsigned int difMes;
    unsigned int somaDias = 0;
    int i;
    int mesInicial;
    int l = 0;

    difAno = numeroAnosDatas(d1, d2);
    difMes = numeroMesesDatas(d1, d2);

    if(difAno == 0){
        if(difMes == 0){
            if(d1.dia == d2.dia){
                return 0;
            }
            else{
                if(d1.dia > d2.dia){
                    return d1.dia - d2.dia;
                }
                else return d2.dia - d1.dia;
            }
        }
        else{
            if(d1.mes > d2.mes){
                for(i = d2.mes; i < d1.mes; i++){
                    if((i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)){
                        somaDias += 31;
                    }
                    if((i == 4 || i == 6 || i == 9 || i == 11)){
                        somaDias += 30;
                    }
                    if(i == 2){
                        if(bissextoData(d1)){
                            somaDias += 29;
                        }
                        else    somaDias += 28;
                    }
                }
                return somaDias += d2.dia - d1.dia;
            }
            else{
                for(i = d1.mes; i < d2.mes; i++){
                    if((i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)){
                        somaDias += 31;
                    }
                    if((i == 4 || i == 6 || i == 9 || i == 11)){
                        somaDias += 30;
                    }
                    if(i == 2){
                        if(bissextoData(d1)){
                            somaDias += 29;
                        }
                        else    somaDias += 28;
                    }
                }
                return somaDias += d1.dia - d2.dia;
            }
        }
    }
    else{
        if(d1.ano < d2.ano){
            mesInicial = d1.mes;

            for(i = d1.mes; i <= difMes;){
                if((i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)){
                    somaDias += 31;
                }
                if((i == 4 || i == 6 || i == 9 || i == 11)){
                    somaDias += 30;
                }
                if(i == 2){
                    if(bissextoDataAtt(d1, l)){
                        somaDias += 29;
                    }
                    else    somaDias += 28;
                }

                i++;
                if(i == 13){
                    i = 1;
                    difMes = difMes - (12 - mesInicial);
                    if(mesInicial){
                        somaDias -= 31;
                    }
                    mesInicial = 0;
                    difAno--;
                    l++;
                }
                if(i > difMes && difAno >= 1){
                    i = 1;
                    difMes = difMes - (12 - mesInicial);
                    mesInicial = 0;
                    difAno--;
                    l++;
                }
            }
            somaDias += (d2.dia-d1.dia);
        }
        else{
            mesInicial = d2.mes;
            for(i = d2.mes; i <= difMes;){
                if((i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)){
                    somaDias += 31;
                }
                if((i == 4 || i == 6 || i == 9 || i == 11)){
                    somaDias += 30;
                }
                if(i == 2){
                    if(bissextoDataAtt(d2, l)){
                        somaDias += 29;
                    }
                    else    somaDias += 28;
                }

                i++;
                if(i == 13){
                    i = 1;
                    difMes = difMes - (12 - mesInicial);
                    if(mesInicial){
                        somaDias -= 31;
                    }
                    mesInicial = 0;
                    difAno--;
                    l++;
                }
                if(i > difMes && difAno >= 1){
                    i = 1;
                    difMes = difMes - (12 - mesInicial);

                    mesInicial = 0;
                    difAno--;
                    l++;
                }
            }
            somaDias += d1.dia;
        }
    }

    return somaDias;
}

unsigned int numeroMesesDatas(Data d1, Data d2){
    unsigned int difAno;
    unsigned int quantM1;
    unsigned int quantM2;

    difAno = numeroAnosDatas(d1, d2);

    if(difAno == 0){
        if(d1.mes == d2.mes){
            return 0;
        }
        else{
            if(d1.mes > d2.mes){
                return d1.mes - d2.mes;
            }
            else return d2.mes - d1.mes;
        }
    }
    else{
        if(d1.ano < d2.ano){
            quantM1 = d1.mes;
            quantM2 = 12*difAno + d2.mes;

            return quantM2 - quantM1;
        }
        else{
            quantM2 = d2.mes;
            quantM1 = 12*difAno + d1.mes;

            return quantM1 - quantM2;
        }
    }
}

unsigned int numeroAnosDatas(Data d1, Data d2){
    if(d1.ano == d2.ano){
        return 0;
    }
    else{
        if(d1.ano > d2.ano){
            return d1.ano - d2.ano;
        }
        else return d2.ano - d1.ano;
    }
}

unsigned int obtemDiaSemanaData (Data d){
    int dia;
    int mes;
    int ano;
    int dia_semana;
    int formula;
    int k;
    int j;

    ano = d.ano;
    mes = d.mes;
    dia = d.dia;

    if(mes == 01 ){
        mes = 13;
        ano = ano - 1;
    }

    if(mes == 02 ){
        mes = 14;
        ano = ano - 1;
    }

    k = ano % 100;
    j = ano / 100;

    formula = dia + ((26 * (mes + 1)) / 10) + k + k/4 + j/4 + 5*j;
    dia_semana = formula % 7;

    dia_semana = ((dia_semana + 5) % 7) + 1;

    return dia_semana;
}

char* imprimeData(Data d, char *formato){
    char *stringData;

    stringData = malloc(sizeof(char));

    if(!strcmp("ddmmaaaa", formato)){
        sprintf(stringData, "%02d/%02d/%04d\0", d.dia, d.mes, d.ano);

        return stringData;
    }
    else if(!strcmp("aaaammdd", formato)){
        sprintf(stringData, "%04d/%02d/%02d\0",  d.ano, d.mes, d.dia);

        return stringData;
    }
    else if(!strcmp("aaaa", formato)){
        sprintf(stringData, "%04d\0", d.ano);

        return stringData;
    }
    else if(!strcmp("mm", formato)){
        sprintf(stringData, "%02d\0", d.mes);

        return stringData;
    }
    else if(!strcmp("dd", formato)){
        sprintf(stringData, "%02d\0", d.dia);

        return stringData;
    }
    else if(!strcmp("ddmm", formato)){
        sprintf(stringData, "%02d/%02d\0", d.dia, d.mes);

        return stringData;
    }
}

/***************************/
/*                                     main.c                                    */
/***************************/

int main(){
    int i;
    int j;
    int dia;
    int mes;
    int ano;
    Data *datas[100] = {NULL};
    char *formato;
    Data *d1;
    int opcao = 1;

    formato = malloc(sizeof(char));

    while(opcao != 0){
        printf("\n\n------------------------------------- Menu -------------------------------------\n");
        printf("01 - criar data.\n");
        printf("02 - copiar data.\n");
        printf("03 - liberar data.\n");
        printf("04 - atribui data.\n");
        printf("05 - obtem dia da data\n");
        printf("06 - obtem mes da data.\n");
        printf("07 - obtem ano da data.\n");
        printf("08 - verifica se a data eh bissexta.\n");
        printf("09 - compara data.\n");
        printf("10 - diferenca em dias de duas datas.\n");
        printf("11 - diferenca em meses de duas datas.\n");
        printf("12 - diferenca em anos de duas datas.\n");
        printf("13 - obtem o dia da semana.\n");
        printf("14 - mostrar a data.\n");

        printf("00 - para parar o programa.\n");
        printf("\nDigite uma opcao: ");

        scanf("%d", &opcao);

        switch(opcao){
            case 1:
                printf("digite o indice da data a ser criada 1 - 100: ");
                scanf("%d", &i);
                printf("digite o dia: ");
                scanf("%d", &dia);
                printf("digite o mes: ");
                scanf("%d", &mes);
                printf("digite o ano: ");
                scanf("%d", &ano);
                datas[i-1] = criaData(dia, mes, ano);
                if(valido(datas[i-1])){
                    printf("data criada com sucesso!\n");
                }
                else printf("data nao criada\n");

                break;
            case 2:
                printf("digite o indice da data a ser copiada 1 - 100: ");
                scanf("%d", &i);
                printf("digite o indice da data que sera a copia 1 - 100: ");
                scanf("%d", &j);
                if(!valido(datas[i-1])){
                    printf("valor invalido.\n");
                    break;
                }
                datas[j-1] = copiaData((*datas[i-1]));
                if(valido(datas[j-1])){
                    printf("copia realizada.\n");
                }
                else printf("copia nao realizada.\n");

                break;
            case 3:
                printf("digite o indice da data a ser excluida 1 - 100: ");
                scanf("%d", &i);

                if(!valido(datas[i-1])){
                    printf("data nao excluida.\n");
                    break;
                }
                liberaData(datas[i-1]);

                if(!valido(datas[i-1])){
                    printf("data excluida.\n");
                }
                else printf("data nao excluida.\n");

                break;
            case 4:
                printf("digite o indice da data a ser atribuida 1 - 100: ");
                scanf("%d", &i);
                printf("digite o dia: ");
                scanf("%d", &dia);
                printf("digite o mes: ");
                scanf("%d", &mes);
                printf("digite o ano: ");
                scanf("%d", &ano);
                if(valido(datas[i-1])){
                    atribuirData(datas[i-1], dia, mes, ano);
                }
                if(valido(datas[i-1])){
                    printf("data atribuida.\n");
                }
                else printf("valor invalido.\n");

                break;
            case 5:
                printf("digite o indice da data a ser mostrada o dia 1 - 100: ");
                scanf("%d", &i);
                if(valido(datas[i-1])){
                    printf("dia da data eh: %s\n", imprimeData((*datas[i-1]), "dd"));
                }
                else printf("valor invalido.\n");

                break;
            case 6:
                printf("digite o indice da data a ser mostrada o mes 1 - 100: ");
                scanf("%d", &i);
                if(valido(datas[i-1])){
                    printf("mes da data eh: %s\n", imprimeData((*datas[i-1]), "mm"));
                }
                else printf("valor invalido.\n");

                break;
            case 7:
                printf("digite o indice da data a ser mostrada o ano 1 - 100: ");
                scanf("%d", &i);
                if(valido(datas[i-1])){
                    printf("ano da data eh: %s\n", imprimeData((*datas[i-1]), "aaaa"));
                }
                else printf("valor invalido.\n");

                break;
            case 8:
                printf("digite o indice da data a ser verificado se eh bissexto 1 - 100: ");
                scanf("%d", &i);
                if(!valido(datas[i-1])){
                    printf("valor invalido.\n");
                    break;
                }
                if(bissextoData((*datas[i-1]))){
                    printf("\nA data ( %s ) eh bissexta\n", imprimeData((*datas[i-1]), "ddmmaaaa"));
                }
                else {
                    printf("\nA data ( %s ) nao eh bissexta\n", imprimeData((*datas[i-1]), "ddmmaaaa"));
                }

                break;
            case 9:
                printf("digite o indice da data a ser comparada 1 - 100: ");
                scanf("%d", &i);
                printf("digite o indice da data segunda data a ser comparada ");
                scanf("%d", &j);
                if(!valido(datas[i-1])){
                    printf("valor invalido.\n");
                    break;
                }
                if(comparaData((*datas[i-1]),(*datas[j-1])) == -1){
                    printf("\n\na data 1 eh menor que a data 2");
                }
                if(comparaData((*datas[i-1]),(*datas[j-1])) == 0){
                    printf("\n\nas datas sao iguais");
                }
                if(comparaData((*datas[i-1]),(*datas[j-1])) == 1){
                    printf("\n\na data 1 eh maior que a data 2");
                }

                break;
            case 10:
                printf("digite o indice da data a ser comparada 1 - 100: ");
                scanf("%d", &i);
                printf("digite o indice da data segunda data a ser comparada ");
                scanf("%d", &j);
                if(!valido(datas[i-1])){
                    printf("valor invalido.\n");
                    break;
                }
                printf("\nA diferenca em dias das duas data eh de: %u dias", numeroDiasDatas((*datas[i-1]), (*datas[j-1])));

                break;
            case 11:
                printf("digite o indice da data a ser comparada 1 - 100: ");
                scanf("%d", &i);
                printf("digite o indice da data segunda data a ser comparada ");
                scanf("%d", &j);
                if(!valido(datas[i-1])){
                    printf("valor invalido.\n");
                    break;
                }
                printf("\nA diferenca em meses das duas data eh de: %u meses", numeroMesesDatas((*datas[i-1]), (*datas[j-1])));

                break;
            case 12:
                printf("digite o indice da data a ser comparada 1 - 100: ");
                scanf("%d", &i);
                printf("digite o indice da data segunda data a ser comparada ");
                scanf("%d", &j);
                if(!valido(datas[i-1])){
                    printf("valor invalido.\n");
                    break;
                }
                printf("\nA diferenca em anos das duas data eh de: %u anos", numeroAnosDatas((*datas[i-1]), (*datas[j-1])));

                break;
            case 13:
                printf("digite o indice da data a ser calculado o dia da semana 1 - 100: ");
                scanf("%d", &i);

                if(!valido(datas[i-1])){
                    printf("valor invalido.\n");
                    break;
                }
                switch(obtemDiaSemanaData((*datas[i-1]))){
                    case 1:
                        printf("\n\ne segunda-feira\n");
                    break;

                    case 2:
                        printf("\n\ne terca-feira\n");
                    break;

                    case 3:
                        printf("\n\ne quarta-feira\n");
                    break;

                    case 4:
                        printf("\n\ne quinta-feira\n");
                    break;

                    case 5:
                        printf("\n\ne Sexta-feira\n");
                    break;

                    case 6:
                        printf("\n\ne Sabado\n");
                    break;

                    case 7:
                        printf("\n\ne Domingo\n");
                    break;
                }

                break;
            case 14:
                printf("digite o indice da data a ser mostrada 1 - 100: ");
                scanf("%d", &i);
                printf("digite o formato a ser mostrado.\n");
                printf("dd/mm/aaaa\n");
                printf("aaaa/mm/dd\n");
                printf("aaaa\n");
                printf("mm\n");
                printf("dd\n");
                printf("mm/dd\n");
                scanf("%s", formato);
                if(!valido(datas[i-1])){
                    printf("valor invalido.\n");
                    break;
                }
                printf("\nA data eh: %s \n", imprimeData((*datas[i-1]), formato));

                break;
        }

    }

/*

    datas[0] = criaData(1, 01, 2001);

        printf("\n\nfim1");

    if(valido(&datas[0])){
        printf("formato ( ddmmaaaa ) : %s\n", imprimeData((*datas[0]), "ddmmaaaa"));
        printf("formato ( aaaammdd ) : %s\n", imprimeData((*datas[0]), "aaaammdd"));
        printf("formato ( aaaa ) : %s\n", imprimeData((*datas[0]), "aaaa"));
        printf("formato ( mm ) : %s\n", imprimeData((*datas[0]), "mm"));
        printf("formato ( dd ) : %s\n", imprimeData((*datas[0]), "dd"));
    }

    datas[1] = copiaData((*datas[0]));

    printf("\n\nfim2");

    if(valido(&datas[1])){
        printf("\n\nformato ( ddmmaaaa ) : %s\n", imprimeData((*datas[1]), "ddmmaaaa"));
        printf("formato ( aaaammdd ) : %s\n", imprimeData((*datas[1]), "aaaammdd"));
        printf("formato ( aaaa ) : %s\n", imprimeData((*datas[1]), "aaaa"));
        printf("formato ( mm ) : %s\n", imprimeData((*datas[1]), "mm"));
        printf("formato ( dd ) : %s\n", imprimeData((*datas[1]), "dd"));
    }
    printf("\n\nfim3");

    datas[2] = copiaData((*datas[0]));
    atribuirData(datas[2], 1, 3, 2001);

    if(valido(&datas[2])){
        printf("\n\nformato ( ddmmaaaa ) : %s\n", imprimeData((*datas[2]), "ddmmaaaa"));
        printf("formato ( aaaammdd ) : %s\n", imprimeData((*datas[2]), "aaaammdd"));
        printf("formato ( aaaa ) : %s\n", imprimeData((*datas[2]), "aaaa"));
        printf("formato ( mm ) : %s\n", imprimeData((*datas[2]), "mm"));
        printf("formato ( dd ) : %s\n", imprimeData((*datas[2]), "dd"));
    }

    printf("\n\ndia: %d\n", obtemDiaData((*datas[2])));
    printf("mes: %d\n", obtemMesData((*datas[2])));
    printf("ano: %d\n\n", obtemAnoData((*datas[2])));

    if(bissextoData((*datas[2]))){
        printf("\nformato ( ddmmaaaa ) : %s\n", imprimeData((*datas[2]), "ddmmaaaa"));
        printf("o ano eh bissesto.");
    }
    else {
        printf("o ano nao eh bissesto.");
        printf("\nformato ( ddmmaaaa ) : %s\n", imprimeData((*datas[2]), "ddmmaaaa"));
    }

    if(comparaData((*datas[1]),(*datas[2])) == -1){
        printf("\n\na data1 eh menor que a data2");
    }
    if(comparaData((*datas[1]),(*datas[0])) == 0){
        printf("\n\nas datas sao iguais");
    }
    if(comparaData((*datas[2]),(*datas[1])) == 1){
        printf("\n\na data1 eh maior que a data2");
    }

    printf("\n\na diferenca de anos da data1 para a data2 eh: %d", numeroAnosDatas((*datas[0]),(*datas[1])));
    printf("\na diferenca de anos da data1 para a data2 eh: %d", numeroAnosDatas((*datas[0]),(*datas[2])));

    printf("\n\na diferenca de meses da data1 para a data2 eh: %d", numeroMesesDatas((*datas[0]),(*datas[1])));
    printf("\na diferenca de meses da data1 para a data2 eh: %d", numeroMesesDatas((*datas[0]),(*datas[2])));

    printf("\n\na diferenca de dias da data1 para a data2 eh: %d", numeroDiasDatas((*datas[0]),(*datas[1])));
    printf("\na diferenca de dias da data1 para a data2 eh: %d", numeroDiasDatas((*datas[0]),(*datas[2])));

    switch(obtemDiaSemanaData((*datas[0]))){
        case 1:
            printf("\n\né uma segunda-feira\n");
        break;

        case 2:
            printf("\n\né uma terça-feira\n");
        break;

        case 3:
            printf("\n\né uma quarta-feira\n");
        break;

        case 4:
            printf("\n\né uma quinta-feira\n");
        break;

        case 5:
            printf("\n\né uma Sexta-feira\n");
        break;

        case 6:
            printf("\n\né um Sábado\n");
        break;

        case 7:
            printf("\n\né um Domingo\n");
        break;
    }
*/
}
