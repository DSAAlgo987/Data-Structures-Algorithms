#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define d 252 // no of input alphabet

void search(char text[], char pat[], int n, int m, int q){
    // For rolling hash function 
    int h = 0;
    int i, j;
    // Calculate rolling has function till m-1 
    for(i = 0; i < m-1; i++){
        h = (h * d) % q;
    }

    int t = 0; // Hash val for text  
    int p = 0; // Hash val for pattern

    // Compute hash code for first window 
    for(i = 0; i < m; i++){
        t = (d * t) % q;
        p = (d * p) % q;
    }

    // Rabin karp loop
    for(i = 0; i <= n-m; i++){
        // If hash code same 
        if(t == p){
            for(j = 0; j < m; j++){
                // Then check chars are matching?
                if(text[i+j] != pat[j]){
                    break;
                }
            }

            // If all chars are matching
            if(j == m){
                printf("Index is found at %d.\n", i);
            }
        }else{
            // Acheive window size
            if(i < n-m){
                // Roll hash function 
                t = (d * (t - text[i] * h) + text[i+m]) % q;

                // if t becomes negative?
                if(t < 0){
                    t += q;
                }
            }
        }
    }
}

int main(){
    char text[] = "aaaab";
    char pat[] = "aab";

    int n = strlen(text);
    int m = strlen(pat);
    // prime no 
    int q = 101;

    search(text, pat, n, m, q);
}