#include<stdio.h>
#include<stdlib.h>
#include "operations.h"

int main(){
    char exp[] = "a+b*c/d";
    printf("Prefix expression : %s" ,  convert(exp));

    return 0;
}