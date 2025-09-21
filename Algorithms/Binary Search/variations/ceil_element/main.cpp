#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Statement: Find Ceil of an element in a sorted array.
 * 
 * Ceil of an element = Smallest element greater than or equal than that element.
 * 
 * Ip:
 * arr, int element;
 * 
 * Op:
 * return index if found otherwise -1
 */

int BinarySearchCeil(vector<int> &arr, int ele) {
    int start = 0;
    int end = arr.size() - 1;
    int res = -1;

    while(start <= end) {
        int mid = start + (end - start) / 2;

        if(arr[mid] == ele) {
            res = mid; 
            end = mid - 1; 
        } else if (arr[mid] < ele) {
            start = mid + 1;
        } else { 
            res = mid; 
            end = mid - 1;
        }
    }

    return res;
}

int main() {
    vector<int> arr = {1, 2, 10, 11, 11, 12, 13, 14, 15}; 

    cout << BinarySearchCeil(arr, 11) << endl; // op: 3
    return 0;
}