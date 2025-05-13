#include <stdio.h>
#include <string.h>

#define MAX 100

void computeLPS(char P[], int lps[], int m){
    // Set lps[0] as 0;
    lps[0] = 0;
    int k = 0; 
    int q;

    for(q = 1; q < m; q++){
        // If pattern not matches and k is less than 0
        while(k > 0 && P[q] != P[k]){
            // Backtrack 
            k = lps[k-1];
        }

        // If pattern matches then inc the k poitner
        if(P[q] == P[k]){
            k++;
        }

        // Set the k value in lps table
        lps[q] = k;
    }
}

int main(){
    char str[] = "ababcabcabababdababd";
    char P[] = "ababd";

    int n = strlen(str);
    int m = strlen(P);

    // Compute LPS
    int lps[MAX]; 
    computeLPS(P, lps, m);

    printf("LPS Array: ");
    for(int i = 0; i < m; i++){
        printf("%d ", lps[i]);
    }

    // Now perform string matching algo
    int q = 0; // For pointing pattern 
    int i; // For pointing string 


    for(i = 0; i < n; i++){
        while(q > 0 && str[i] != P[q]){
            q = lps[q - 1];
        }

        if(str[i] == P[q]){
            q++;
        }

        // if q reaches the pattern size 
        if(q == m){
            printf("\nPattern found at index: %d - %d", i - q + 1, i);
            // Continues to search for other occurences
            q = lps[q-1];
        }
    }

    return 0;
}