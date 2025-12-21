#include <bits/stdc++.h>
#include <stdio.h>

using namespace std; 

/* 
    Problem: Permutation with case Change
    IP: ab
    OP: {ab, aB, Ab, AB}
    Time complexity: O(2^n)
    Space complexity: O(n)
    
    Methods: tolower(), toupper() returns ASCII(INT) values 
*/

// Permuation with spaces 
void solve(string ip, string op, int idx) {
    // Base condition 
    if(idx == ip.length()) {
        cout << op << endl;
        return;
    }
    
    // Case Change: Lower 
    solve(ip, op + char(tolower(ip[idx])), idx + 1);
    
    // Case Change: Upper 
    solve(ip, op + char(toupper(ip[idx])), idx + 1);
}

int main()
{
    string ip = "ab";
    string op = "";
    
    
    solve(ip, op, 0);
    
    return 0;
}