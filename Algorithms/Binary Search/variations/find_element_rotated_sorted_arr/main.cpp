#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Statement: Find an element in rotated sorted array.
 * 
 * Ip:
 * vector<int> arr;
 * 
 * op:
 * return index;
 * 
 * Cosntraints:
 *  1 <= nums.length <= 5000
    -104 <= nums[i] <= 104
    All values of nums are unique.
    nums is an ascending array that is possibly rotated.
    -104 <= target <= 104
 */

// Time complexity: logN
int minRotation(vector<int> &arr) {
    int N = arr.size();
    int start = 0;
    int end = N - 1;


    while(start <= end) {
        int mid = start + (end - start) / 2; 
        int next = (mid + 1) % N;   
        int prev = (mid + N - 1) % N;

        // If array is already sorted
        if(arr[start] <= arr[end]) {
            return start;
        }

        // Min element 
        if(arr[mid] <= arr[prev] && arr[mid] <= arr[next]) {
            return mid; // No of rotation = mid element index 
        }
        // Decide side 
        else if(arr[start] <= arr[mid]) {
            start = mid + 1;  // left sorted, move towards the right unsorted side 
        } else {
            end = mid - 1; // right sorted, move towards the left unsorted side 
        }
    }

    return 0; // min no of rotation 
}   

// Time complexity: logN
int BinarySearch(vector<int> &arr, int start, int end, int ele) { 
    while(start <= end) { 
        int mid = start + (end - start) / 2;

        if(ele == arr[mid]) {
            return mid;
        } else if(ele < arr[mid]) {
            end = mid - 1; 
        } else { 
            start = mid + 1;
        }
    }

    return -1; // Invalid search
}

// Time complexity: O(logn)
int solve(vector<int> &arr, int ele) {
    
    int index = minRotation(arr);

    int left = BinarySearch(arr, 0 , index - 1, ele);

    if(left != -1) {
        return left;
    } 

    return BinarySearch(arr, index , arr.size() - 1, ele);
}

int main(){
    vector<int> arr = {4,5,6,7,0,1,2};

    cout << solve(arr, 0) << endl;

   
    return 0;
}