#include <bits/stdc++.h>
using namespace std;

/**
 * PS: K-Closest Points to origin.
 * 
 * IP: arr[n][2], int k;
 * 
 * OP: Return K Closest Points.
 * 
 * FORMULA: x^2 + y^2;
 */

// Aliases:
using p = pair<int,int>;
using pp = pair<int, p>;
using v = vector<int>;
using vv = vector<v>;

void print(vv &arr) {
    for(auto p: arr) {
        for(auto i: p) {
            cout << i << " ";
        }
        cout << endl;
    }

    cout << endl;
}

// Time complexity: O(nlogk)
vv kClosest(vv &arr, int k) {
    int n = arr.size();
    // Create mxHeap (distance, point)
    priority_queue<pp> mxHeap;

    // Iterate 2d Arr 
    for(int i = 0; i < n; i++) {
        mxHeap.push({arr[i][0] * arr[i][0] + arr[i][1] * arr[i][1], {arr[i][0],arr[i][1]}});

        // If greater than size k
        if(mxHeap.size() > k) {
            // Pop from mxHeap 
            mxHeap.pop();
        }
    }

    // Return 2d ans vector containing k closest points 
    vv closests;

    // Iterate mxHeap 
    while(!mxHeap.empty()) {
        p points = mxHeap.top().second;
        closests.push_back({points.first, points.second});
        mxHeap.pop();
    }

    // Inorder to maintain ans in ascending order use reverse()
    reverse(closests.begin(), closests.end());

    return closests;
}


int main(){
    vv arr = {
        {1, 3},
        {-2, 2},
        {5, 8},
        {0, 1}
    };
    int k = 2;

    vv closests = kClosest(arr, k);

    print(closests); // OP: {-2, 2}, {0, 1}
    
    return 0;
}