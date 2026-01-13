#include <bits/stdc++.h>
using namespace std; 

/**
 * PS: M-Coloring Problem (1-indexed)
 *
 * Problem:
 *   Given an undirected graph G with N vertices and M colors,
 *   determine all possible ways to color the vertices such that
 *   no two adjacent vertices have the same color.
 *
 * IP:
 *   - Graph G represented as adjacency matrix G[N][N]
 *   - Integer M (number of colors)
 *
 * OP:
 *   - All valid color assignments (or true/false if at least one exists)
 *
 * CONSTRAINT:
 *   - No two adjacent vertices can have the same color
 *
 * APPROACH:
 *   - Backtracking
 *   - Assign colors to vertices one by one
 *   - For each vertex, try all M colors
 *   - Check safety before moving to the next vertex
 *   - Backtrack if no color leads to a valid solution
 *
 * TC:
 *   - O(M^N) (worst case)
 *
 * SC:
 *   - O(N) (recursion stack + color array)
 *
 * LEARNING:
 *   - How to apply backtracking on graph problems
 *   - How vertex-wise decisions reduce problem size
 *   - Importance of safety checks before recursion
 *   - Understanding exponential search space (M choices per vertex)
 *   - Difference between graph traversal and graph backtracking
 */

// Aliases
using v= vector<int>;
using vv = vector<v>;

// Global Vars 
int N = 5; 

vv graph = {
    {0, 0, 0, 0, 0}, // 0
    {0, 0, 1, 1, 0}, // 1
    {0, 1, 0, 1, 1}, // 2
    {0, 1, 1, 0, 1}, // 3 
    {0, 0, 1, 1, 0}, // 4
};

int m = 3;

vv ans;
int totalSoln = 0; 

// Bounding function: isSafe 
bool isSafe(vv &graph, int U, int c, v &color) {
    // Traverse each vertex 
    for(int V = 1; V < N; V++) {
        // No two adjancet vertex should have same 
        if(graph[U][V] == 1 && color[V] == c) {
            return false;
        }
    }

    // Safe to place that color 
    return true; 
}

// Helper function 
void graphColoringUtil(vv &graph, int m, v &color, int V) {
    // BC 
    if(V == N) {
        ans.push_back(color);
        totalSoln++;
        return;
    }

    // Then Start coloring node 
    for(int c = 1; c <= m; c++) {
        // Before placing color check is it safe?
        if(isSafe(graph, V, c, color)) {
            // place color 
            color[V] = c; 

            // DO this to other vertices 
            graphColoringUtil(graph, m, color, V + 1);

            // When it backtracks make color 0 again 
            color[V] = 0;
        }
    }
}

// Graph coloring function
void graphColoring(vv &graph, int m) {
    v color(N, 0); // It will store color of adjancent node 

    // Now, start coloring with 1st vertex 
    graphColoringUtil(graph, m, color, 1);
}

void display(vv &ans) {
    // if soln exists 
    if(totalSoln == 0) {
        cout << "Soln doesn't exist" << endl;
    } else {
        for(auto i: ans) {
            for(auto j: i) {
                cout << j << " ";
            }
            cout << endl;
        }
        cout << "Total Solns: " << totalSoln << endl;
    }
}
 
int main()
{
    graphColoring(graph, m);

    display(ans);

    return 0;
}