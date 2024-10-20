#include <stdio.h>
#include <stdlib.h>

// TC : O(log n)
void insert(int A[] , int n){
    // A[] : heap
    // n : new index in which the new element is present

    int temp  , i = n;
    temp = A[n];

    while(i > 1 && temp > A[i/2]){
        A[i] = A[i/2]; 
        i = i/2;
    }
    A[i] = temp;
}

void swap(int *a , int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

// TC : O(nlogn)
int delete(int A[] , int n){
    int x, i , j , temp;
    x = A[1];
    A[1] = A[n];

    i = 1; j= 2*i;
    while(j < n-1){
        // comparing it's children
        // right child > left child
        if(A[j+1] > A[j]){
            j +=1;
        }
        
        // compare parent element with it's child
        if(A[i] < A[j]){
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
            i = j;
            j = 2*j;
        }else {
            break;
        }
    }

    A[n] = x;
    return x;
}

// TC : O(n) faster than normal creation 
void heapify(int A[] , int n){
    for(int i = n/2 ; i>0 ; i--){
        int j = 2 *i;
        int dummy = i;

        while(j < n){// this condition ensures that node must have both lchild & rchild to go inside loop.
            // comparing children 
            if(A[j+1] > A[j]){
                j = j+1;
            }
            // comapring parent with children
            if(A[i] < A[j]){
                swap(&A[i] , &A[j]);
                i = j;
                j = 2 *j;
            }
        }
        // i is at the leaf right now, so reassigned to its original value
        i = dummy;
    }
}

int main(){
    int H[] = {0 , 10 , 20 , 30 , 25, 5 , 40 , 35};
    // 40 , 25 , 35 , 10 , 5 , 20, 30

    TC : O(nlogn)
    for(int i = 2 ; i<=7 ; i++){
        insert(H ,i);
    }

    heapify(H , 7);

    printf("\nHeap : ");
    for(int i = 1 ; i<=7 ; i++){
        printf("%d " , H[i]);
    }

    for(int i=7 ; i >1 ; i--){
        delete(H ,i);
    }

    printf("\nAfter Deletion Heap (Heap Sort) : ");
    for(int i = 1 ; i<=7 ; i++){
        printf("%d " , H[i]);
    }
    return 0;
}