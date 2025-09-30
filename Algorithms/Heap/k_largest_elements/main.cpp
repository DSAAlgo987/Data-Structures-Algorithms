#include <bits/stdc++.h>
using namespace std;

/**
 * PS: Implement K Largest Elements.
 * 
 * Ip: 
 * vector<int> arr, int k;
 * 
 * Op:
 * Display all largest elements of size k.
 * 
 * Approach 1: Sorting -> nlogn
 *  i. First sort the vector.
 *  ii. Display from k to size -1;
 * 
 * Approach 2: MinHeap -> nlogk
 */

using v = vector<int>;

void solve(v &arr, int k) {
    int n = arr.size(); 

    // MinHeap 
    priority_queue<int, v, greater<int>> minHeap; 

    // Iterate over arr 
    for(int i = 0; i < n; i++) {
        // Insert element -> mnHeap
        minHeap.push(arr[i]);

        // Size > k then pop from mnHeap
        if(minHeap.size() > k) {
            // Remove min element from heap 
            minHeap.pop();
        }

    }

    // Display all the elements present in minHeap 
    while(minHeap.size() > 0) {
        cout << minHeap.top() << " ";
        minHeap.pop();
    }
}

int main(){
    v arr = {5, 3, 2, 1, 7, 8, 9};
    int k = 3;

    solve(arr, k);  // OP: 7 8 9
    
    return 0;
}