#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Statement: Order Agnostic Search. 
 * Array is sorted but in which way it is not mentioned.
 * 
 * Ip:
 * vector arr, int ele 
 * 
 * Op:
 * return index if element found else -1 
 */

int BinarySearch(vector<int> &arr, int ele, bool asc) {
    int start = 0;
    int end = arr.size() - 1;

    while(start <= end) {
        int mid = start + (end - start) / 2;

        if(ele == arr[mid]) {
            return mid;
        }
        else if(ele < arr[mid]) {
            if(asc) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        else { 
            if(asc) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
    }

    return -1;
}

int OrderAgnosticSearch(vector<int> &arr, int ele) {
    bool asc = false; 

    // Size 1 
    if(arr[0] == ele) {
        return 0;
    }

    // More than 1 element, Then identify array is sorted in which fashion 
    if(arr[0] < arr[1]) {
        asc = true;
    } else {
        asc = false;
    }

    return BinarySearch(arr, ele, asc);
}

int main() {
    vector<int> arr = {9, 8, 7, 6};

    cout << OrderAgnosticSearch(arr, 8) << endl; // Op: 1

    cout << OrderAgnosticSearch(arr, 100) << endl; // Op: -1
    return 0;
}