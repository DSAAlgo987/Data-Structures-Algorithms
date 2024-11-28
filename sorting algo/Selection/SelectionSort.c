#include <stdio.h>

void swap(int *i , int *k){
    int temp = *i;
    *i = *k;
    *k = temp;
}

void Selection(int A[] , int n){
    int i , j , k;
    
    for(i = 0; i < n-1;i++){
        for(j = k =i; j< n; j++){
            if(A[j] < A[k]) // find min element
                k = j;
        }
        // after finding smallest element swap ith and kth element
        swap(&A[i] , &A[k]);
    }
}


int main()
{
    int A[] = {11 , 3 , 10 , 15 , 5, 4 , 5 , 7 , 1 , 2} , n = 10  ,i;
    
    Selection(A , n);
    
    for(i = 0 ; i<n;i++){
        printf("%d " ,A[i]);
    }
    
    return 0;
}
