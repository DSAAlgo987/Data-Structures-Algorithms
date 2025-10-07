#include <bits/stdc++.h>
using namespace std;

/**
 * PS: Frequency Sort: Sort array based on the highest frequency.
 * 
 * IP:
 * vector<int> arr;
 * 
 * OP:
 * (Dipslay)
 * vector<int> sortedArr;
 * 
 * Approach 1: MaxHeap -> nlogn
 * Approach 2: Compare Function(Comparator) -> nlogn
 * Approach 3: Bucket/Bin Sort  -> n (Optimized solution)
 */

// Aliases 
using v = vector<int>;
using vv = vector<v>;
using p = pair<int, int>;
using ump = unordered_map<int, int>; // <key, freq>

// Approach 1: MaxHeap 
void solve1(v &arr) {
    int n = arr.size();

    // Create unordered_map 
    ump  mp; 

    // Iterate over arr
    for(auto i: arr) {
        mp[i]++;
    }

    // Create mxHeap 
    priority_queue<p> mxHeap;

    // Iterate over mp 
    for(auto i: mp) {
        // key = freq -> mxHeap
        mxHeap.push({i.second, i.first});
    }

    // Iterate mxHeap 
    while(mxHeap.size() > 0) {
        int first = mxHeap.top().first;
        int second = mxHeap.top().second;

        for(int i = 1; i <= first; i++) {
            cout << second << " ";
        }
        mxHeap.pop();
    }

    cout << endl;
}

// Aproach 2: Comparator Function 
void solve2(v arr) {
    int n = arr.size();

    // Create ump freq;
    ump freq;   // <key, freq>

    // Store freq
    for(auto x: arr) {
        freq[x]++;
    }

    // Sort based freq in DESC order 
    auto lambdaDESC = [&freq] (int a, int b) {
        // If freq is same 
        if(freq[a] == freq[b]) {
            // Then sort in ASC order of elements 
            return a < b;
        }

        // If not then sort -> DESC order of Freq
        return freq[a] > freq[b];
    };

    sort(begin(arr), end(arr), lambdaDESC);

    // Iterate arr 
    for(auto x: arr) {
        cout << x << " ";
    }

    cout << endl;
}

// Approach 3: Bucket/Bin Sort 
void solve3(v &arr) {
    int n = arr.size();

    // Create freq map
    ump freq;

    // Iterate arr 
    for(auto x: arr) {
        freq[x]++;
    }

    // Create buckets 2D vector 
    vv buckets(n+1);

    // Iterate freq and store into buckets
    for(auto [element, freq]: freq) {
        buckets[freq].push_back(element);
    }

    // Iterate in backward direction to get the result 
    // i -> freq
    for(int i = n; i >= 1; i--) {
        for(auto x: buckets[i]) {
            for(int j = 1; j <= i; j++) {
                cout << x << " ";
            }
        }
    }

    cout << endl;
}


int main(){
    v arr = {1, 1, 1, 3, 2, 2, 4};

    cout << "Heap Approach" << endl;
    solve1(arr); 

    cout << "Comparator Approach" << endl;
    solve2(arr);

    cout << "Bucket/Bin Sort Approach (Optimized Soln)" << endl;
    solve3(arr);
    
    return 0;
}