#include <bits/stdc++.h>
using namespace std;

/**
 * PS: Given an integer array nums, which can have duplicate entries, provide the power set. Duplicate subsets cannot exist in the solution set. Return the answer in any sequence.
 * IP: vector arr;
 * OP: vector of vector subsets
 * TC: O(2^n)
 * SC: O(n)
 * BF APPROACH: Recursion + Unordered 
 * Better APPROACH: Recursion + Backtracking
 */

// Aliases
using v = vector<int>;
using vv = vector<v>;

vv ans;

// Print all unique subsets: sumofsubset II
void solve(v &arr, int idx, v &subseq) {
    // Push empty set to the ans 
    ans.push_back(subseq);


    // SKIP: All duplicates
    for(int i = idx; i < arr.size(); i++) {
        // Check duplicacy & handle overlfow  
        if(i != idx && arr[i] == arr[i-1]) continue;

        // if no duplicacy then push element to subseq
        subseq.push_back(arr[i]);

        // Again call solve to find other subseq 
        solve(arr, i + 1, subseq);

        // when recursion is reached the leaf node 
        // then start removing element from subseq
        subseq.pop_back();
    }
}

int main(){
    v arr = {2, 1, 2};
    v subseq;

    // Step 1: Sort the arr 
    sort(arr.begin(), arr.end());

    // Step 2: Generate all unique subsets
    solve(arr, 0, subseq);

    // Step 3: Print subsets
    for (auto &subset : ans) {
        cout << "{ ";
        for (int x : subset)
            cout << x << " ";
        cout << "}" << endl;
    }

    return 0;
}