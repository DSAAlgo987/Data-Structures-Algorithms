#include <bits/stdc++.h> 

using namespace std; 

int solve(string &s, int k){
    int mx = 0, i = 0, j = 0;
    unordered_map<char, int> mp;
    while(j < s.size()){
        // Calculation 
        mp[s[j]]++;

        if(mp.size() < k){
            j++;
        }
        else if(mp.size() == k){
            // ans <- calculation 
            mx = max(mx, j - i + 1);
            j++;
        }
        else if(mp.size() > k){
            while(mp.size() > k){
                mp[s[i]]--;

                if(mp[s[i]]== 0){
                    mp.erase(s[i]);
                }
                i++;
            }

            j++;
        }
    }

    return (mp.size() == k) ? mx : -1;
}

int main(){
    string s = "aaa";
    int k = 3;

    int ans = solve(s, k);

    cout << ans << endl;

    return 0;
}