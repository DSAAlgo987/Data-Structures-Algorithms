#include <bits/stdc++.h>
using namespace std;

/**
 * PS: Given an array print all the sum of the subset generated from it, in the increasing order.
 * IP: vector arr, int N;
 * OP: sum of vector: vector sumOfVector
 * TC: O(2^n)
 * SC: O(n) 
 */

// Aliases
using v = vector<int>;

v ans;

// Sum Of Subset Function
void solve(v &arr, int sum, int i, int N) {
    // BC
    if(i == N) {
        ans.push_back(sum);
        return;
    }

    // Exclude 
    solve(arr, sum, i+1, N);

    // Include 
    solve(arr, sum + arr[i], i+1, N);
}

int main(){
    v arr = {5, 2, 1};
    int N = arr.size();

    solve(arr, 0, 0, N);

    // Display sum of subsets 
    for(auto i: ans) {
        cout << i << " ";
    }

    return 0;
}