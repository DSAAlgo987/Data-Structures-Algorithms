#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Statement: Binary search on DESC order.
 * Time complexity: O(log N)
 */
int BinarySearch(vector<int> &arr, int ele) {
    int start = 0;
    int end = arr.size() - 1;

    while(start <= end) {
        int mid = start + (end - start)/2;

        if(ele == arr[mid]) {
            return mid;
        } else if(ele < arr[mid]) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    return -1;
}

int main() {
    vector<int> arr = {9, 8, 4, 3, 2, 1};

    cout << BinarySearch(arr, 1) << endl; // op: 5

    cout << BinarySearch(arr, 19) << endl; // op: -1

    return 0;
}