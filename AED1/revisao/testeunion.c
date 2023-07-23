#include <stdio.h>


int main(){


    union
    
     Dado {
        int intn;
        double doublen;
    }dado;


    

    dado.intn=10;
    dado.doublen=10.5;


    printf(dado.intn+dado.doublen);














    return 0;
}