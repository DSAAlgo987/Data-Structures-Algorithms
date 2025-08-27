#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Statement: Implement Breadth First Search 
 * It uses Queue internally and which follow fifo pattern
 * 
 * ip:
 * Adj_list / Adj_matrix 
 *  
 * op:
 * display BFS
 */

/**
 * Time Complexity: 
 *  Adj List: O(V + E)
 *  Adj Matrix: O(V^2)
 */
void BFS(vector<vector<int>> &adjList, int n, list<int> q) {
    vector<int> visited(n, false); // To track which vertices are visited

    // Iterate all over the vertices until all the vertices are traversed
    while(!q.empty()) {
        int currentNode = q.front(); // Get that node 

        cout << currentNode << " "; // Display it 

        q.pop_front(); // Remove it from the front
        visited[currentNode] = true;

        // Push the connected nodes of currentNode to the Q
        for(auto &child: adjList[currentNode]) {
            // Not visited
            if(!visited[child]) {
                q.push_back(child);
            }
        }
    }
}

int main(){
    vector<vector<int>> adjList = {
        {0},
        {2, 4}, // 1
        {1, 3}, // 2
        {2},    // 3
        {1, 5}, // 4
        {4}     // 5
    };

    int src = 1;

    list<int> q;
    // Initially insert src node 
    q.push_back(src);

    BFS(adjList, adjList.size(), q); // OP: 1 2 4 3 5
    
    return 0;
}