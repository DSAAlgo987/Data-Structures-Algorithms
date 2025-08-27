#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Statement: Depth First Search
 * It uses stack to traverse all nodes and follows LIFO pattern.
 *
 * Recursive approach will be preOrder, inOrder & postOrder.
 */

// Iterative approach: O(V^2)
void dfs(vector<vector<int>> &graph, int src, int n) {
    stack<int> st; // To store nodes 
    vector<int> visited(n+1, 0); // Visited to track which node is visited or not 

    st.push(src); // Initially push src node 

    // Iterate all the remaining nodes until stack becomes empty 
    while(!st.empty()) {
        // pop that node from stack 
        int currentNode = st.top();
        st.pop();

        cout << currentNode << " ";

        // set visited for that displayed node 
        visited[currentNode] = 1;

        // Identify the connectede nodes of currentNode 
        for(int v = 1; v < n; v++) {
            // Push those nodes which are connected & not visited 
            if(graph[currentNode][v] == 1 && visited[v] == 0) {
                // push into the stack 
                st.push(v);
            }
        }
    }   

}

// Time complexity: O(V^2)
void dfsRecursive(vector<vector<int>> &graph, int src, vector<bool> &visited) {
    // not visisted 
    if(!visited[src]) {
        // Display 
        cout << src << " ";

        // Set visisted 
        visited[src] = true;

        // Explore all it's adjacent vertices 
        for(int v = 1; v < graph.size(); v++) {
            // Connected and not visited 
            if(graph[src][v] == 1 && !visited[v]) {
                // Then apply dfs on them 
                dfsRecursive(graph, v, visited);
            }
        }
    }
}

int main() {
    vector<vector<int>> graph = {
        {0, 0, 0, 0, 0, 0},
        {0, 0, 1, 1, 0, 0}, // 1
        {0, 1, 0, 0, 1, 0}, // 2
        {0, 1, 0, 0, 0, 1}, // 3
        {0, 0, 1, 0, 0, 0}, // 4
        {0, 0, 0, 1, 0, 0}, // 5
    };

    int n = graph.size();
    
    // dfs(graph, 1, n); // Start from 1st node 
    // op: 1 3 5 2 4

    vector<bool> visited(n, false);

    dfsRecursive(graph, 1, visited);

    return 0;
}