#include <bits/stdc++.h>
using namespace std;

/**
 * Graph Traversing: 
 *  1. BFS: Breadth First Search 
 *  It traverses level by level 
 *  It identifies the shallowest node
 *  Internally, it uses Queue DS for implementation
 * 
 *  Algo: 
 *  1. Visiting 
 *  2. Explore all it's neighbour nodes (adjacent nodes)
 * 
 *  A: 
 *      TC: O(V + E) 
 *      SC: O(V) for Q and Visited 
 */
 
// Aliases
using v = vector<int>; 
using vv = vector<v>; 

// adjList
vv adjList() { 
    int n, m; 
    cin >> n >> m; 
    
    vv adj(n); 
    
    for(int i = 0; i < m; i++) { 
         int u , v;
         cin >> u >> v; 
         
         adj[u].push_back(v);
         adj[v].push_back(u);
    }
    
    return adj;
}

// BFS: Breadth First Search 
void bfs(vv &adj, int src) { 
    int n = adj.size(); 
    
    v visited(n, false);
    list<int> q; 
    
    q.push_back(src);
    visited[src] = true; // mark immediately
    
    while(!q.empty()) { 
        // 1. visiting 
        int currNode = q.front();
        cout << currNode << " ";
        q.pop_front(); 
        
        
        // 2. Exploring all it's neighbour vertices 
        for(auto &child: adj[currNode]) {
            if(!visited[child]) {
                visited[child] = true; 
                q.push_back(child); 
            }
        }
    }
}

int main() {
    vv adj = {
        {1, 2, 3},
        {0, 2},
        {0, 1, 3, 4},
        {0, 2, 4},
        {2, 3, 5, 6},
        {4}, 
        {4}, 
    };
    
    bfs(adj, 0); 
    
    return 0; 
}