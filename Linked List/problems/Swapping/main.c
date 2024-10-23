#include <stdio.h>

int main()
{
    int a = 10;
    int b = 20;
    
    printf("Before swapping  : a= %d , b = %d " , a , b);
    
    
    a = a ^ b; // ^ : this sign is XOR 
    b = b ^ a;
    a = a ^ b;
    printf("After swapping : a = %d , b = %d" , a , b);

    return 0;
}