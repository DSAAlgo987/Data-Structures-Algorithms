#include <stdio.h>
#include <time.h>

int min ,max; // Left subtree

void minMax(int A[], int l, int h){
    int min1, max1; // Right subtree
    // Base conditions 
    if(l == h){
        min = max = A[l];
    }

    // If two elements 
    else if(l == h-1){
        // Identify min and max between those two elements
        if(A[l] < A[h]){
            min = A[l];
            max = A[h];
        }else{
            min = A[h];
            max = A[l];
        }
    }
    else {
        // choice diagram

        // Divide 
        int mid = (l + h) / 2;
        minMax(A, l, mid); // For left subtree

        min1 = min;
        max1 = max;

        minMax(A, mid+1, h);

        if(min1 < min){
            min = min1;
        }

        if(max1 > max){
            max = max1;
        }
    }

}

int main(){

    int A[] = {70, 10, 50, 20, 80, 15, 5, 40, 60};
    int n = sizeof(A)/ sizeof(A[0]);
    clock_t start , end;
    double timeTaken;

    start = clock();
    minMax(A, 0, n-1);
    end = clock();


    printf("Min: %d \nMax: %d", min, max);

    timeTaken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\nTime Taken by CPU: %f", timeTaken);

    return 0;
}