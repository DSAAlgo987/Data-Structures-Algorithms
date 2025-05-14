#include <stdio.h>

#define d 3


int main()
{
    int n = 2;
    int A[d][d], B[d][d], C[d][d];
    int P, Q, R, S, T, U, V;
    int i, j;
    
    printf("Enter A matrix: ");
    for(i = 1; i <= n; i++){
        for(j = 1; j <= n; j++)
            scanf("%d", &A[i][j]);
    }
    
    printf("Enter B matrix: ");
    for(i = 1; i <= n; i++){
        for(j = 1; j <= n; j++)
            scanf("%d", &B[i][j]);
    }
    
    printf("\nA Matrix: \n");
    for(i = 1; i <= n; i++)
        for(j = 1; j <= n; j++)
            printf(" %d ", A[i][j]);
        printf("\n");
    
    printf("\nB Matrix: \n");
    for(i = 1; i <= n; i++)
        for(j = 1; j <= n; j++)
            printf(" %d ", A[i][j]);
        printf("\n");
        
    // SMM Working 
    P = (A[1][1] + A[2][2]) * (B[1][1] + B[2][2]);
    Q = (A[2][1] + A[2][2]) * B[1][1];
    R = A[1][1] * (B[1][2] - B[2][2]); 
    S = A[2][2] * (B[2][1] - B[1][1]);
    T = (A[1][1] + A[1][2]) * B[2][2];
    U = (A[2][1] - A[1][1]) * (B[1][1] + B[1][2]); 
    V = (A[1][2] - A[2][2]) * (B[2][1] + B[2][2]); 
    
    // Calculate Result matrix 
    C[1][1] = P + S - T + V;
    C[1][2] = R + T;
    C[2][1] = Q + S;
    C[2][2] = P - Q + R + U;
    
    // Result matrix 
    printf("\nC Matrix: \n");
    for(i = 1; i <= n; i++)
        for(j = 1; j <= n; j++)
            printf(" %d ", C[i][j]);
        printf("\n");
    
    return 0;
}
