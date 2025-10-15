#include <bits/stdc++.h>
using namespace std;

/**
 * PS: Sum of elements b/w K1 and K2 Smallest.
 * 
 * IP: vector<int> arr, int k1, k2;
 * OP: Sum between those k's
 * 
 * APROACH 1: Sorting -> nlogn
 * APROACH 2: MxHeap -> nlogk (Optimized)
 * 
 * There can be many variations like k1 smallest and k2 smallest can be asked.
 */

// Aliases 
using v = vector<int>;

// Time complexity: nlogk
int kSmallest(v &arr, int k) {
    // Create mxHeap
    priority_queue<int> mxHeap;

    // Iterate over arr and pushed it into mxHeap
    for(auto ele: arr) {
        mxHeap.push(ele);

        // if size > k 
        if(mxHeap.size() > k) {
            mxHeap.pop();
        }
    }

    // Return top element 
    return mxHeap.top();
}

// Time complexity: O(nlogk)
int sumOfElements(v &arr, int k1, int k2) {
    int first = kSmallest(arr, k1);     // nlogk
    int second = kSmallest(arr, k2);    // nlogk
    int sum = 0;

    // Iterate over and identify those elements which are b/w those two k's
    for(auto ele: arr) {                // n
        if(ele > first && ele < second) {
            sum += ele;
        }
    }

    return sum;
}

int main(){
    v arr = {1, 3, 12, 5, 15, 11};
    int k1 = 3, k2 = 6;

    cout << sumOfElements(arr , k1, k2) << endl; // OP: 23
    
    return 0;
}