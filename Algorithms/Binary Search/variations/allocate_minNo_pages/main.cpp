#include <bits/stdc++.h>
using namespace std;

/*
    PS: Allocate Min no of Pages.
    
    Ip:
    vector<int> arr, int k;
    
    Op:
    int minimizedPage;
*/

using v = vector<int>;

// Time complexity : O(n)
bool isValid(v &arr, int n, int k, int mx) {
    int students = 1;
    int sum = 0;
    
    for(int i = 0; i < n; i++) {
        sum += arr[i];
        
        if(sum > mx) {
            students++;
            sum = arr[i];
        }
        
        if(students > k) {
            return false;
        }
    }
    
    return true;
}

// Time complexity: n + nlgn
int allocatePages(v &arr, int k) {
    int n = arr.size();
    
    // Base case 
    if(n < k) {
        return -1;
    }
    
    int start = *max_element(arr.begin(), arr.end()); // Returns iterator (Max element in arr)
    int end = accumulate(arr.begin(), arr.end(), 0); // Sum of all elements 
    int res = -1;
    
    while(start <= end) { 
        int mid = start + (end - start) / 2;
        
        if(isValid(arr, n, k, mid) == true) {
            res = mid;
            end = mid - 1;
        }
        else {
            start = mid + 1;
        }
    }
    
    return res;
}

int main()
{
    v arr = {10, 20, 30, 40};
    int k = 2; // No of students
    
    cout << allocatePages(arr, k) << endl; // Op: 60

    return 0;
}