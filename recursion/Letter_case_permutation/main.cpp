#include <bits/stdc++.h>
#include <stdio.h>

using namespace std; 

/* 
    Problem: Letter Case Permuation
    IP: a1b2
    OP: {a1b2, a1B2, A1b2, A1B2}
    Time complexity: O(2^n)
    Space complexity: O(n)
    
    Methods: tolower(), toupper() & isalpha() returns ASCII(INT) values 
*/

//  Letter Case Permuation
void solve(string ip, string op, int idx) {
    // Base condition 
    if(idx == ip.length()) {
        cout << op << endl;
        return;
    }
    
    // Not an alphabet 
    if(!isalpha(ip[idx])) {
        solve(ip, op + ip[idx], idx + 1);
        
    } else {
        // Case Change: Lower 
        solve(ip, op + char(tolower(ip[idx])), idx + 1);
        
        // Case Change: Upper 
        solve(ip, op + char(toupper(ip[idx])), idx + 1);
    }
    
}

int main()
{
    string ip = "a1b2";
    string op = "";
    
    
    solve(ip, op, 0);
    
    return 0;
}