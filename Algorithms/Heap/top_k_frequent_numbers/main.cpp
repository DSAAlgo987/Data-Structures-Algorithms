#include <bits/stdc++.h>
using namespace std;

/**
 * PS: Top K Frequent Numbers/Elements.
 * 
 * IP: 
 * vector<int> arr, int k;
 * 
 * OP:
 * Return TopKNumbers;
 * 
 * Approach 1: Map + Sorting
 * Time complexity: n + nlogn
 * 
 * Approach 2: Map + minHeap 
 * Time complexity: n + nlogk
 */

// Aliases
using v = vector<int>;
using p = pair<int, int>;


// Brute Force: O(nlgn)

class Solution {
public:
    using v = vector<int>;
    using p = pair<int, int>; // <freq, #>
    using umap = unordered_map<int, int>; // < #, freq>

    vector<int> topKFrequent(vector<int>& nums, int k) {
          umap m; 

          for(auto x: nums) m[x]++;

          vector<p> vp; 

          // convert map to vv 
          for(auto [first, second]: m) vp.push_back({second, first});

          // sort based on freq (DESC) using greater<>() comparator function 
          sort(vp.begin(), vp.end(), greater<p>());

          // compute the final ans 
          v ans; 
          for(int  i = 0 ; i < k; i++) ans.push_back(vp[i].second);

          return ans; 
    }
};

void printv(v &arr) {
    for(auto i: arr) {
        cout << i << " ";
    }
    cout << endl;
}

// Time Complexity: nlogk
v topKFreq(v &arr, int k) {
    int n = arr.size();
    unordered_map<int, int> mp;

    // Store number with theiry freq
    for(int i = 0; i < n; i++) {
        mp[arr[i]]++;
    }

    // Create minHeap 
    priority_queue<p, vector<p>, greater<p>> minHeap;

    // Iterate map 
    for(auto i: mp) {
        // push pair -> minHeap 
        // Here key = frequency in minHeap
        minHeap.push({i.second, i.first});

        // size > k then pop from minHeap
        if(minHeap.size() > k) {
            minHeap.pop();
        }
    }

    // Create ans vector
    v ans;

    // Iterate minHeap 
    while(minHeap.size() > 0) {
        ans.push_back(minHeap.top().second);
        minHeap.pop();
    }

    return ans;
}

int main(){
    v arr = {1, 1, 1, 3, 3, 2, 2, 4, 5, 5};
    int k = 2;

    v ans = topKFreq(arr, k);

    printv(ans);
    
    return 0;
}