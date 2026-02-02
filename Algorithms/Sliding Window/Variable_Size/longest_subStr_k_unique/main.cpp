#include <bits/stdc++.h> 
using namespace std; 

/**
 * PS: Longest substring with k unique chars 
 * 
 * Problem: You are given a string s and k.
 * Your task is to find out longest substring with k unique chars. 
 * 
 * IP: string s, int k;
 * OP: int -> longest substring size 
 * 
 * APPROACH: 
 *  - Sliding window: TC: O(n), SC: O(k)
 * 
 * LEARNING: 
 *  - Identification of variable sliding window
 *  - map to identify unique chars. 
 */
 
// aliases 
using umap = unordered_map<char,int>;

// Longest substring with k unique chars 
int solve(string &s, int k) { 
    int n = s.size();
    int i = 0, j = 0; 
    int mx = INT_MIN; 
    
    umap m1; 
    
    while(j < n) { 
        // calc 
        m1[s[j]]++;
        
        // achieve cond 
        if(m1.size() < k) j++;
        
        // hit cond 
        else if(m1.size() == k) { 
            // ans <- calc 
            mx = max(mx, j - i + 1);
            j++; // expand 
        } 
        // > cond 
        else if(m1.size() > k) { 
            // remove ith calc
            while(m1.size() > k) {
                m1[s[i]]--; 
                
                if(m1[s[i]] == 0) m1.erase(s[i]);
                
                i++; 
            }
            
            j++;
        }
    }
    
    // return the ans 
    return mx == INT_MIN ? 0: mx; 
}

int main()
{
    string s = "aabacbebebe";
    int k = 3; 
    
    cout << "longest substring size: " << solve(s, k) << endl;
    return 0;
}