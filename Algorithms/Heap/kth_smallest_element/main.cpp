#include <bits/stdc++.h>
using namespace std;

/**
 * PS: Implement Kth Smallest Element.
 * 
 * Ip:
 * vector<int> arr, int k;
 * 
 * Op:
 * Display Kth Smallest
 * 
 * Approach 1: Sorting
 *  This approach will take nlogn time complexity.
 * 
 * Approach 2: Heap (optimized)
 *  This approach will take nlogk time complexity.
 */

using v = vector<int>;

// Time complexity: nlogk
int solve(v &arr, int k) {
    int n = arr.size();
    priority_queue<int> mxHeap;

    // Iterate all over arr  
    for(int i = 0; i < n; i++) {
        // Insert element -> mxHeap
        mxHeap.push(arr[i]);

        // If size greaater than given size then pop from mxHeap
        if(mxHeap.size() > k) {
            mxHeap.pop();
        }
    }

    // Return final answer 
    return mxHeap.top();
}

int main(){
    v arr = {4, 1, 2,5, 6, 7, 9};
    int k = 3; 

    cout << solve(arr, k) << endl; // Op: 4
    
    return 0;
}