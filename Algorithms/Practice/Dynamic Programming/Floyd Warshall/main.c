#include <stdio.h>
#include <limits.h>

#define I INT_MAX

int main(){
    int n = 5;
    int A[5][5] = {
        {0, 3, 8, I, -4},
        {I, 0, I, 1, 7},
        {I, 4, 0, I, I},
        {2, I, -5, 0, I},
        {I, I, I, 6, 0},
    };

    int P[5][5];

    // Initialize parent matrix 
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j || A[i][j] == I){
                P[i][j] = I;
            }else{
                P[i][j] = i; 
            }
        }
    }

    // Floyd warshall working 
    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(A[i][k] != I && A[k][j] != I && A[i][k] + A[k][j] < A[i][j]){
                    // Update matrix 
                    A[i][j] = A[i][k] + A[k][j];
                    P[i][j] = k;
                }
            }
        }
    }

    // Print matrix 
    printf("\nResult matrix: \n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf(" %4d ", A[i][j]);
        }

        printf("\n");
    }

    printf("\nParent matrix: \n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(P[i][j] == I){
                printf("  _  ");
            }else{
                printf(" %3d ", P[i][j] + 1);
            }
        }
        printf("\n");
    }
}