#include <stdio.h>



int main(){
    int A[2][2], B[2][2], C[2][2];
    int i, j, P, Q, R, S, T, U, V;

    printf("Enter A matrix: \n");
    for(i = 0; i< 2; i++){
        for(j = 0; j <2; j++)
            scanf("%d", &A[i][j]);
    }  

    printf("Enter B matrix: \n");
    for(i = 0; i< 2; i++){
        for(j = 0; j <2; j++)
            scanf("%d", &B[i][j]);
    } 

    printf("\nA matrix: \n");
    for(i = 0; i< 2; i++){
        for(j = 0; j <2; j++)
            printf("%d\t", A[i][j]);
        printf("\n");
    }   
    printf("\nB matrix: \n");
    for(i = 0; i< 2; i++){
        for(j = 0; j <2; j++)
            printf("%d\t", B[i][j]);
        printf("\n");
    }   

    // SMM 
    P = (A[0][0] + A[1][1]) * (B[0][0] + B[1][1]);
    Q = (A[1][0] + A[1][1]) * B[0][0];
    R = A[0][0] * (B[0][1] - B[1][1]);
    S = A[1][1] * (B[1][0] - B[0][0]);
    T = (A[0][0] + A[0][1]) * B[1][1];
    U = (A[1][0] - A[0][0]) * (B[0][0] + B[0][1]);
    V = (A[0][1] - A[1][1]) * (B[1][0] + B[1][1]);

    // Calculate result matrix 
    C[0][0] = P + S - T + V;
    C[0][1] = R + T;
    C[1][0] = Q + S;
    C[1][1] = P - Q + R + U;

    printf("\nC matrix: \n");
    for(i = 0; i< 2; i++){
        for(j = 0; j <2; j++)
            printf("%d\t", C[i][j]);
        printf("\n");
    } 

    return 0;
}