#include <bits/stdc++.h>
using namespace std;

string minWindow(string s, string t){
    int i = 0, j = 0, minLen = INT_MAX, start = 0, count = 0;

    unordered_map<char, int> mp;

    // Store t into map
    for(auto c: t){
        mp[c]++;
    }

    // Store size of unique chars
    count = mp.size();

    // Sliding window
    while(j < s.size()){
        // Calculation 
        if(mp.find(s[j]) != mp.end()){
            // Remove freq 
            mp[s[j]]--;

            // if it becomes 0 
            if(mp[s[j]] == 0){
                count--;
            }
        }
        // if count becomes 0 
        if(count == 0){
            // Shrink window by incrementing i when count == 0
            while(count == 0){
                if(mp.find(s[i]) != mp.end()){
                    // INC freq 
                    mp[s[i]]++;

                    // if char freq becomes 1 
                    if(mp[s[i]] == 1){
                        count++;
                        // calculate size of that window 
                        if(j - i + 1 < minLen){
                            start = i;
                            minLen = j - i + 1;
                        }
                    }
                }
                i++;
            }
        }

        j++;
    }

    if(minLen == INT_MAX) return "";
    // substr(pos, len)
    return s.substr(start, minLen);
}

int main(){
    string s = "TOTMTAPTAT";
    string t = "TAT";

    cout << minWindow(s, t) << endl;
    return 0;
}