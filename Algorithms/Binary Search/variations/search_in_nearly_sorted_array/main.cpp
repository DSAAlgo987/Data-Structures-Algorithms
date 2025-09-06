#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Statement: Search an element in nearly sorted array.
 * Given a sorted integer array arr[] consisting of distinct elements, where some elements of the array     are moved to either of the adjacent positions, i.e. arr[i] may be present at arr[i-1] or arr[i+1].
    Given an integer target.  
    You have to return the index ( 0-based ) of the target in the array. If target is not present return -1.
 */

// Time Complexity: O(logN)
int modifideBinarySearch(vector<int> &arr, int ele) {
    int start = 0;
    int end = arr.size() - 1;

    while(start <= end) {
        // Cacl mid 
        int mid = start + (end - start) / 2;

        // ith mid matches with ele 
        if(ele == arr[mid]) { 
            return mid; 
        }
        // i+1th mid matches with ele & handle SF
        else if(mid + 1 <= end && ele == arr[mid + 1]) {
            return mid + 1;
        }
        // i-1th mid matches with ele & handle SF 
        else if(mid - 1 >= start && ele == arr[mid - 1]) {
            return mid - 1;
        }
        else if(ele < arr[mid]) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }

    return -1; // Invalid Search
}

int main(){
    vector<int> arr = {10, 3, 40, 20, 50, 80, 70};

    cout << modifideBinarySearch(arr, 40) << endl; // op: 2
    cout << modifideBinarySearch(arr, 90) << endl; // op: -1
    cout << modifideBinarySearch(arr, 10) << endl; // op: 0
    
    return 0;
}