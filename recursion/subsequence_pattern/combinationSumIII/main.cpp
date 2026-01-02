#include <bits/stdc++.h>
using namespace std;

/**
 * PS: Combination Sum III - Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.
 * IP: int k, int n
 * OP: vector of vector combinations
 * TC: O(2^9 * K) “Because the input size is fixed (1 to 9), the exponential part is bounded.” == O(K)
 * SC: O(k * x)
 * APPROACH: Recursion + Backtracking
 */

// Aliase
using v = vector<int>;
using vv = vector<v>;

vv ans;

// Combination Sum III
void solve(v &arr, int i, int n, int k, v &subSeq) {
    // BC 
    if(i == arr.size()) {
        if(n == 0 && k == 0) {
            ans.push_back(subSeq);
        }
        return;
    }

    // BT condition 
    if(n != 0 && k == 0) return;

    // Include condition 
    if(arr[i] <= n) {
        // Possible candidate 
        subSeq.push_back(arr[i]);
        solve(arr, i + 1, n - arr[i], k - 1, subSeq);
        subSeq.pop_back();
    }

    // skip current element 
    solve(arr, i + 1, n , k, subSeq);
}

int main(){
    v arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = 9;
    int k = 3;
    v subSeq;

    solve(arr, 0, n, k, subSeq);

    // Display ans arr
    for(auto i: ans) {
        for(auto j: i) {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}