#include <stdio.h>
#include <limits.h>

#define I INT_MAX 

int cost[8][8] = {
    {I, I, I, I, I, I, I, I},
    {I, I, 6, 5, 5, I, I, I},
    {I, I, I, I, I, -1, I, I},
    {I, I, -2, I, I, 1, I, I},
    {I, I, I, -2, I, I, -1, I},
    {I, I, I, I, I, I, I, 3},
    {I, I, I, I, I, I, I, 3},
    {I, I, I, I, I, I, I, I},
};

// int cost[5][5] = {
//     {I, I, I, I, I},       // 0 (not used)
//     {I, 0, 4, I, 5},       // 1
//     {I, I, 0, I, 5},       // 2
//     {I, I, -10, 0, I},     // 3
//     {I, I, I, 3, 0}        // 4
// };



int d[8];
int p[8];

int BellmanFord(int src, int n){
    int i, u, v;

    // Initialize distand and parent matrix 
    for(i = 1; i <= n; i++){
        d[i] = I;
        p[i] = -1;
    }

    d[src]= 0;

    // Relaxation till n-1 times
    for(i = 1; i <= n-1; i++){
        for(u = 1; u <= n; u++){
            for(v = 1; v <= n; v++){
                if(cost[u][v] != I && d[u] + cost[u][v] < d[v]){
                    // Update distance & parent array
                    d[v] = d[u] + cost[u][v];
                    p[v] = u;
                }
            }
        }
    }

    // Again Relaxation to check negative edge cycle 
    for(u = 1; u <= n; u++){
        for(v = 1; v <= n; v++){
            if(cost[u][v] != I && d[u]+ cost[u][v] < d[v]){
                // There is a cycle 
                return 1;
            }
        }
    }
    // There is no any cycle
    return 0;
    
}

int main(){

    int n = 7;

    if(BellmanFord(1 , n)){
        printf("\nThere is a negative edge cycle.");
    }else{
        printf("\nShortest Path Table\n");
        for(int i =1; i <= n; i++){
            printf("%d\t%d\t%d\t\n", i, d[i], p[i]);
        }
    }

    return 0;
}