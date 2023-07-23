# include <stdio.h>


int main(){


    int n = 0, numero, contaprimos=0, ndivid=0;


    scanf("%d", &numero);


    while(1){
        n++;

        if(numero%n==0){
            ndivid++;
        
        }
        if(n==numero){
            break;
        }
    }

    if(ndivid==2){
        printf("o numero e primo\n");
    }
    else{
        printf("o numero nao e\n");
    }






    return 0;
}