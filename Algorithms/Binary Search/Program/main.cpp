#include <bits/stdc++.h>
using namespace std;

/**
 * Binary Search: It requires the to be sorted either in ASC or DESC order.
 * Time complexity: O(logN)
 */
int BinarySearch(vector<int> &arr, int ele) {
    int start = 0;
    int end = arr.size();
    
    while(start <= end) {
        int mid = start + (end - start) / 2;

        if(ele == arr[mid]) {
            return mid;
        }
        else if(ele < arr[mid]) {
            end = mid - 1;
        }
        else {
            start = mid + 1;
        }
    }

    return -1;
}

int main() { 
    vector<int> arr = {1, 2, 3, 4, 5, 9, 10, 12};

    cout << BinarySearch(arr, 10) << endl; // op: 6

    cout << BinarySearch(arr, 100) << endl; // op: -1
    return 0;
}