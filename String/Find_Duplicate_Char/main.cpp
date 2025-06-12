#include <bits/stdc++.h>
using namespace std;

void solve(string &s){
    unordered_map<char, int> m;

    // Process each char and store their freqs
    for(auto &c: s){
        m[c]++;
    }

    // Display chars having more than 1 freq
    for(auto &entry: m){
        if(entry.second > 1){
            cout << entry.first << ": "<< entry.second << endl;
        }
    }
}

int main(){
    string s;

    cin >> s;
    solve(s);

    return 0;
}