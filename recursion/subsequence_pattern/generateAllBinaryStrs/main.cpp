#include <bits/stdc++.h>
using namespace std;

/*
    PS: Generate all balanced Parenthesis
    IP: int n;
    OP: return all binary strings which do not contains
        consecutive 1's and strings must be in lexicographically sorted
    Approach: Recursion (Extended IP OP method)
    TC: O(2^n)
    SC: O(n) : recursive stack calls
    back(): To check last character : O(1)
*/

// Aliases
using v = vector<string>;

v ans;

// Generate all balanced parenthesis
void solve(int n, string s) {
    // BC 
    if(n == 0) {
        ans.push_back(s);
        return;
    }

    // add 0's always
    solve(n - 1, s + '0');

    if(s.empty() || s.back() != '1') {
        solve(n - 1, s + '1');
    }
}

int main(){
    int n = 3;
    string s = "";

    solve(n, s);

    for(auto s: ans) {
        cout << s << " ";
    }

    
    return 0;
}