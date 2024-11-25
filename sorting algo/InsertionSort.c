#include <stdio.h>


void Insertion(int A[] , int n){
    int x,i,j;
    for(i = 1 ; i<n;i++){
        j = i-1;
        x = A[i];
        while(j>-1 && A[j] > x){
            // first shifting 
            A[j+1] = A[j];
            j--;
        }
        A[j+1] =x;
    }
}


int main()
{
    int A[] = {11 , 3 , 10 , 15 , 5, 4 , 5 , 7 , 1 , 2} , n = 10  ,i;
    
    Insertion(A , n);
    
    for(i = 0 ; i<n;i++){
        printf("%d " ,A[i]);
    }
    
    return 0;
}
