#include <stdio.h>
#include "operations.h"

int main(){
    char prefix[] = "+*54/67";

    int result= eval(prefix);

    if(result){
        printf("Evaluation of prefix %s : %d" , prefix , result);
    }
    return 0;
}