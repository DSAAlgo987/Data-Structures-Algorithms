/**
    Cycle Detection using DSU (Disjoint Set union):
    
    -ve value represent individul subset/ head of a set
    +ve value repsent parent of current element element 
    
    Analysi: 
        TC: O(E) 
        SC: O(V) for set(parent)
    
*/

class Solution {
  public:
    // Aliases 
    using v = vector<int>; 
    using vv = vector<v>; 
    
    // Global Vars
    v parent;
    
    void initialize(int n) { 
        for(int i = 0; i < n; i++) parent.push_back(-1); 
    }
    
    // weighted union
    void unionSet(int u, int v) { 
        if(parent[u] < parent[v]) { 
            parent[u] += parent[v]; 
            parent[v] = u; 
        }
        else {
            parent[v] += parent[u]; 
            parent[u] = v; 
        }
    }
    
    int find(int u) { 
        while(parent[u] > -1) u = parent[u]; 
        
        return u; 
    }
    
    bool isCycle(int V, vector<vector<int>>& edges) {
        initialize(V);
        
        // Traverse edges 
        for(auto &e: edges) { 
            int u = e[0];
            int v = e[1]; 
            
            int set_u = find(u);
            int set_v = find(v); 
            
            // same parents ? 
            if(set_u == set_v) return true; // cycle deteced 
            
            // not then perfrom union of parents 
            unionSet(set_u, set_v); 
        }
        
        return false; // no cycle detected
    }
};