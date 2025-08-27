#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Statement: Find a valid path is exists between src and dst.
 * If exists return True o/w False;
 * 
 * Ip:
 * n, edges, src, dst
 * 
 * op:
 * T/F
 */

// O(V + E) : Bcoz here i used adj list insetead of adj. matrix
bool dfs(int n, vector<vector<int>> &adj, int src, int dst) {
    stack<int> st;
    vector<int> visited(n, false); // Initially no one visited 

    st.push(src); // Push src node 
    visited[src] = true; // Set src node as visited

    // Start iterating all the remaining nodes 
    // Visit one node : O(V)
    while(!st.empty()) {
    
        int currentNode = st.top(); // Store top node  to currentNode
        st.pop();

        if(currentNode == dst) {
            return true;
        }
      
        // Go with for neighbour nodes
        // Explore all its neighbour Once: O(E)
        for(auto &neigh : adj[currentNode]) {
            if(!visited[neigh]) {
                st.push(neigh); // push connected nodes to stack 
                visited[neigh] = true; // set visited as true for currentNode
            }
        }
    }

    return false;
}


bool validPath(int n, vector<vector<int>> &edges, int src, int dst) {
    // Base case 
    if(src == dst) {
        return true;
    }

    if(n == 0) {
        return false; // No nodes -> no path
    }

    // Step 1: Create adj list 
    vector<vector<int>> adj(n);

    for(auto e: edges) {
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]); // Bcoz graph is undirected
    }

    // Step 2: Perform DFS on Adj. list 
    return dfs(n, adj, src, dst);
}

int main(){
    int n = 3;
    vector<vector<int>> edges = {
        {0, 1}, {1, 2}, {2, 0}
    };

    int src = 0;
    int dst = 2;

    cout << (validPath(n, edges, src, dst) ? "TRUE" : "FALSE") << endl;
    return 0;
}