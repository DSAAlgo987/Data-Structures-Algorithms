#include <stdio.h>
#include <string.h>

/**
 * Constraints:
 * 1. If we take any vertex check connection with prev vertex. 
 * 2. Check duplication in path array
 * 3. Finally check the last vertex is having connection with first vertex or not?
 */

#define V 6 // No of vertices 

int solutionCount = 0;

void print(int path[], int n){
    int i;
    ++solutionCount;
    printf("\nSolution %d:\n", solutionCount);
    for(i = 1; i <= n; i++){
        printf("%d -> ", path[i]);
    }

    // Print firxt vertex again to show the cycle
    printf("%d\n", path[1]);
}

int isSafe(int v, int graph[V][V], int n, int path[], int pos){
    // 1. Check connection with prev vertex
    if(graph[path[pos-1]][v] == 0){
        return 0; // Conflict
    }

    // 2. Check duplication in path array
    for(int i = 1; i < pos; i++){
        if(path[i] == v){
            return 0; // Conflict
        }
    }

    return 1; // No conflict
}

// Recursive function
void hamCycleUtil(int graph[V][V], int n, int path[], int pos){
    // Base case: If all vertices are included in the path
    if(pos == V){
        // Check that last vertex is having connection with first vertex
        if(graph[path[n]][1] == 1){
            // print solution
            print(path, n);
        }
        return;
    }

    // Try all vertices as candidates for the next position
    for(int v = 1; v <= n; v++){
        // Safe to place vertex in path?
        if(isSafe(v, graph, n, path, pos)){
            // Satisfy constraints then place vertex in path 
            path[pos] = v;

            // Go for other vertices to find the cycle for other position
            hamCycleUtil(graph, n, path, pos + 1);

            // Backtrack
            path[pos] = 0; 
        }
    }

}

void hamCycle(int graph[V][V], int n){
    int path[V]; // Store all the path cycles

    // Initialize path as 0 initially
    memset(path, 0, sizeof(path));

    // set path[1] to 1st vertex avoid base case 
    path[1] = 1;

    // Helping function to find cycles
    // Start from position 2 since 1 is fixed at position 1
    hamCycleUtil(graph, n, path, 2);

    // If soln count is 0 then there is no any soln
    if(solutionCount == 0){
        printf("\n\nSolution deosn't exists.");
    }else{
        printf("\nTotal Solutions: %d", solutionCount);
    }

    // Reset for other graph 
    solutionCount = 0;
}

int main(){
    int graph[V][V] = {
        {0, 0, 0, 0, 0, 0},
        {0, 0, 1, 1, 0, 1},
        {0, 1, 0, 1, 1, 1},
        {0, 1, 1, 0, 1, 0},
        {0, 0, 1, 1, 0, 1},
        {0, 1, 1, 0, 1, 0},
    };

    int n = 5; // No of vertices
    
    hamCycle(graph, n);

    int graph1[6][6] = {
        {0, 0, 0, 0, 0, 0},  // 0th row (unused)
        {0, 0, 1, 0, 0, 0},  // Vertex 1 connected to 2
        {0, 1, 0, 1, 0, 0},  // Vertex 2 connected to 1, 3
        {0, 0, 1, 0, 1, 0},  // Vertex 3 connected to 2, 4
        {0, 0, 0, 1, 0, 1},  // Vertex 4 connected to 3, 5
        {0, 0, 0, 0, 1, 0}   // Vertex 5 connected to 4
    };
    
    hamCycle(graph1, n); // Doesn't contain cycle
}