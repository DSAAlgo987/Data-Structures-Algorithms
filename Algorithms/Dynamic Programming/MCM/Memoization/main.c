#include <bits/stdc++.h>
using namespace std;

/*
    Problem Statement: Matrix Chain Multiplication
    Memoize(Top down) Approach: 
    Time complexity: O(2^n)
*/

vector<vector<int>> t; // Global declaration 

int solve(vector<int> &A, int i, int j) {
    // Base condition 
    if(i >= j) {
        return 0;
    }
    
    // Present in t ?
    if(t[i][j] != -1) {
        return t[i][j];
    }
    
    int mn = INT_MAX;
    
    // find k loop scheme 
    for(int k = i; k <= j-1; k++) {
        // Calc tempAns
        int tempAns = solve(A, i, k) + solve(A, k+1, j) + A[i-1] * A[k] * A[j];
        
        // Calc ans from tempAns 
        mn = min(mn, tempAns);
    }
    
    return t[i][j] = mn;
}

int main() {
    vector<int> arr = {40, 20, 30, 10, 30};
    int n = arr.size();
    
    t.assign(n + 1, vector<int>(n + 1, -1)); // Initialization as -1 
    
    cout << solve(arr, 1, n - 1) << endl; // op : 26000
    
    return 0;
}