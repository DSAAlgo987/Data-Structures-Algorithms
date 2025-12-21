#include <bits/stdc++.h>
#include <stdio.h>

using namespace std; 

/* 
    Problem: Permutation with spaces 
    IP: ABC 
    OP: {A_B_C, A_BC, AB_C, ABC}
    Time complexity: O(2^n)
    Space complexity: O(n)
*/

// Permuation with spaces 
void solve(string ip, string op, int idx) {
    // Base condition 
    if(idx == ip.length()) {
        cout << op << endl;
        return;
    }
    
    // Exclude '_'
    solve(ip, op + ip[idx], idx + 1);
    
    // Include '_'
    op.push_back('_');
    solve(ip,op + ip[idx], idx + 1);
}

int main()
{
    string ip = "ABC";
    string op = "";
    
    op.push_back(ip[0]);
    
    solve(ip, op, 1);
    
    return 0;
}