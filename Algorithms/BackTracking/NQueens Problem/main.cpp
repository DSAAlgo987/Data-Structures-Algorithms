#include <bits/stdc++.h>
using namespace std; 

/*
    PS: NQueens Problem 
    IP: n (queen No's)
    OP: Display all the possible solns
    APPROACH: Backtracking
    TC: O(n^n) = n!
    SC: O(n)
    1 Indexed based 
*/

// Aliases 
using v = vector<int>;
using vv = vector<v>;

// Global variables 
int n = 4;
vv ans;
v x(n + 1, 0);

// Bounding function 
bool valid(int k, int l) {
    
    // Check Prev queens (k-1)
    for(int i = 1; i < k; i++) {
        // Same column || same diagonal/cross diagonal
        if(x[i] == l || (i - x[i]) == (k - l) || (i + x[i]) == (k + l)) {
            return false;
        }
    }
    
    return true;
}

// NQueens Function 
void NQueens(int k) {
    // Column No's (i)
    for(int i = 1; i <= n; i++) {
        // Check safe to place or not 
        if(valid(k, i)) {
            x[k] = i;
            
            // BC 
            if(k == n) {
                ans.push_back(x);
                return;
            }
            // Recursive call for other queens 
            NQueens(k + 1);
        }
    }
}


int main()
{
    NQueens(1); // Start with 1st queen 
    
    // Display all solns 
    for(auto i: ans) {
        cout << "[";
        for(auto j: i) {
            cout << j << " ";
        }
        cout << "]," << endl;
    }
    return 0;
}