#include <bits/stdc++.h>
using namespace std; 

/**
 * Directed Graph Representation: 
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
    
    vv adj(n, v(n, 0)); 
    
    // create
    for(int u = 0; u < n; u++) { 
        for(int v = 0; v < n; v++) { 
            if(u == v) continue; 
            
            cout << u << v << ": ";
            cin >> adj[u][v]; 
        }
    }
    
    // display 
    for(auto u: adj) {
        for(auto v: u) cout << v << " ";
        cout << endl; 
    }
}


// Adjancency List 
void AdjList() { 
    int n; 
    cin >> n; 
    
    vv adj(n);
    
    // create 
    for(int u = 0; u < n; u++) { 
        int m; 
        cout << u << ": ";
        cin >> m; 
        
        for(int j = 0; j < m; j++) { 
            int v; 
            cin >> v; 
            
            adj[u].push_back(v);
        }
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