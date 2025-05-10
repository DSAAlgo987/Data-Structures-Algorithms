#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 30000

void printArray(int A[], int n){
    for(int i = 0; i < n; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int Partition(int A[], int low, int high){
    int pivot = A[low];
    int i = low + 1;
    int j = high;

    do{
        // iterate i if it is less than equal to pivot
        while(A[i] <= pivot){
            i++;
        }

        // iterate j if it is greater than to pivot
        while(A[j] > pivot){
            j--;
        }

        // if they are less than or greater than pivot than swap
        if(i < j){
            swap(&A[i], &A[j]);
        }
    }while(i < j);

    // After i and j cross to each other then swap with j with pivot element 
    swap(&A[low], &A[j]);

    return j; // Partition element 
}

void QuickSort(int A[], int low, int high){
    // Base Condition min two elements should be there 
    if(low < high){
        int partition = Partition(A, low, high);

        // Divide 
        QuickSort(A, low, partition - 1);
        QuickSort(A, partition + 1, high);
    }
}

void reverse(int A[], int n){
    int temp[SIZE];

    for(int i = 0; i < n; i++){
        temp[i] = A[n - i -1];
    }

    for(int i = 0; i < n;i++){
        A[i] = temp[i];
    }
}

int main(){
    int A[SIZE];
    int n = sizeof(A) / sizeof(A[0]);
    clock_t t1, t2, t3, t4, t5, t6;
    double total_t;

    for(int i =0; i < n;i++){
        A[i] = rand() % 100;
    }

    t1 = clock();
    QuickSort(A, 0, n-1);
    t2 = clock();

    // printArray(A, n);
    total_t = (double)(t2 - t1) / CLOCKS_PER_SEC;
    printf("\nTime Taken to sort randome array: %.2f", total_t);

    t3 = clock();
    QuickSort(A, 0, n-1);
    t4 = clock();

    total_t = (double)(t4 - t3) / CLOCKS_PER_SEC;
    printf("\nTime Taken to sort sorted array: %.2f", total_t);

    reverse(A, n);

    t5 = clock();
    QuickSort(A, 0, n-1);
    t6 = clock();

    total_t = (double)(t6 - t5) / CLOCKS_PER_SEC;
    printf("\nTime Taken to sort reverse array: %.2f", total_t);




    return 0;
}