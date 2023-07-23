#include <stdlib.h>

void COMPLEXOlibera(Complexo *z)
{

    // verificando se o struct complexo ja foi liberado, ou se ainda á algum valor
    if (z != NULL)
    {
        // liberando a parte real
        free((z)->re);
        // liberando a parte imaginaria
        free((z)->im);
        // liberando struct por total
        free((z));
        // atribuindo NULL na struct complexo e saindo da condicional e finalizando a liberação
        (z) = NULL;
    }
}

Complexo *COMPLEXOcria(float real, float imag)
{

    // criando um struct do tipo complexo
    Complexo *z;
    // atribui null pra evitar a utilização de um lixo de memoria, na struct complexo z
    z = NULL;
    // aloca por meio do malloc o tamanho necessario para a struct complexo
    z = (Complexo *)malloc(sizeof(Complexo));
    // verifica se struct complexo nao vai ser nula e retorna o endereço da struct z
    if ((*z) != NULL)
    {
        return z;
    }
    // retorna 0 caso a struct for NULL, pra fazer o tratamento
    else
    {
        return 0;
    }

}
    
Complexo *COMPLEXOmultiplica(Complexo *z1, Complexo *z2) {

    //criando a struct Complexa que vai amarzena os valores da multiplicacao dos numeros complexos

    Complexo *multiplica;

    /*temos por definicao matematica que a formula da multiplicacao de numeros imaginarios é (ac-bd)+(ad+bc)
    onde a é a parte real do primeiro numero imaginario e b sua parte imaginaria
    onde c é a parte real do primeiro numero imaginario e d sua parte imaginaria
    */
    multiplica= COMPLEXOcria(((z1->re)*(z2->re))-((z1->im)*(z2->im)),((z1->re)*(z2->im))-((z1->im)*(z2->re)))
    
    return multiplica;
}