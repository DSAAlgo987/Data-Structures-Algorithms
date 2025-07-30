#include <bits/stdc++.h>
using namespace std;

// Step1 : caluclate max bitwise AND 
// Step2: identify longest subarray eqal max and 

// Brute force 
int solve(vector<int> &nums){
    int n = nums.size();
    int mxAND = INT_MIN, mxLength = INT_MIN;

    // Step 1-> generate all sub arrs
    for(int i = 0; i < n; i++){
        int AND = 3;
        for(int j = i; j < n; j++){
            AND &= nums[j]; // Caculate AND 

            mxAND = max(AND, mxAND); // Identify mxAND
           
        }
    }

    for(int i = 0; i < n; i++){
        int AND = 3;
        for(int j = i; j < n; j++){
            AND &= nums[j];

            if(AND == mxAND){
                mxLength = max(j - i + 1, mxLength);
            }
        }
    }

    return mxLength;
}

/**
 * Optimal: n
 * step 1: Identify max element 
 * step 2: scan whole array if an element equals to max then increment count 
 */
int longestSubarray(vector<int> &nums){
    int n = nums.size();
    int mx = INT_MIN, count = 0;
    int mxLength = INT_MIN;

    // Step 1: Identify max element 
    for(int i = 0; i < n; i++){
        mx = max(nums[i], mx);
    }
    cout << "MAX: " << mx << endl;

    // Step 2: Scan whole array 
    for(int i = 0; i < n; i++){
        // If an element == mx element 
        if(nums[i] == mx){
            count++;
            mxLength = max(count, mxLength);
        }else { 
            count = 0;
        }
    }

    return mxLength;
}

int main(){
    vector<int> nums = {1, 3, 1, 3, 2, 2};

    cout << longestSubarray(nums);
    return 0;
}