#include <bits/stdc++.h>
using namespace std;

// Brute force : O(n^3)
int longestSubarrayBruteForce(vector<int> &nums) { 
    int n = nums.size();
    int mx = 0;

    // Step 1: Generate all possible subarrays 
    for(int i = 0; i < n; i++) { 
        for(int j = i; j < n; j++) {
            int countOnes = 0;
            int countZeroes = 0;

            // Access each element from subarrays and increment count zeroes or ones 
            for(int k = i; k <= j; k++) {
                if(nums[k] == 1) {
                    countOnes++;
                } else {
                    countZeroes++;
                }

            }
            // There must be at most one 0 in subarray 
            int maxLength;
            if(countZeroes <= 1) { 
                if(countZeroes == 0) { // if ther are no zeroes
                    maxLength = countOnes -1; // Caclulate length of max length
                }else { 
                    // There is one single zero in subarray we reduce it and we only store coutones length
                    maxLength = countOnes;
                }
                mx = max(mx, maxLength);
            } 
        }
    }

    return mx;
}

// Sliding window Approach: O(n) 
int longestSubarray(vector<int>& nums) {
    int n = nums.size();
    int mx = 0, i = 0, j = 0;
    int countZeroes = 0;

    while(j < n) {
        if(nums[j] == 0) {
            countZeroes++;
        }

        // If window has at most one zero
        if(countZeroes <= 1) {
            mx = max(mx, j - i + 1 - 1); // Always remove one element
            j++;
        } 
        // If more than one zero, shrink from left
        else {
            while(countZeroes > 1) {
                if(nums[i] == 0)
                    countZeroes--;
                i++;
            }
            mx = max(mx, j - i + 1 - 1); // Max length after adjusting window
            j++;
        }
    }

    return mx;
}

int main(){
    vector<int> nums = {1, 0, 1, 1, 0};

    cout << longestSubarray(nums) << endl;
    return 0;
}