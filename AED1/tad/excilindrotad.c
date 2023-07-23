

Cilindro* cilindro_cria(float raio, float altura,bool visibilidade){

    Cilindro* p = (Cilindro*)malloc(sizeof(Cilindro));
    if(p !=null){
        p->raio = raio;
        p->altura = altura;
        p->visibilidade = visibilidade;
    }
    return (p);
}
float volume_cilindro(Cilindro* c1){
    float volume;
    
    volume= (c1->altura)*(c1->raio)*(c1->raio)*PI;


    return volume;


}



int main(){
    float raio, altura;
    Cilindro *c1;

    printf("Digite a altura e a base do cilindro\n");
    scanf("%lf %lf", &raio, &altura);
    c1 = cilindro_cria(raio, altura);
    printf("altura do cilindro: %f\n", cilindro_altura(c1));
    printf("raio do cilindro: %f\n", cilindro_raio(c1));
    printf("area da base do cilindro: %f\n", area_base(c1));
    printf("area da face do cilindro: %f\n", area_face(c1));
    printf("volume do cilindro: %f\n", volume_cilindro(c1));




    return 0;
}