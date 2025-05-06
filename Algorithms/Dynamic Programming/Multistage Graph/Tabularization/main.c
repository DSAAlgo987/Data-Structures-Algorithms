#include <stdio.h>
#include <limits.h>

// Required DS
int stages = 4, min;
int n = 8;
int cost[9], P[9], d[9];
int c[9][9] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0},  
    {0, 0, 2, 1, 3, 0, 0, 0, 0},  
    {0, 0, 0, 0, 0, 2, 3, 0, 0},  
    {0, 0, 0, 0, 0, 6, 7, 0, 0},  
    {0, 0, 0, 0, 0, 6, 8, 9, 0},  
    {0, 0, 0, 0, 0, 0, 0, 0, 6},  
    {0, 0, 0, 0, 0, 0, 0, 0, 4},  
    {0, 0, 0, 0, 0, 0, 0, 0, 5},  
    {0, 0, 0, 0, 0, 0, 0, 0, 0}   
};

int main(){

    cost[n] = 0; // cost of end vertex 

    // calculate cost and distance array
    for(int i = n-1; i>=1; i--){
        min = INT_MAX;
        for(int k = i+1; k <= n; k++){
            // identify min
            if(c[i][k] != 0 && c[i][k] + cost[k] < min){
                min = c[i][k] + cost[k];
                d[i] = k;
            }
        }

        cost[i] = min;
    }

    // Identify path 
    P[1] = 1; P[stages] = n;

    for(int i = 2; i < stages; i++){
        P[i] = d[P[i-1]];
    }

    // Display path 
    printf("Distance is : ");

    for(int i = 1; i <= stages; i++){
        printf("%d -> ", P[i]);
    }

    return 0;
}