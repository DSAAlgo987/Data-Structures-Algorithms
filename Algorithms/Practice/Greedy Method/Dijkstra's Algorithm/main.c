#include <stdio.h>
#include <limits.h>
#include <string.h>

#define I INT_MAX 

// Adjancency matrix 
int cost[7][7] = {
    {I, I, I, I, I, I, I}, // 0
    {I, I, 2, 4, I, I, I}, // 1
    {I, I, I, 1, 7, I, I}, // 2
    {I, I, I, I, I, 3, I}, // 3
    {I, I, I, I, I, I, 1}, // 4
    {I, I, I, I, 2, I, 5}, // 5
    {I, I, I, I, I, I, I}  // 6
};

int d[7];
int p[7];
int visited[7];

void Dijkstra(int src, int n){
    int min, u, v, i, j;

    // Initialize distance and visited matrix 
    for(i = 1; i <= n; i++) {
        d[i] = I;
        visited[i] = 0;
    }

    // Initially set src as 0
    d[src] = 0;

    for(i = 1; i <= n; i++){
        // Idenitfy min distance vertex and not visisted
        min = I;
        u = -1;

        for(j = 1; j <= n ;j++){
            if(!visited[j] && d[j] < min){
                u = j;
                min = d[j];
            }
        }

        if(u == -1)
            break; // All vertices are visisted  and uncreashable 
        // Update visited 
        visited[u] = 1;
        // Relaxation 
        for(v = 1; v <= n; v++){
            // Relax those vertices which are having connection and not visisted
            if(!visited[v] && cost[u][v] != I && d[u] + cost[u][v] < d[v]){
                // update parent and distance array
                d[v] = d[u] + cost[u][v];
                p[v] = u;
            }
        }
        
    }

}

int main(){
    int n = 6, i;

    Dijkstra(1 , n);

    printf("\nShortest Paths from Vertex 1 using Dijkstra's Algorithm:\n");
    printf("Vertices Distance Parent\n");

    for(i = 1; i <= n;i++){
        if(i == 1){
            printf("%d\t%d\t_\n", i, d[i]);
            continue;
        }
        printf("%d\t%d\t%d\n", i, d[i], p[i]);
    }
}
