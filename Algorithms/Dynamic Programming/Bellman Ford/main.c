#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define I INT_MAX // Infinity
#define N 5       // Number of vertices + 1 (0 index not used)

// Cost matrix (1-based indexing)
int cost[N][N] = {
    {I, I, I, I, I},       // 0 (not used)
    {I, 0, 4, I, 5},       // 1
    {I, I, 0, I, 5},       // 2
    {I, I, -10, 0, I},     // 3
    {I, I, I, 3, 0}        // 4
};

int d[N], parent[N];

bool BellmanFord(int src, int n) {
    for (int i = 1; i <= n; i++) {
        d[i] = I;
        parent[i] = -1;
    }
    d[src] = 0;

    // Relax all edges (n-1) times
    for (int i = 1; i <= n - 1; i++) {
        for (int u = 1; u <= n; u++) {
            for (int v = 1; v <= n; v++) {
                if (cost[u][v] != I && d[u] != I && d[u] + cost[u][v] < d[v]) {
                    d[v] = d[u] + cost[u][v];
                    parent[v] = u;
                }
            }
        }
    }

    // Check for negative-weight cycles
    for (int u = 1; u <= n; u++) {
        for (int v = 1; v <= n; v++) {
            if (cost[u][v] != I && d[u] != I && d[u] + cost[u][v] < d[v]) {
                return false; // Negative cycle detected
            }
        }
    }

    return true;
}

void printShortestPaths(int n) {
    printf("Vertex\tDistance\tParent\n");
    for (int i = 1; i <= n; i++) {
        printf("%d\t%d\t\t%d\n", i, d[i], parent[i]);
    }
}

int main() {
    
    
    if (BellmanFord(1, N-1)) {
        printf("\nShortest Paths from Vertex 1 using Bellman-Ford Algorithm:\n");
        printShortestPaths(N-1);
    } else {
        printf("Negative-weight cycle detected!");
    }

    return 0;
}
