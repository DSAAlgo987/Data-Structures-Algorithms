#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Identify Longest Inreasing Subsequence 
 * 
 * Ip:
 * array nums;
 * 
 * op:
 * length of LIS 
 */

// Tabular approach: O(n * m)
int LCS(vector<int> &x, vector<int> &y, int m, int n) {
    vector<vector<int>> t(m + 1,vector<int>(n + 1, 0)); // Initialization with 0s

    // Start filling, remaining cells(sub-problems): i -> m, j -> n
    for(int i = 1; i < m + 1; i ++) {
        for(int j = 1; j < n + 1; j++) {
            // Matching 
            if(x[i-1] == y[j-1]) {
                t[i][j] = 1 + t[i-1][j-1];
            } else {
                t[i][j] = max(
                    t[i][j-1],
                    t[i-1][j]
                );
            }
        }
    }

    return t[m][n];
}


// O(n)
vector<int> removeDuplicates(vector<int> &arr) {
    // Base case 
    if(arr.size() <= 1) {
        return arr;
    }
    // start from 1st element 
    int j = 0;
    for(int i = 1; i < arr.size(); i++) {
        if(arr[i] != arr[j]){
            j++;
            arr[j] = arr[i];
        }
    }
    // Shrink arr size;
    arr.resize(j + 1);

    // Return array after removing duplicates
    return arr;
}

// Time complexity: O(m * n)
int lengthOfLIS(vector<int> &nums) {
    // b vector is hidden: it is sorted and not duplicate vector of nums(a)
    vector<int> b = nums;
    // Sort b vector 
    sort(b.begin(), b.end()); // nlogn
    b = removeDuplicates(b);

    return LCS(nums, b, nums.size(), b.size());
}



int main(){
    vector<int> arr = {10,9,2,5,3,7,101,18};

    cout << lengthOfLIS(arr) << endl;
    
    return 0;
}