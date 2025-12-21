#include <bits/stdc++.h>
#include <iostream>

using namespace std; 

/*
    PS: Print N Binary no where 1's >= 0's in all it's prefixes
    IP: n = 3 
    OP: 111,110,101,100
    TC: O(2^n)
    SC: n 
*/

void solve(int n, int z, int o, string op) {
    // Base condition 
    if(n == 0) {
        cout << op << endl;
        return;
    }
    
    // Single choice: Add 1 
    if(z == o) {
        // Add 1
        solve(n-1, z, o + 1, op + '1');
    } 
    // Double Choice: Add 1/0
    else {
        // Add 1 
        solve(n-1, z, o + 1, op + '1');
        
        // Add 0 
        solve(n-1, z + 1, o, op + '0');
    }
}


int main()
{
    solve(3, 0, 0, "");

    return 0;
}