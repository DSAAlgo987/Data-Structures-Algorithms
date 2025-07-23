#include <bits/stdc++.h>
using namespace std;

// nlgn
string longestCommonPrefix(vector<string>& strs) {
    // base case 
    if(strs.size() == 0){
        return "";
    }
    string ans = "";

    // sort ip string 
    sort(strs.begin(), strs.end()); // nlgn

    string first = strs[0];
    string last = strs[strs.size() - 1];

    // Compare first and last strings char by char.
    for(int i = 0; i < first.size() && i < last.size(); i++){
        if(first[i] != last[i]){
            break;
        }
        ans += first[i];
    }

    return ans;
}

int main(){
    vector<string> strs = {"faiz", "faizan", "faiza"};

    cout << longestCommonPrefix(strs);
    
    return 0;
}