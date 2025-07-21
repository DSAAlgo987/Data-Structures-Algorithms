#include <bits/stdc++.h>
using namespace std;

// Problem: Longest substring with all unique characters 

int longestSubstringWithoutRepeating(string &s){
    int i = 0, j = 0, mx = INT_MIN; 
    unordered_map<char, int> mp;

    // Base case 
    if(s.size() == 0){
        return 0;
    }

    while(j < s.size()){
        // Calculation
        mp[s[j]]++;

        // mp size same as window size
        if(mp.size() == j - i + 1){
            // Ans <- calculation 
            mx = max(mx, j - i + 1);
            j++;
        }
        // mp size less than window size
        else if(mp.size() < j - i + 1){
            // Remove ith element until equal or greater than window size 
            while(mp.size() < j - i + 1){
                // Remove ith calculation 
                mp[s[i]]--;

                if(mp[s[i]] == 0){
                    mp.erase(s[i]);
                }

                i++;
            }
            j++;
        }
    }

    return mx;
}

int main(){
    string s = "";

    int ans = longestSubstringWithoutRepeating(s);

    cout << ans << endl;
    return 0;
}