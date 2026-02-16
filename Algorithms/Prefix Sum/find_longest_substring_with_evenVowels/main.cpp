#include <stdio.h>
#include <bits/stdc++.h>

using namespace std; 

// longest substing containing vowels in even cnt 
int solve(string &s) {
   
    int n = s.size(); 
    int mx = INT_MIN; 
    
    // Traverse s and generate all possible substring 
    for(int i = 0; i < n; i++) { 
        unordered_map<char, int> m = {
            {'a',0},
            {'e',0},
            {'i',0},
            {'o',0},
            {'u',0},
        };
    
        for(int j = i; j < n; j++) { 
            if(m.find(s[j]) != m.end())
                m[s[j]]++; 
            cout << s[j];
            // if freq of vowels is in even cont 
            if(m['a'] % 2 == 0 && m['e'] % 2 == 0 && m['i'] % 2 == 0 && m['o'] % 2 == 0 && m['u'] % 2 == 0) {
                mx = max(mx, j - i + 1); 
            }
        }
        cout << endl;
    }
    
    return mx; 
}

int main()
{
    string s = "eleetminicoworoep";
    
    cout << solve(s) << endl;
    return 0;
}