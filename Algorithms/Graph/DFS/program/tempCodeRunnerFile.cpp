void dfs(vector<vector<int>> &graph, int src, int n) {
//     stack<int> st; // To store nodes 
//     vector<int> visited(n+1, 0); // Visited to track which node is visited or not 

//     st.push(src); // Initially push src node 

//     // Iterate all the remaining nodes until stack becomes empty 
//     while(!st.empty()) {
//         // pop that node from stack 
//         // Visit one node : O(V)
//         int currentNode = st.top();
//         st.pop();

//         cout << currentNode << " ";

//         // set visited for that displayed node 
//         visited[currentNode] = 1;

//         // Identify the connectede nodes of currentNode 
//         // Explore all its neighbour Once: O(E)
//         for(int v = 1; v < n; v++) {
//             // Push those nodes which are connected & not visited 
//             if(graph[currentNode][v] == 1 && visited[v] == 0) {
//                 // push into the stack 
//                 st.push(v);
//             }
//         }
//     }   

// }