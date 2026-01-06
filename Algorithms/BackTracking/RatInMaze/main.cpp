#include <bits/stdc++.h>
using namespace std;

/**
 * PS: Rat in a maze (0 -> wall, 1 -> path)
 * IP: N, M[N][N]
 * OP: Return all possible paths 
 * APPROACH: Backtracking 
 * TC: O(4^N)
 * SC: O(N)
 */

// Aliases
using v = vector<int>;
using vv = vector<v>;

// Global variables
int N = 7;
vv M = { 
    {1, 0, 0, 0, 0, 0, 0},
    {1, 1, 0, 1, 1, 1, 0},
    {0, 1, 0, 0, 0, 1, 0},
    {1, 1, 1, 1, 0, 1, 0},
    {0, 0, 0, 1, 1, 1, 0},
    {0, 0, 0, 0, 0, 1, 1},
    {0, 0, 0, 0, 0, 0, 1}
};

// vv soln(row, vector<int>(cols, valueToInitializeWith))
vv soln(2, v(N*N, 0));

// Display Function 
void display(vv &soln, int p) {
    for(int j = 0; j < p; j++) {
        cout << "(" << soln[0][j] << "," << soln[1][j] << ") ";
    }
    cout << endl;
}

// RIM Function 
void RIM(int i, int j, int p) {
    // BC: When it reaches to exit 
    if(i == N - 1 && j == N - 1) {
        // Dipslay ans 
        display(soln, p);
        return;
    }

    // Start
    M[i][j] = 0; // Mark it as visited 
    soln[0][p] = i; // Set path -> soln
    soln[1][p] = j; // Set path -> soln

    // Explore all possible paths 
    // Right (i, j + 1) & next cell must be a path(1)
    if(j + 1 < N && M[i][j+1] == 1)
        RIM(i, j + 1, p + 1);
    
    // Down (i+1, j) & next cell must be a path(1)
    if(i + 1 < N && M[i+1][j] == 1) 
        RIM(i+1, j, p + 1);
    
    // Left (i, j - 1) & next cell must be a path(1)
    if(j > 0 && M[i][j-1] == 1) 
        RIM(i, j - 1, p + 1);
    
    // Up (i-1, j) & next cell must be a path(1)
    if(i > 0 && M[i-1][j] == 1) 
        RIM(i - 1, j, p + 1);
    

    // When it reaches to leaf node then it backtracks 
    M[i][j] = 1; // Mark visited as unvisited 
}

int main() {
    RIM(0, 0, 0);

    return 0;
}