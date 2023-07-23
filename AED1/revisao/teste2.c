#include <stdio.h>
#include <string.h>

int main()
{
    int tamn1, tamn2, i, j, ai, bi, ts;
    unsigned char n1[1000], n2[1000];
    unsigned char r[1000] = {0};
    
    printf("Digite um numero\n");
    scanf("%s",n1);
    printf("Digite outro numero\n");
    scanf("%s",n2);
    
    tamn1=strlen(n1);
    tamn2=strlen(n2);
    
    ts = 0;
    for(j = tamn2-1; j >= 0; j--){
        bi = n2[j] - '0'; //j nunca é menor que 0
        for(i = tamn1-1; i >= -1; i--){ //Vai até -1 para somar o último ts
            ai = i >= 0 ? n1[i] - '0' : 0; //valor depende se i é maior ou igual a 0
            r[j+i+1] += bi * ai + ts; // multiplica e soma aos anteriores
            ts = r[j+i+1] / 10;
            r[j+i+1] = r[j+i+1] % 10;
        }
    }
    
    //Transforma números em caracteres
    r[tamn1 + tamn2] = '\0';
    for(i = 0; i < tamn1+tamn2; i++){
        r[i] += '0';
    }
    
    //Remove zero a esquerda
    for(i = 0; i < tamn1+tamn2-1 && r[i] == '0'; i++);
    strcpy(r, &r[i]);
    
    
    printf("\n%s\n", r);
    
    return 0;
}