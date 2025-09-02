#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Statement: Find first and last position/occurence of an Element in a sorted array.
 * 
 * Ip:
 * vector arr, int ele
 * 
 * Op:
 * return vector pos[first, last]
 */
int binarySearch(vector<int> &arr, int ele, bool first) {
    int start = 0;
    int end = arr.size() - 1;
    int res = -1;

    while(start <= end) {
        int mid = start + (end - start) / 2;

        if(ele == arr[mid]) {
            res = mid;
            
            if(first) {
                // Go backward direction from mid position 
                end = mid - 1;
            } else {
                // Go forward direction from mid position
                start = mid + 1;
            }
        }
        else if(ele < arr[mid]) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }

    return res;
}

vector<int> findFirstAndLastPosition(vector<int> &arr, int ele) {
    int first = binarySearch(arr, ele, true);
    int last = binarySearch(arr, ele, false);

    vector<int> ans;
    ans.push_back(first);
    ans.push_back(last);

    return ans;
}

void displayVec(vector<int> &v) {
    for(auto i: v) {
        cout << i << " ";
    }
    cout << endl;
}
int main() {
    vector<int> arr = {1, 2, 10, 10, 10, 18, 20};

    vector<int> ans = findFirstAndLastPosition(arr, 10); // op: [2, 4]
    
    displayVec(ans);

    
    return 0;
}