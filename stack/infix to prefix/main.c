#include<stdio.h>
#include<stdlib.h>
#include "operations.h"

int main(){
    char exp[] = "a+b*c/d";
    printf("Prefix expression : %s" ,  convert(exp));
    char str[20] = "mam";
    
    // printf("Enter your string : ");
    // scanf("%s" , str);
    // if(palindrome(str)){
    //     printf("\npalindrome!");
    // }else{
    //     printf("\nNot palindrome");
    // }


    // using two pointer approach
    if(palindrome2(str)){
        printf("\npalindrome!");
    }else{
        printf("\nNot palindrome");
    }
    return 0;
}