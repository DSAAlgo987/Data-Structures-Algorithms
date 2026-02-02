#include <bits/stdc++.h> 
using namespace std; 

/**
 * PS: Longest substring without repeating chars.
 * 
 * Problem: You are given a string s. 
 * Your task is to find out longest substring without repeating chars. 
 * 
 * IP: string s;
 * OP: longest length -> <int>;
 * 
 * APPROACH: 
 *  - Sliding window: 
 *      TC: O(n) 
 *      SC: O(k) for map size 
 * 
 * LEARNING: 
 *  - Identifiction of variable sliding window 
 *  - similar with longest substring of k unique chars 
 */

// aliases 
using umap = unordered_map<char, int>; 

// Longest substring without repeating chars 
int solve(string s) { 
    int n = s.size(), mx = INT_MIN, i = 0, j = 0; 
    
    umap m1; 
    
    while(j < n) { 
        // calc 
        m1[s[j]]++; 
        
        // hit condition 
        if(m1.size() == j - i + 1) { 
            mx = max(mx, j - i + 1); // ans <- calc 
            j++;        // expand 
        }
        
        // < condition
        else if(m1.size() < j - i + 1) { 
            // shrink: remove ith calc 
            while(m1.size() < j - i + 1){
                m1[s[i]]--; 
                
                if(m1[s[i]] == 0) m1.erase(s[i]);
                
                i++; // shrink 
            }
            
            j++; 
        }
    }
    
    return mx == INT_MIN ? 0: mx; 
}

int main()
{
    string s = "pwwkew"; 
    
    cout << "Longest substring length: " << solve(s) << endl;
    return 0;
}