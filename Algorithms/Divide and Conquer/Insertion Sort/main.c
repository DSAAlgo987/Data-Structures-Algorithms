#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define SIZE 30000

void printArray(int *A, int n){
    int i;
    for(i = 0; i < n; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
}

void InsertionSort(int A[], int n){
    int i, j, x;

    for(i = 1; i < n; i++){
        j = i-1;
        x = A[i];

        while(j > -1 && A[j] > x){
            // Swap 
            A[j+1] = A[j];
            j--;
        }

        A[j+1] = x;
    }
}

void reverse(int *A, int n){
    int temp[SIZE];

    for(int i = 0; i < n; i++){
        temp[i] = A[n - i -1];
    }

    for(int i = 0; i < n; i++){
        A[i] = temp[i];
    }
}

int main(){
    int A[SIZE];
    int n = sizeof(A)/ sizeof(A[0]);
    clock_t t1, t2, t3, t4, t5, t6;
    double total_t;


    for(int i = 0; i < SIZE; i++){
        A[i] = rand() % 100;
    }

    t1 = clock();
    InsertionSort(A, n);
    // printArray(A, n);
    t2 = clock();

    total_t = (double) (t2 - t1) / CLOCKS_PER_SEC;
    printf("\nTime Take to sort Random array: %.2f", total_t);

    t3 = clock();
    InsertionSort(A, n);
    // printArray(A, n);
    t4 = clock();

    total_t = (double) (t4 - t3) / CLOCKS_PER_SEC;
    printf("\nTime Take to sort Sorted array: %.2f", total_t);

    reverse(A, n);
    t5 = clock();
    InsertionSort(A, n);
    // printArray(A, n);
    t6 = clock();

    total_t = (double) (t6 - t5) / CLOCKS_PER_SEC;
    printf("\nTime Take to sort Reverse array: %.2f", total_t);

    return 0;
}