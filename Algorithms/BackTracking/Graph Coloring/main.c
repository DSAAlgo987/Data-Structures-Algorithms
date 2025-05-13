#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define V 5

int solutionCount = 0;

bool isSafe(int graph[V][V], int color[], int v, int c) {
    for (int i = 1; i < V; i++) {
        if (graph[v][i] && color[i] == c)
            return false;
    }
    return true;
}

void graphColoringUtil(int graph[V][V], int m, int color[], int v) {
    if (v == V) {
        solutionCount++;
        printf("Solution %d:\n", solutionCount);
        for (int i = 1; i < V; i++) {
            printf("Vertex %d → Color %d\n", i, color[i]);
        }
        printf("\n");
        return;
    }

    for (int c = 1; c <= m; c++) {
        if (isSafe(graph, color, v, c)) {
            color[v] = c;
            graphColoringUtil(graph, m, color, v + 1);
            color[v] = 0; // Backtrack
        }
    }
}

void graphColoring(int graph[V][V], int m) {
    int color[V] = {0};
    graphColoringUtil(graph, m, color, 1);

    if (solutionCount == 0)
        printf("No valid coloring possible with %d colors.\n", m);
    else
        printf("Total Solutions: %d\n", solutionCount);
}

int main() {
    int graph[V][V] = {
       {0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {0, 0, 0, 1, 0}
    };

    int m = 3; // Number of colors
    graphColoring(graph, m);
    return 0;
}
