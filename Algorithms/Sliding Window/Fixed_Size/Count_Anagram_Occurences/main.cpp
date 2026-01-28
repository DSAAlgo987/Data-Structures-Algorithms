#include <bits/stdc++.h>
using namespace std;

/**
 * PS: # occurrences of anagrams 
 * 
 * PROBLEM: You are given two strings s, ptn of different length.
 * Your task it to find # occurrences of anagrams. 
 * 
 * IP: String s, ptn; 
 * OP: # -> (int);
 * 
 * APPROACH: 
 *  1. Brute Force: TC: O(n^2), SC: O(n) 
 *  2. Sliding window: TC: O(n), SC: O(n)
 * 
 * LEARNING: 
 *  - Count is built-in variables in cpp.
 * 
 */

// Brute force 
int solve(string s, string ptn) { 
    int m = s.size(); 
    int n = ptn.size(); 

    int cnt = 0; 

    // Sort ptn string 
    sort(ptn.begin(), ptn.end());

    // Generate substring of lenthg n 
    for(int i = 0; i < m - n + 1; i++) { 
        string winChar = "";
        for(int j = i; j < i + n; j++) { 
            // append s[j] char 
            winChar += s[j];
        }

        // Check is it anagram?
        sort(winChar.begin(), winChar.end());

        if(winChar == ptn) cnt++;
    }

    return cnt; 
}

// Sliding window
int countOccurrences(string s, string ptn) { 
    int m = s.size(); 
    int n = ptn.size(); 

    // Create unordered map m1 
    unordered_map<char, int> m1; 

    // Add ptn with freq -> m1 
    for(auto c: ptn) m1[c]++;
    
    int cnt = m1.size(); // Track # of unique letters
    int ans = 0; 

    // start sliding window 
    int i = 0, j = 0;
    while(j < m) { 
        // Calc
        if(m1.find(s[j]) != m1.end()) {
            m1[s[j]]--;
            
            if(m1[s[j]] == 0) cnt--;
        }

        // Achieve ws 
        if(j - i + 1 < n) j++;

        // hit ws 
        else if(j - i + 1 == n) { 
            // ans <- calc 
            if(cnt == 0) ans++;

            // slide window 
            if(m1.find(s[i]) != m1.end()) {
                m1[s[i]]++;

                if(m1[s[i]] == 1) cnt++;
            }
            i++;
            j++;
        }
    }

    return ans; 
}

int main(){
    string s = "forrxxorrfxdrrof";
    string ptn = "forr";

    cout << "#: " << solve(s, ptn) << endl; 
    cout << "#: " << countOccurrences(s, ptn) << endl;
    
    return 0;
}