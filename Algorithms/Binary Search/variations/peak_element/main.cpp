#include <bits/stdc++.h>
using namespace std;

/**
 * PS: Peak element is an element which is greater than it's neighbours
 * 
 * Ip: 
 * vector<int> arr; 
 * 
 * op: 
 * return idx of Peak element
 * 
 * Category: Binary Search on Answer
 */

// Time Complexity: O(logN)
int peakElement(vector<int> &arr) { 
    int n = arr.size();

    if(n == 1) 
        return 0;
        
    int start = 0;
    int end = n - 1; 

    while(start <= end) { 
        int mid = start + (end - start) / 2;
        if(mid > 0 && mid < n - 1) { 
            if(arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1])
                return mid; 
            else if(arr[mid + 1] > arr[mid]) 
                start = mid + 1; 
            else 
                end = mid - 1;
        }
        else if(mid == 0) {
            if(arr[0] > arr[1]) 
                return 0; 
            else 
                return 1; 
        }
        else {
            if(arr[n-1] > arr[n-2]) 
                return n - 1; 
            else 
                return n - 2; 
        }
    }
    return -1;
}

int main(){
    vector<int> arr = {1, 2, 3, 1};

    cout << peakElement(arr) << endl;
    
    return 0;
}