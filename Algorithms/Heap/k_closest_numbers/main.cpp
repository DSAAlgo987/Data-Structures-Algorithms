#include <bits/stdc++.h>
using namespace std;

/**
 * PS: Implement K Closest Numbers.
 * 
 * Ip:
 * vector<int> arr, int k;
 * 
 * Op:
 * Display K Closest Numbers;
 * 
 * Approach 1: Sorting -> nlgn
 * Approach 2: mxHeap -> nlgk
 */

using v = vector<int>;
using p = pair<int, int>;

// Time complexity: nlogk
void solve(v &arr, int k, int x) {
    int n = arr.size();

    // MaxHeap
    priority_queue<p> mxHeap;

    // Iterate all over array elements 
    for(int i = 0; i < n; i++) {
        // Push element with abs differnce with x;
        mxHeap.push({abs(arr[i] - x), arr[i]});

        // If size > k then remove top element from mxHeap 
        if(mxHeap.size() > k) {
            mxHeap.pop();
        }
    }

    // Display Closest Numbers present in mxHeap 
    while(mxHeap.size() > 0) {
        cout << mxHeap.top().second << " ";
        mxHeap.pop();
    }
}

int main(){
    v arr = {5, 6, 7, 8, 9};
    int k = 3;
    int x = 7;

    solve(arr, k, x); // Op: 8, 7, 6
    
    return 0;
}