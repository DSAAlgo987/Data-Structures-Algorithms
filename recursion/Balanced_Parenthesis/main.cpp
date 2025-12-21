#include <bits/stdc++.h>
#include <iostream>

using namespace std; 

/*
    PS: Well Balanced Parenthesis
    IP: n = 3 (open = 3, close = 3)
    OP: ((())), ()()(), (())(), ()(()), (()())
    TC: O(2^n)
    SC: n 
*/

// Aliases 
using v = vector<string>;

v ans;

// Display array 
void display(v &ans) {
    for(auto ele: ans) {
        cout << ele << " ";
    }
    
    cout << endl;
}

// Well Balanced Parenthesis 
void solve(int o, int c, string op, v &ans) {
    // Base condition 
    if(o == 0 && c == 0) {
        ans.push_back(op);
        return;
    }
    
    if(o != 0) {
        solve(o - 1, c, op + '(', ans);
    }
    if(c > o) {
        solve(o, c - 1, op + ')', ans);
    }
}

int main()
{
    solve(3, 3, "", ans);
    display(ans);

    return 0;
}