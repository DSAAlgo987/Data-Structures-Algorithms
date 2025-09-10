#include <bits/stdc++.h>
using namespace std; 

/**
 * Problem Statement: Find first occurrence of 1s in an infinite binary sorted array.
 * 
 * Ip:
 * vector<int> arr, int key = 1;
 * 
 * op:
 * return index if found o/w -1;
 */
using v = vector<int>;

int ModifiedBS(v &arr, int start, int end, int key) { 
    int res = -1;
    while(start <= end) {
        int mid = start + (end - start) / 2;
        // Find first occurrence 
        if(key == arr[mid]) {
            res = mid; 
            end = mid - 1;
        }
        else if(key < arr[mid]) {
            end = mid - 1;
        }else {
            start = mid + 1;
        }
    }

    return res;
}

int firstOccurrenceOne(v &arr, int key) {
    int start = 0;
    int end = 1;
    // First Identify searching space 
    while(key > arr[end]) {
        start = end; 
        end *= 2;
    }

    // Then apply Binary Search 
    return ModifiedBS(arr, start, end, key);
}

int main() {
    v arr = {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1};

    cout << firstOccurrenceOne(arr, 1) << endl; // Op: 7
    
    return 0;
}