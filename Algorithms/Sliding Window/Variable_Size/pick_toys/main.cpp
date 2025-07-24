#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: john and his mommy went to mall and john asked his mom to buy toys for him.
 * Mom has two condts: 
 * 1. Line se uthau toys
 * 2. Mx 2 types ke hu 
 * 
 * Ip:
 * 1. string : consists of letters that represent toys
 * 2. k : max types 
 * 
 * Op: Return # no toys john can have.
 */

// n
int pickToys(string &str, int k){
    int i = 0, j = 0, mx = INT_MIN; 
    unordered_map<char, int> mp;

    while(j < str.size()){
        // calculation 
        mp[str[j]]++;

        if(mp.size() <= k){
            // ans <- calculation 
            mx = max(mx, j - i + 1);
            j++;
        }
        else if(mp.size() > k){
            while(mp.size() > k){
                mp[str[i]]--;

                if(mp[str[i]] == 0){
                    mp.erase(str[i]);
                }

                i++;
            }

            j++;
        }
    }

    return mx;
}

int main(){
    string s = "abaccab";

    int k = 2;

    cout << pickToys(s, k);
    return 0;
}