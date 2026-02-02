#include <bits/stdc++.h>
using namespace std;

/**
 * PS: Minimum Window Substring
 *
 * Problem: Given two strings s and t of lengths m and n respectively, 
 * return the minimum window substring of s such that every character in t 
 * (including duplicates) is included in the window. If there is no such substring, 
 * return the empty string "".
 * 
 * IP: String s, t; 
 * OP: String minimum window substring;
 * 
 * APPROACH: 
 *  - Variable sliding window 
 *      - TC: O(n)
 *      - SC: O(k) for m1 map 
 * 
 * LEARNING: 
 *  - Identification of variable sliding window 
 *  - j used for DEC freq 
 *  - i used for INC freq 
 */
 
// Aliases 
using umap = unordered_map<char,int>; 

// Minimum Window Substring 
string solve(string s, string t) { 
    umap m1; 
    int n = s.size(); 
    
    // Traverse t string and INC freq 
    for(auto c: t) m1[c]++; 
    
    int mn = INT_MAX, cnt = m1.size(), sIdx = -1;
    int i = 0, j = 0; 
    
    // Slidinw window 
    while(j < n) { 
        // S[j] -> present m1?
        if(m1.find(s[j]) != m1.end()) { 
            m1[s[j]]--; 
                
            if(m1[s[j]] == 0) cnt--; 
                
        }
        // All letters are used 
        if(cnt == 0) { 
            // shrink window & ans <- calc 
            // ans <- calc 
            while(cnt == 0) { 
                if(m1.find(s[i]) != m1.end()) { 
                    m1[s[i]]++;
                    if(m1[s[i]] == 1) {
                        cnt++;
                        // calculate size of that window 
                        if(mn > j - i + 1) { 
                            mn = j - i + 1; 
                            sIdx = i; 
                        }
                    } 
                }
                i++; 
            }
        }
        
        j++; // expand
    }
    
    // return ans 
    return sIdx == -1 ? "empty": s.substr(sIdx, mn); 
}

int main () {
    string s = "timetopractice"; 
    string t = "toc"; 
    
    cout << "Min Window Substr: " << solve(s, t) << endl;
}