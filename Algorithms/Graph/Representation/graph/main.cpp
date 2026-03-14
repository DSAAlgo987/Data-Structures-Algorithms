#include <bits/stdc++.h>
using namespace std; 

/**
 * Undirected Graph Representation: 
 * Data structures, Which are used to represent the Graph. 
 * 
 * 1. Adjacency Matrix: 
 * TC: O(V^2) -> we have to visit vertices even if it's connected or not.
 * 
 * 2. Adjacency List: 
 * TC: O(V + E) -> we need to visit those vertices which are adjacent.
 */

// Aliases
using v = vector<int>;
using vv = vector<v>; 

// Adjacency Matrix 
void AdjMat() { 
    int n; 
    cin >> n; 
    
    vv adjMat(n, v(n, 0)); 

    // Create 
    for(int i = 0; i < n; i++) { 
        for(int j = i + 1; j < n; j++) { 
            cin >> adjMat[i][j]; 
            adjMat[j][i] = adjMat[i][j];
        }
    }

    // Display 
    for(int i = 0; i < n; i++) { 
        for(int j = 0; j < n; j++) 
            cout << adjMat[i][j] << " ";
        cout << endl; 
    }
}


// Adjancency List 
void AdjList() { 
    int n, m; 
    cin >> n >> m; 
    
    vv adj(n);
    
    // create 
    for(int i = 0; i < m; i++) { 
        int u, v;   
        cin >> u >> v; 
        
        adj[u].push_back(v);
        adj[v].push_back(u); 
    }
    
    cout << endl;
    // display
    for(auto u: adj) {
        for(auto v: u) cout << v << " ";
        cout << endl;
    }
}


int main() { 
    // AdjMat(); 
    AdjList(); 
    return 0; 
}