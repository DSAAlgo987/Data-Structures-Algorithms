#include <bits/stdc++.h>
using namespace std;

// n* klgk
vector<vector<string>> groupAnagrams(vector<string> str){
    unordered_map<string, vector<string>> mp;

    for(auto &s: str){
        string sorted_str = s;
        sort(sorted_str.begin(), sorted_str.end());

        mp[sorted_str].push_back(s);
    }

    vector<vector<string>> result;

    for(auto it: mp){
        result.push_back(it.second);
    }

    return result;
}

int main(){
    vector<string> str = {"tea", "aet", "eat", "bat", "nat", "tan"};

    vector<vector<string>> ans = groupAnagrams(str);

    for(auto i: ans){
        for(auto s: i){
            cout << s << " ";
        }
    }
    return 0;
}