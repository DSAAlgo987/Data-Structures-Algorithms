#include <bits/stdc++.h>
using namespace std;

/**
 * PS: Implement Sort A K Sorted Array. (ASCENDING) 
 * 
 * Ip:
 * vector<int> arr, int k;
 * 
 * Op:
 * Display Sorted Array.
 * 
 * Approach 1: Sorting -> nlogn
 * 
 * Approach 2: MinHeap -> nlogk
 *  Why minHeap bcoz we have to sort array in ASC order.
 */

using v = vector<int>;

// Time Complexity: nlogk
void solve(v &arr, int k) {
    int n = arr.size();
    v sorted;

    // MinHeap 
    priority_queue<int, v, greater<int>> minHeap;

    // Iterate all over array 
    for(int i = 0; i < n; i++) {
        // Insert element -> minHeap 
        minHeap.push(arr[i]);

        // If size > k then store top element -> sorted vector and remove it from minHeap
        if(minHeap.size() > k) {
            sorted.push_back(minHeap.top());
            minHeap.pop();
        }
    }

    // Remaining elements present in minHeap push -> sorted vector
    while(minHeap.size() > 0) {
        sorted.push_back(minHeap.top());
        minHeap.pop();
    }

    // Display sorted vector 
    for(auto i: sorted) {
        cout << i << " ";
    }
    cout << endl;
}

int main(){
    v arr = {6, 5, 3, 2, 8, 10, 9};
    int k = 3;

    solve(arr, k); 
    
    return 0;
}