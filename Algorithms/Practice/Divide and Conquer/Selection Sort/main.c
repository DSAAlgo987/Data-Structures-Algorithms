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

void SelectionSort(int A[], int n){
    int i, j, k;

    for(i = 0; i < n-1; i++){
        for(j = k = i; j < n; j++){
            // Identify min element
            if(A[j] < A[k]){
                k = j; // K will point to that position 
            }
        }

        // After this swap min element with selected position 
        int temp = A[k];
        A[k] = A[i];
        A[i] = temp;
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
    SelectionSort(A, n);
    // printArray(A, n);
    t2 = clock();

    total_t = (double) (t2 - t1) / CLOCKS_PER_SEC;
    printf("\nTime Take to sort Random array: %.2f", total_t);

    t3 = clock();
    SelectionSort(A, n);
    // printArray(A, n);
    t4 = clock();

    total_t = (double) (t4 - t3) / CLOCKS_PER_SEC;
    printf("\nTime Take to sort Sorted array: %.2f", total_t);

    reverse(A, n);
    t5 = clock();
    SelectionSort(A, n);
    // printArray(A, n);
    t6 = clock();

    total_t = (double) (t6 - t5) / CLOCKS_PER_SEC;
    printf("\nTime Take to sort Reverse array: %.2f", total_t);

    return 0;
}