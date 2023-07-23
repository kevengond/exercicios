#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "complexos.h"



// Definicao da TAD
typedef struct complexo {
    float re; // Componente real
    float im; // Componente imaginária
} Complexo;


Complexo *COMPLEXOcria(float real, float imag)
{

    // criando um struct do tipo complexo
    Complexo *z;
    // atribui null pra evitar a utilização de um lixo de memoria, na struct complexo z
    z = NULL;
    // aloca por meio do malloc o tamanho necessario para a struct complexo
    z = (Complexo *)malloc(sizeof(Complexo));
    // verifica se struct complexo nao vai ser nula e retorna o endereço da struct z
    if (z != NULL)
    {
        z->im = imag;
        z->re = real;
        return z;
    }
    // retorna 0 caso a struct for NULL, pra fazer o tratamento
    else
    {
        return 0;
    }

}

void COMPLEXOlibera(Complexo *z)
{

    // verificando se o struct complexo ja foi liberado, ou se ainda á algum valor
    if (z != NULL)
    {
        free((z));
        // atribuindo NULL na struct complexo e saindo da condicional e finalizando a liberação
        (z) = NULL;
    }
}

void COMPLEXOatribui(Complexo *z, float real, float imag)
 {
  z->re = real;
  z->im = imag;
}
//feito por @RubensAugusto

//imprime o numero complexo no terminal utilizando notação cientifica
//@param *z numero complexo a ser imprimido
void COMPLEXOmostra(Complexo *z) 
{
  signed int eIm = 0; //variavel para indicara a potencia de dez da parte imaginaria
  signed int eRe = 0; //variavel para indicar a potencia de dez da parte real
  float im = z->im; //guarda o valor da parte imaginaria do numero
  float re = z->re; //guarda o valor da parte real do numero

  printf("z = ");
  eRe = NOTACAOcientifica(&re);
  eIm = NOTACAOcientifica(&im);
  printf("%.2fe%d ", re, eRe); //imprime a parte real
  if(z->im > 0)//testa se im é maior ou menor que zero para ver qual sinal deve imprimir
    printf("+ %.2fe%di\n", im, eIm);
  else
    printf("- %.2fe%di\n", im, eIm);
}    
//feito por @RubensAugusto

//função para representar um numero em notação cientifica
//@param *num recebe o endereço do numero a ser transformado e o retorna somente com uma casa decimal a 
//direita
//@return e o expoente de dez 
signed int NOTACAOcientifica(float *num)
{
  modulo(num);

  signed int e = 0;  //expoente de dez do numero 
  if(*num > 9) //compara para ver se a imagem é um numero com mais de uma casa decimal
    while(*num > 9) 
    {
      *num /= 10; //movimenta a virgula para a esquerda
      e++; //adiciona ao expoente
    }
  else
    while(*num < 1)
    {
      *num *= 10; //movimenta a virgula para direita
      e--; //subtrai expoente
    }
  
  return e;
}

//função que retorna o conjugado de z
//@param *z numero complexo a ser conjugado
//@return retorna um endereço para numero complexo conjugado
Complexo *COMPLEXOconjuga(Complexo *z) 
{
  Complexo *conjugado;

  conjugado = COMPLEXOcria(z->re, z->im); //cria o conjugado
  conjugado->im *= -1; // inverte o sinal da parte imaginaria

  return conjugado;
}

Complexo *COMPLEXOadiciona(Complexo *z1, Complexo *z2) {
  Complexo *soma;
  soma = NULL;
  soma = (Complexo *)malloc(sizeof(Complexo));
  soma->re = z1->re + z2->re;
  soma->im = z1->im + z2->im;
  return soma;
}

Complexo *COMPLEXOmultiplica(Complexo *z1, Complexo *z2) {

    //criando a struct Complexa que vai amarzena os valores da multiplicacao dos numeros complexos

    Complexo *multiplica;

    /*temos por definicao matematica que a formula da multiplicacao de numeros imaginarios é (ac-bd)+(ad+bc)
    onde a é a parte real do primeiro numero imaginario e b sua parte imaginaria
    onde c é a parte real do primeiro numero imaginario e d sua parte imaginaria
    */
    multiplica= COMPLEXOcria(((z1->re)*(z2->re))-((z1->im)*(z2->im)),((z1->re)*(z2->im))-((z1->im)*(z2->re)));
    
    return multiplica;
}

Complexo *COMPLEXOpotencia1(Complexo *base, int expoente) {

}

Complexo *COMPLEXOpotencia2(Complexo *base, Complexo *expoente) {

}

float COMPLEXOmagnitude(Complexo *z)
{
  float magnitude;
  magnitude = sqrt((z->re*z->re) + (z->im*z->im));
  return magnitude;
}

float COMPLEXOangulo(Complexo *z) {

}
//retorna o modulo do valor de num
//@param *num o valor a ser calculado o modulo
void modulo(float *num)
{
  if(*num < 0)
    *num *= -1;
}