#include <stdio.h>

void PrintLCS(char A[] , char B[], int m, int n){
    int LCS[m+1][n+1];
    int i,j;
 
    // Initialize 0th row and column as Zero
    for (i = 0; i <= m; i++) {
        for (j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                LCS[i][j] = 0;
            }
        }
    }
    
    for(i = 1 ; i <= m; i++){
        for(j = 1; j <= n; j++){
            if(A[i-1] == B[j-1]){
                // Plus one with Previous Diagonal Element
                LCS[i][j] = 1 + LCS[i-1][j-1];
            }else {
                // Take the max of previous row and column 
                LCS[i][j] = (LCS[i-1][j] > LCS[i][j-1]) ? LCS[i-1][j] : LCS[i][j-1];
            }
        }
    }
    
    // Print the LCS array
    for (i = 0; i <=m; i++) {
        for (j = 0; j <=n; j++) {
            printf("%d ", LCS[i][j]);
        }
        printf("\n");
    }
    
    // Print LCS length 
    printf("\nLength of LCS: %d\n", LCS[m][n]);
    
    // Backtrack to find the LCS string
    int lcsLength = LCS[m][n];
    char lcsStr[lcsLength + 1]; // +1 for null terminator
    lcsStr[lcsLength] = '\0';
    
    i = m, j = n;
    while(i > 0 && j > 0){
        if(A[i-1] == B[j-1]){ // If characters match, it's part of LCS
            lcsStr[--lcsLength] = A[i-1];
            i--;
            j--;
        }else if(LCS[i-1][j] > LCS[i][j-1]){
            i--; // Move up 
        }else{
            j--; // Move left
        }
    }
    
    printf("LCS: %s" , lcsStr);
}
int main()
{
    char A[] = "bd";
    char B[] = "abcd";
    
    int m = sizeof(A)/ sizeof(A[0]) - 1; // Subtract 1 to remove null terminator
    int n = sizeof(B)/ sizeof(B[0]) - 1; // Subtract 1 to remove null terminator
    printf("%d %d\n\n" , m, n);
    
    PrintLCS(A, B, m, n);
    return 0;
}