#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Statement: Find no of rotation is done in sorted array.
 * 
 * Ip:
 * vector<int> sortedArr;
 * 
 * Op:
 * # of rotation 
 */
int solve(vector<int> &arr) {
    int start = 0;
    int end = arr.size() - 1;
    int N = arr.size();
    int noOfRotation;

    while(start <= end) {
        // If array already sorted 
        if(arr[start] <= arr[end]) {
            return start;
        }
        int mid = start + (end - start) / 2;
        int next = (mid + 1) % N;
        int prev = (mid + N - 1) % N;

        // Check if mid is minimum
        if(arr[mid] <= arr[prev] && arr[mid] <= arr[next]) {
            return mid; // index of min = rotations
        }

        // Decide side
        if(arr[start] <= arr[mid]) {
            start = mid + 1; // left sorted, go right
        } else {
            end = mid - 1; // right sorted, go left
        }
    }

    return 0;
}

int main() {
    vector<int> arr = {5, 1, 2, 3, 4};

    cout << solve(arr) << endl; // OP: 1

    return 0;
}