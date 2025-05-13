#include <stdio.h>
#include <string.h>

#define V 5

int graph[V][V] = {
        {0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {0, 0, 0, 1, 0}
};

int solutionCount = 0;

int isSafe(int n, int color[], int m, int v, int c){
    int i;

    // Check that adjancent vertex has  same color?
    for(i = 1; i <= n; i++){
        if(graph[v][i] && color[i] == c){
            return 0; // Conflict
        }
    }

    return 1; // No conflict
}

// Coloring the vertices from 1st vertex
void graphColoringUtil(int n, int color[], int m, int v){
    // If all vertices are colored 
    if(v == V){
        // Print solution 
        ++solutionCount;
        printf("\nSolution %d: ", solutionCount);

        printf("\nColor Assignment: \n");
        for(int i = 1; i <= n; i++){
            printf("%d vertex -> %d color\n", i, color[i]);
        }
        printf("\n");
        return;
    }

    // if not then perform following things 
    // start coloring each vertices until all colors are traversed
    for(int c = 1; c <= m; c++){
        // check adjacent vertex should not have same color 
        if(isSafe(n, color, m, v, c)){
            // Safe the assign the color 
            color[v] = c;

            // Go for other vertices 
            graphColoringUtil(n, color, m, v+1);

            // Backtrack
            color[v] = 0;
        }
    }
}


void graphColoring(int n, int m){
    int color[V];

    // Initlize color as 0 
    memset(color, 0, sizeof(color));

    // Start coloring vertices from 1st vertex
    graphColoringUtil(n, color, m, 1);

    // If there are solutions 
    if(solutionCount != 0){
        printf("\nTotal Solutions with %d colors: %d", m, solutionCount);
    }
    // If there are not any solutions
    else{
        printf("\nSolution deson't exist with %d colors.");
    }
}


int main(){
    int n = 4;
    int m = 3; // no of colors 

    graphColoring(n, m);

}