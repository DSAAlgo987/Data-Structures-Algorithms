#include <bits/stdc++.h>
using namespace std; 

/**
 * PS:  Given an array nums and an integer k.Return the number of non-empty subsequences of nums such that the sum of all elements in the subsequence is equal to k.
 * 
 * IP: int arr , int k;
 * OP: # subseq's sum == k
 * Methods: Back(), front() : O(1)
 */

//Aliase
using v = vector<int>;

int cnt = 0;

// # all subseq == k
void solve(int n, v &arr, int k,int sum) {
    // Base condition 
    if(n == 0) {
        // Check 
        if(sum == k) {
            cnt++;
        }
        return;
    }

    // Pruning
    if(sum > k) {
        return;
    }

    // Exclude 
    solve(n - 1, arr, k, sum);
    
    // include 
    solve(n - 1, arr, k, sum + arr[n-1]);
}

int main() {
    v arr = {3, 4, 6, 7};
    int k = 10;
    solve(arr.size(), arr, k, 0);

    cout << "Total Count: " << cnt << endl;
    return 0;
}