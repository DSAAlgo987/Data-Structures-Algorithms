#include <bits/stdc++.h>
using namespace std; 

/**
 * Graph Traversing: 
 * 
 * DFS (Depth First Searching):
 *  It traverses the vertices depth wise. 
 *  It uses stack/recursion for implementation. 
 * 
 * TC: 
 *  Adj List: O(V + E) 
 *  Adj Matrix: O(V^2)
 * 
 * SC: O(V) -> Max Depth/ Stack depth 
 */
 
// aliases
using v = vector<int>;
using vv = vector<v>;

// DFS 
void dfs(vv &adj, v &visited, int u) { 
    // Visiting 
    visited[u] = true; 
    cout << u << " ";
    
    // Explore it's adjacent neighbours
    for(auto &nbr: adj[u]) {
        if(!visited[nbr]) dfs(adj, visited, nbr); 
    }
}


int main()
{
    vv adj = {
        {1, 2, 3},
        {0, 2},
        {0, 1, 3, 4},
        {0, 2, 4},
        {2, 3, 5, 6},
        {4},
        {4},
    };
    int n = adj.size(); 
    
    v visited(n, false);
    
    dfs(adj, visited, 0);
    
    return 0;
}