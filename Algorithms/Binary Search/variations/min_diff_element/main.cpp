#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Statement: Min sum difference of an element in a sorted array.
 * 
 * Ip: 
 * vector<int> arr, int key;
 * 
 * Op: 
 * return key containing min sum;
 */

using v = vector<int>;

int minSumDifference(v &arr, int key) {
    int start = 0; 
    int end = arr.size() - 1; 

    while(start <= end) { 
        int mid = start + (end - start) / 2;

        // If key is present 
        if(key == arr[mid]) {
            return key;
        }
        else if(key < arr[mid]) { 
            end = mid - 1; 
        }
        else { 
            start = mid + 1; 
        }
    }

    return (abs(arr[start] - key) < abs(arr[end] - key)) ? arr[start]: arr[end];
}

int main(){
    v arr = {1, 3, 5, 11, 15, 18}; 

    cout << minSumDifference(arr, 12) << endl; // Op: 11
    cout << minSumDifference(arr, 11) << endl; // Op: 11
    return 0;
}