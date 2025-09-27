#include <bits/stdc++.h>
using namespace std;

/**
 * PS: Search an element/key in bitonic array.
 * 
 * Ip: 
 * vector<int> arr, int element/key;
 * 
 * Op:
 * return index if found o/w -1;
 */

using v = vector<int>;

// Time complexity: logn
int findPeak(v &arr) { 
    int n = arr.size();

    // Base case
    if(n <= 1) { 
        return 0;
    }

    int start = 0; 
    int end = n - 1; 

    while(start <= end) {
        int mid = start + (end - start) / 2; 

        if(mid > 0 && mid < n - 1) { 
            if(arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1]) { 
                return mid; 
            }
            else if(arr[mid+1] > arr[mid]) { 
                start = mid + 1;
            }
            else { 
                end = mid - 1; 
            }
        }
        else if(mid == 0) { 
            if(arr[mid] > arr[1]) {
                return mid;
            }
            else { 
                return 1; 
            }
        }
        else { 
            if(arr[n-1] > arr[n-2]) { 
                return n-1;
            } 
            else { 
                return n-2;
            }
        }
    }

    return -1; // There is no peak element 
}

// Time complexity: logN
int BinarySearch(v &arr, int start, int end, int ele, bool asc) { 

    while(start <= end) {
        int mid = start + (end - start) / 2; 

        if(arr[mid] == ele) {
            return mid; 
        }
        else if(arr[mid] < ele) { 
            if(asc) {
                start = mid + 1;
            } 
            else { 
                end = mid - 1; 
            }
        }
        else { 
            if(asc) { 
                end = mid - 1; 
            } else { 
                start = mid + 1; 
            }
        }
    }

    return -1; // Invalid search 
}

// Time complexity: LogN
int SearchInBitonicArray(v &arr, int ele) { 
    // Step1: Identify Peak element index 
    int idx = findPeak(arr);

    // Step2: Then apply binary search
    int a = BinarySearch(arr, 0, idx-1, ele, true);
    int b = BinarySearch(arr, idx, arr.size() - 1, ele, false);

    if(a != -1) {
        return a;
    }
    
    return b; 
}

int main(){
    v arr = {5, 6, 7, 10, 3, 2, 1};
    int ele = 2;

    cout << SearchInBitonicArray(arr, ele) << endl; // OP: 5
    cout << SearchInBitonicArray(arr, 200) << endl; // OP: -1 
    
    return 0;
}