#include <stdio.h>
#include <string.h>

void computeLPS(char *P, int m, int *lps){
    // 0th index letter always set to 0
    lps[0] = 0;
    int k = 0;

    for(int q = 1; q < m; q++){
        // Compare P with P until k > 0;
        while(k > 0 && P[q] != P[k]){
            k = lps[k-1];
        }

        // If match
        if(P[q] == P[k]){
            // Increment k value
            k++;
        }

        // Store in lps 
        lps[q] = k;
    }
}

int main(){
    char str[] = "ababcabcabababd";
    int n = strlen(str);
    
    char P[] = "ababd";
    int m = strlen(P);

    int lps[m];
    computeLPS(P, m, lps);

    printf("LPS array:\n");
    for (int i = 0; i < m; i++) {
        printf("%d ", lps[i]);
    }

    int q = 0;
    // Now apply KMP algo 
    for (int i = 0; i < n; i++) {
        while (q > 0 && str[i] != P[q]) {
            q = lps[q - 1];
        }

        if (str[i] == P[q]) {
            q++;
        }

        if (q == m) {
            printf("Pattern found at index %d\n", i - m + 1);
            q = lps[q - 1]; // To continue searching for next occurrence
        }
    }

    return 0;
}