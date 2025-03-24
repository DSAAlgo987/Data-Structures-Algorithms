#include <stdio.h>

#define I 32767

// Algorithm:
/**
 * 1. First select vertices having minimum edge cost from cost matrix
 * 2. Select the adjacent Vertices having minimum edge cost
 */

// Initialization 
int cost[8][8] = {
    {I, I, I, I, I, I, I, I},
    {I, I, 25, I, I, I, 5, I},
    {I, 25, I, 12, I, I, I, 10},
    {I, I, 12, I, 8, I, I, I},
    {I, I, I, 8, I, 16, I, 14},
    {I, I, I, I, 16, I, 20, 18},
    {I, 5, I, I, I, 20, I, I},
    {I, I, 10, I, 14, 18, I, I}
};

// Initialize as Infinity
int near[8] = {I, I, I, I, I, I, I, I};

// n-> nodes , n-1 -> edges(6)
int t[2][6];

int main(){
    int i, j, u, v, k,min = I, n=7, sum=0;

    // Initial work
    // Find minimum edge from Cost matrix(upper triangular)
    for(i = 1; i<=n;i++){
        for(j = i; j<=n ;j++){
            if(cost[i][j] < min){
                min = cost[i][j];
                u = i; v = j;
            }
        }
    }

    near[u] = near[v] = 0;
    t[0][0] = u; t[1][0] = v;
    sum += min;

    // Identify near vertex having minium edge and connected by the selected edge 
      for (i = 1; i <= n; i++) {
        if (near[i] != 0) { 
            near[i] = (cost[i][u] < cost[i][v]) ? u : v;
        }
    }

    // Repeatetion work 
    for(i=1; i<n-1 ;i++){
        min = I;
        // Identify min edge from near array 
        for(j=1; j<=n; j++){
            if(near[j]!=0 && cost[j][near[j]]<min){
                min = cost[j][near[j]];
                k = j;
            }
        }

        // update Spanning tree and near array too
        t[0][i] = k; t[1][i] = near[k];
        near[k] = 0;
        sum += min;

        // Identify near vertex having minium edge and connected by the selected edge
        for(j=1; j<=n; j++){
            if(near[j]!=0 && cost[j][k] < cost[j][near[j]]){
                near[j] = k;
            }
        }
    }

    for(i=0; i<n-1;i++){
        printf("(%d, %d),",t[0][i],t[1][i]);
    }

    printf("\nTotal cost: %d",sum);

    return 0;
}