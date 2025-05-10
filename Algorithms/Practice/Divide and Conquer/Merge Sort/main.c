#include <stdio.h>
#include <time.h>

void Merge(int A[], int l, int mid, int h){
    int B[100];
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

int main(){
    int A[] = {70, 3, 10, 15, 5, 4, 2, 1};
    int n = sizeof(A)/ sizeof(A[0]);
    clock_t start_t, end_t;
    double total_t;

    start_t = clock();
    MergeSort(A, 0, n-1);
    end_t = clock();

    printf("Sorted Array: \n");
    for(int i = 0; i < n; i++){
        printf("%d ", A[i]);
    }

    total_t = (double) (end_t - start_t)/ CLOCKS_PER_SEC;

    printf("\nTime Taken by CPU: %f", total_t);

    return 0;
}