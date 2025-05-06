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
    int i, j, k;

    // Initialize parent matrix
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            if(i == j || A[i][j] == I)
                P[i][j] = -1;
            else
                P[i][j] = i; // Path from i to j goes through i initially
        }
    }

    // Floyd-Warshall Algorithm
    for(k = 0; k < n; k++){
        for(i = 0; i < n; i++){
            for(j = 0; j < n; j++){
                if(A[i][k] != I && A[k][j] != I && A[i][k] + A[k][j] < A[i][j]){
                    A[i][j] = A[i][k] + A[k][j];
                    P[i][j] = k;
                }
            }
        }
    }

    // Print Distance Matrix
    printf("Final distance matrix:\n");
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            if(A[i][j] == I)
                printf(" INF ");
            else
                printf(" %4d", A[i][j]);
        }
        printf("\n");
    }

    // Print Parent Matrix
    printf("\nFinal parent table:\n");
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            if(P[i][j] == -1)
                printf("  -  ");
            else
                printf(" %3d ", P[i][j] + 1); // optional: +1 for 1-based display
        }
        printf("\n");
    }

    return 0;
}
