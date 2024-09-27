// sparse matrix 
#include <stdio.h>
#include "operations.h"


int main()
{
    int m , n;
    printf("Enter the dimension for sparse matrix : ");
    scanf("%d %d" , &m , &n);
    
    struct Node *A[m];
    
    // Create sparse matrix 
    createSparseMatrix(A , m , n);
    
    // display sparse matrix 
    displaySparseMatrix(A , m , n);
    return 0;
}
