/**
 * PS: # nice subarrs
 * 
 * PROBLEM: You are given an array nums, and k. 
 * Your task is to identify all nice subarrays cnt.
 * Nice subarray if there are k elements in the subarr is called nice subarr.
 * 
 * IP: vector<int> nums, int k; 
 * OP: # of nice subarrs (int);
 * 
 * APPROACH: 
 *  - BF: O(n^2)
 *  - VSW: O(n)
 *  - PS + Hashmap: O(n)
 * 
 * LEARNING: 
 *  - Only variable sliding window is not capable to solve this problem. 
 *  - Here we need to identify all valid subarrs in which there are exactly k odd elemets should be there.
 *  - For this we are using one formula: 
 ** - Exactly(k) = AtMost(k) - AtMost(k - 1); 
 */

// Variable sliding window counting variation 
class Solution {
public:
    int AtMost(vector<int>& nums, int k) { 
        int i = 0, oddCnt = 0, cnt = 0; 

        // traverse nums 
        for(int j = 0; j < nums.size(); j++) { 
            // calculation 
            if(nums[j] % 2 == 1) oddCnt++;

            // Invalid window 
            while(oddCnt > k) {
                // Remove ith calculation until valid
                if(nums[i] % 2 == 1) oddCnt--; 
                i++;
            }

            // calculate ans : all valid subarrs
            cnt += j - i + 1; 
        }

        return cnt; 
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return AtMost(nums, k) - AtMost(nums, k-1);
    }
};

// Prefix sum + Hashamp
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int sum = 0; 
        unordered_map<int, int> m; // <sum, freq>
        m[0] = 1; // sum = 0, freq = 1
        int cnt = 0;  

        // traverse nums 
        for(int i = 0; i < nums.size(); i++) { 
            // check odd? 
            if(nums[i] % 2 == 1) sum++; 

            // sum - k present in map 
            if(m.find(sum - k) != m.end()) cnt += m[sum - k]; 

            // add sum with freq 
            m[sum]++;
        }

        return cnt; 
    }
};