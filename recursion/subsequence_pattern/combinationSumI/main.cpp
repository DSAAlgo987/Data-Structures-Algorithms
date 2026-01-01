#include <bits/stdc++.h>
using namespace std;

/**
 * PS: Given an array of distinct integers and a target value, return all unique combinations whose sum equals the target. Each number may be used unlimited times, and combinations are considered unique based on the frequency of elements.
 * IP: int arr, int target;
 * OP: return vector of sub sequence 
 * APPROACH: Recursion + Backtracking
 * TC: O(2^t * k) 
 * SC: O(n * x) : n -> mx_depth, x -> valid combination
 */

// Aliases
using v = vector<int>;
using vv = vector<v>;

vv ans;

// Combination sum I function 
void solve(v &arr, int i, int target, v &subSeq) {
    // BC 
    if(i == arr.size()) { // To avoid out of bound error
        if(target == 0) { // To check that target is achieved
            // push subSeq to ans 
            ans.push_back(subSeq);
        }
        return;
    }

    // Element <= Target 
    if(arr[i] <= target) {
        // Possible candiation, push it to subSeq, DO 
        subSeq.push_back(arr[i]);
        // Again pick it by substracting target with current element
        solve(arr, i, target - arr[i], subSeq);
        // UNDO 
        subSeq.pop_back();
    }

    // Skip if current > target 
    solve(arr, i + 1, target, subSeq);
}

int main(){
    v arr = {2, 3, 5, 7};
    int target = 7;
    v subSeq;

    solve(arr, 0, target, subSeq);

    // Display Combinations 
    for(auto i: ans) {
        for(auto j: i) 
            cout << j << " ";
        cout << endl;
    }
    
    return 0;
}