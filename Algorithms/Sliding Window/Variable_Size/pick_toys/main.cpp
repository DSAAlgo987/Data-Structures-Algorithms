#include <bits/stdc++.h>
using namespace std; 

/**
 * PS: Pick Toys 
 * 
 * Problem: You are given an array which consists of toys. 
 * Your task is to help john to pick Mx quantity of toys of mx two types toys.
 * John can only pick toys in sequence manner and it can only take two types of toys
 * maximum.
 * 
 * IP: vector<int> A; 
 * OP: return Mx quantity of toys (int);
 * 
 * APPROACH: 
 *  - Sliding window: 
 *      - TC: O(n)
 *      - SC: O(k) for map 
 * 
 * LEARNING: 
 *  - Identification of variable sliding window 
 *  - Relation with other solved problem 
 */
 
// aliases 
using umap = unordered_map<char, int>; 

// Global vars 
int k = 2; // mx two types toys 

// Pick toys 
int solve(string &s) { 
    int i = 0, j = 0, mx = INT_MIN;
    int n = s.size(); 
    
    umap m1; 
    
    while(j < n) { 
        // calc 
        m1[s[j]]++; 
        
        // hit condition 
        if(m1.size() <= k) { 
            // ans <- calc 
            mx = max(mx, j - i + 1); 
            
            // expand
            j++; 
        }
        // > condition 
        else if(m1.size() > k) {
            // Shrink: Remove ith calcl 
            while(m1.size() > k) { 
                m1[s[i]]--; 
                
                if(m1[s[i]] == 0) m1.erase(s[i]);
                
                i++;
            }
            j++;
        }
    }
    
    // Return ans 
    return mx == INT_MIN ? 0: mx; 
}

int main() { 
    string s = "abaccab";
    
    cout << "MX QTY of Toys: " << solve(s) << endl;
    return 0;
}