#include <stdio.h>

int min, max; // for left tree

void MinMax(int A[], int low , int high){
    int min1, max1; // for right tree

    // Case 1: For 1 element 
    if(low == high){
        min = max =A[low];
    }
    // Case 2: For 2 elements
    else if(low == high-1){
        if(A[low] < A[high]){
            min = A[low];
            max = A[high];
        }else{
            min = A[high];
            max = A[low];
        }
    }else{
        // Divide 
        int mid = (low + high)/2;

        MinMax(A, low, mid); // for left tree
        min1 = min;
        max1 = max;

        MinMax(A, mid+1, high);// for right tree 

        // Compare left sub tree with right sub tree 
        if(max1 > max){
            max = max1;
        }
        if(min1 < min){
            min = min1;
        }

    }
}


int main(){
    int n = 9;
    int A[n];

    for(int i = 0 ;i < n ; i++){
        printf("Enter the Array elements: ");
        scanf("%d", &A[i]);
    }

    MinMax(A, 0, n-1);

    printf("\nMax value: %d \nMin value: %d",max,min);
    return 0;
}