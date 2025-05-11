#include <stdio.h>
#include <limits.h>

// First the select the min edge 
// After that select the min edge vertex from selected vertex and connected

#define V 8 // No of vertices 
#define I INT_MAX 

// Cost matrix 
int cost[V][V] = {
    {I, I, I, I, I, I, I, I},
    {I, I, 25, I, I, I, 5, I},
    {I, 25, I, 12, I, I, I, 10},
    {I, I, 12, I, 8, I, I, I},
    {I, I, I, 8, I, 16, I, 14},
    {I, I, I, I, 16, I, 20, 18},
    {I, 5, I, I, I, 20, I, I},
    {I, I, 10, I, 14, 18, I, I}
};

// Near array 
int near[V] = {I, I, I, I, I, I, I, I,};

// Spanning Tree matrix 
int t[2][6];

int main(){
    int i, j, k, sum = 0;
    int n = 7;
    int min = I;
    int u, v;

    // Identify Min Edge Vertices
    for(i = 1; i <= n; i++){
        for(j = i; j <= n; j++){
            if(cost[i][j] < min){
                min = cost[i][j];
                u = i; v = j;
            }
        }
    }

    // Marked visited for u and v vertices 
    near[u] = 0;
    near[v] = 0;
    // Add min Edge vertices in t array 
    t[0][0] = u; t[1][0] = v;
    sum += min;

    // Update near array 
    for(int i = 1; i <= n; i++){
        if(near[i] != 0){
            near[i] = (cost[i][u] < cost[i][v]) ? u : v;
        }
    }

    // Repeatation work till n - 1 edges
    for(i = 1; i < n - 1; i++){
        // Identify min edge vertex and not visisted
        min = I;
        for(j = 1; j <= n; j++){
            if(near[j] !=0 && cost[j][near[j]] < min){
                min = cost[j][near[j]];
                k = j;
            }
        }

        // Calculate cost
        sum += min;
        
        // Update t array 
        t[0][i] = near[k]; t[1][i] = k;
        near[k] = 0; // visisted

        // update near array 
        for(j = 1; j <=n; j++){
            if(near[j] != 0 && cost[j][k] < cost[j][near[j]]){
                near[j] = k;
            }
        }
    }

    // Print MST
    for(i = 0; i < n-1; i++){
        printf("(%d, %d) ",t[0][i], t[1][i]);
    }

    printf("\nCost: %d", sum);

    return 0;
}