#include <stdio.h>
#include <limits.h>
#define I INT_MAX

// Initialization
int cost[7][7] = {
    {I, I, I, I, I, I, I}, // 0
    {I, I, 2, 4, I, I, I}, // 1
    {I, I, I, 1, 7, I, I}, // 2
    {I, I, I, I, I, 3, I}, // 3
    {I, I, I, I, I, I, 1}, // 4
    {I, I, I, I, 2, I, 5}, // 5
    {I, I, I, I, I, I, I}  // 6
};

// Distance array for Dijkstra's Algorithm
int d[9] = {I};
int parent[9] = {-1};
int visited[9] = {0};

// Dijkstra's Algorithm for Shortest Path
void Dijkstra(int src, int n)
{
    int min, u, i, j;
    // Initialize distances to infinity
    for (i = 1; i <= n; i++)
    {
        d[i] = I;
        visited[i] = 0;
    }
    // Distance to source is 0
    d[src] = 0;
    for (i = 1; i <= n; i++)
    {
        // Find the vertex with minimum distance which is not yet visited
        min = I;
        u = -1;
        for (j = 1; j <= n; j++)
        {
            if (!visited[j] && d[j] < min)
            {
                min = d[j];
                u = j;
            }
        }
        if (u == -1)
            break; // All vertices are visited or unreachable
        visited[u] = 1;
        // Relaxation step
        for (j = 1; j <= n; j++)
        {
            if (!visited[j] && cost[u][j] != I && d[u] + cost[u][j] < d[j])
            {
                d[j] = d[u] + cost[u][j];
                parent[j] = u;
            }
        }
    }
}
int main()
{
    int i, j, u, v, k, min = I, n = 6, sum = 0;

    // Dijkstra's Algorithm to find shortest path from vertex 1
    Dijkstra(1, n);
    // Output Dijkstra's result
    printf("\nShortest Paths from Vertex 1 using Dijkstra's Algorithm:\n");
    printf("Vertices Distance Parent\n");
    for (i = 1; i <= n; i++)
    {
        if (i != 1)
        {
            printf("%d\t %d\t %d\n", i, d[i], parent[i]);
        }
    }
    return 0;
}