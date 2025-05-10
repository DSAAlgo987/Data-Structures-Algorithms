#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define SIZE 30000

void Merge(int A[], int l, int mid, int h){
    int B[SIZE];
    int i = l, j= mid + 1;
    int k = l;
    while(i <= mid && j <= h){
        if(A[i] < A[j]){
            B[k++] = A[i++];
        }else{
            B[k++] = A[j++];
        }
    }

    // Store remaining elements from A array 
    for(; i <= mid; i++){
        B[k++] = A[i];
    }

    for(; j<= h; j++){
        B[k++] = A[j];
    }

    // Store back from B to A
    for(i = 0; i <= h; i++){
        A[i] = B[i];
    }
}

void MergeSort(int A[], int l, int h){
    // Base condition min two elements should be there 
    if(l < h){
        int mid = (l + h) / 2;
        // Divide
        // left subtree 
        MergeSort(A, l, mid);

        // right subree
        MergeSort(A, mid + 1, h);

        // Conquer
        Merge(A, l, mid, h);
    }
}

void reverse(int A[], int n){
    int temp[n];

    for(int i = 0; i < n;i++){
        temp[i] = A[n - i - 1];
    }

    for(int i = 0; i < n; i++){
        A[i] = temp[i];
    }
}

int main(){
    int A[SIZE];
    int n = SIZE;
    clock_t t1, t2, t3, t4, t5, t6;
    double total_t;

    for(int i = 0; i < n; i++){
        A[i] = rand() % 100;
    }

    // printf("Sorted Array: \n");
    // for(int i = 0; i < n; i++){
    //     printf("%d ", A[i]);
    // }


    t1 = clock();
    MergeSort(A, 0, n-1);
    t2 = clock();


    total_t = (double) (t2 - t1)/ CLOCKS_PER_SEC;
    printf("\nTime Taken to sort for random array: %f", total_t);

    t3 = clock();
    MergeSort(A, 0, n-1);
    t4 = clock();

    total_t = (double) (t4 - t3)/ CLOCKS_PER_SEC;
    printf("\nTime Taken to sort for Sorted Array: %f", total_t);

    t5 = clock();
    MergeSort(A, 0, n-1);
    t6 = clock();

    total_t = (double) (t6 - t5)/ CLOCKS_PER_SEC;
    printf("\nTime Taken to sort for Reverse Array: %f", total_t);

    return 0;
}