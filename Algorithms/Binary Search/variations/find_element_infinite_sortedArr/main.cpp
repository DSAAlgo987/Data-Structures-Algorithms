#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Statement: Find position of an element in an infinite sorted array. 
 * 
 * Ip: 
 * vector<int> arr, int key 
 * 
 * Op: 
 * return index if found o/w -1 
 */

int BinarySearch(vector<int> &arr, int start, int end, int key) {
    while(start <= end) { 
        int mid = start + (end - start) / 2; 
        
        if(key == arr[mid]) {
            return mid; 
        }
        else if(key < arr[mid]) {
            end = mid - 1;
        } else { 
            start = mid + 1;
        }   
    }
    return -1; 
}

int FindELementInfiniteArr(vector<int> &arr, int key) {
    int start = 0;
    int end = 1; 
    
    // First identify where end and start will point 
    while(key > arr[end]) {
        start = end; 
        end *= 2; 
    }    
    
    // Now apply binary search 
    return BinarySearch(arr, start, end, key);
}
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    
    cout << FindELementInfiniteArr(arr, 7) << endl; // op: 6
    return 0;
}