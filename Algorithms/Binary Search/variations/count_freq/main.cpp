#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Statement: Find frequency of an Element in a given sort array.
 * 
 * Ip:
 * vector arr, int ele
 * 
 * Op:
 * Freq of ele
 */

int binarySearch(vector<int> &arr, int ele, bool first) {
    int start = 0;
    int end = arr.size() - 1;
    int res = -1;

    while(start <= end) {
        int mid = start + (end - start) / 2;

        if(ele == arr[mid]) {
            res = mid;
            
            if(first) {
                // Go backward direction from mid position 
                end = mid - 1;
            } else {
                // Go forward direction from mid position
                start = mid + 1;
            }
        }
        else if(ele < arr[mid]) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }

    return res;
}

int countFreq(vector<int> &arr, int ele) {
    int first = binarySearch(arr, ele, true);
    int last = binarySearch(arr, ele, false);

    if(first == -1 && last == -1) {
        return 0; // target not found
    }

    return last - first + 1;
}

int main() {
    vector<int> arr = {1, 2, 10, 10, 10, 18, 20};

    cout << countFreq(arr, 10) << endl; // op: 3
    return 0;
}