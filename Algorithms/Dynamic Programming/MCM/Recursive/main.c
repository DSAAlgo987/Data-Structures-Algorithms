#include <bits/stdc++.h>
using namespace std;

/*
    Problem Statement: Matrix Chain Multiplication
    Recursive Approach: 
    Time complexity: O(2^n)
*/
int solve(vector<int> &A, int i, int j) {
    // Base condition 
    if(i >= j) {
        return 0;
    }
    
    int mn = INT_MAX;
    
    // find k loop scheme 
    for(int k = i; k <= j-1; k++) {
        // Calc tempAns
        int tempAns = solve(A, i, k) + solve(A, k+1, j) + A[i-1] * A[k] * A[j];
        
        // Calc ans from tempAns 
        mn = min(mn, tempAns);
    }
    
    return mn;
}

int main() {
    vector<int> arr = {40, 20, 30, 10, 30};
    
    cout << solve(arr, 1, arr.size() - 1) << endl; // op : 26000
    
    return 0;
}