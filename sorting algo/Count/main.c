#include <stdio.h>
#include <stdlib.h>

int findMax(int A[] , int n){
    int max =0, i;
    for(i = 0 ; i< n;i++){
        if(A[i] > max){
            max = A[i];   
        }
    }
    return max;
}

void CountSort(int A[] , int n){
    int max ,i , j;
    int *C;
    
    // find max 
    max = findMax(A , n);
    // create count as the max element 
    C = (int *)malloc(sizeof(int) *max+1);
    
    // initialize count array as empty (0)
    for(i = 0 ; i < max+1 ; i++)
        C[i] = 0;
    
    // store frequency/count of elements in A 
    for(i = 0 ; i < n ; i++){
        C[A[i]]++;
    }
    
    // retrieve all the elements from count by decrementing count
    i = 0 ,j = 0;
    while(i < max +1){
        if(C[i] > 0){
            A[j++] = i;
            C[i]--;
        }else {
            i++;
        }
    }
}

int main()
{
    int A[] = {11 , 3 , 10 , 15 , 5, 4 , 5 , 7 , 1 , 2} , n = 10  ,i;
    
    CountSort(A , n);
    
    for(i = 0 ; i<n;i++){
        printf("%d " ,A[i]);
    }
    
    return 0;
}
