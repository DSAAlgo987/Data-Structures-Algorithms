#include <stdio.h>

void Merge(int A[] , int l , int mid , int h){
    int i , k , j;
    int B[100]; // auxiliary array 
    i = l , j = mid+1 , k = l;
    
    while(i <= mid && j <= h){
        if(A[i] < A[j])
            B[k++] = A[i++];
        else 
            B[k++] = A[j++];
    }
    
    // get all remaining elements from the array 
    for(; i <=mid ; i++){
        B[k++] = A[i];
    }
    for(; j<=h ; j++){
        B[k++] = A[i];
    }
    
    // copy all elements from B to A 
    for(i = 0; i <= h ; i++){
        A[i] = B[i];
    }
}

void MergeSort(int A[] , int l , int h){
    int mid;
    // atleast two elements should be there 
    if(l < h){
        mid = (l+h)/2; // calc mid
        // left list MergeSort
        MergeSort(A , l ,mid);
        //right list MergeSort
        MergeSort(A , mid+1 , h);
        //perform merging
        Merge(A , l , mid , h);
    }
}

int main()
{
    int A[] = {11 , 3 , 10 , 15 , 5, 4 , 5 , 7 , 1 , 2} , n = 10  ,i;
    
    MergeSort(A , 0 , n-1);
    
    for(i = 0 ; i<n;i++){
        printf("%d " ,A[i]);
    }
    
    return 0;
}
