#include <bits/stdc++.h>
using namespace std;

/**
 * PS: Connect Ropes (Minimize cost);
 * 
 * IP: vector<int> arr
 * OP: MinCost (int)
 * APPROACH: MinHeap
 */

// Aliases
using v = vector<int>;

// Time complexity: O(nlogn)
int connectRopes(v &arr) {
    priority_queue<int, v, greater<int>> minHeap;

    // Iterate over arr and push into minHeap
    for(auto ele: arr) {
        minHeap.push(ele);
    }

    // Iterate over minHeap if size >= 2
    int cost = 0;
    while(minHeap.size() >= 2) {
        int first = minHeap.top();
        minHeap.pop();

        int second = minHeap.top();
        minHeap.pop();

        cost += first + second;

        minHeap.push(first + second);
    }

    return cost;
}

int main(){
    v arr = {1, 2, 3, 4, 5};

    cout << connectRopes(arr) << endl; // OP: 33;
    
    return 0;
}