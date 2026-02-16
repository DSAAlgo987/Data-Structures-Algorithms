/**
 * PS: Binary Subarry with sum 
 * 
 * PROBLEM: You are given an array nums and a goal. 
 * Your task to cnt those subarrys whose sum is equal to goal. 
 * 
 * IP: vector<int> nums, int goal 
 * OP: # -> int
 * 
 * APPROACH: 
 *  -BF: O(n^2)
 *  -PS + Hashmap: O(n)
 *  -VSWCV: O(n)
 * 
 * LEARNING: 
 *  - It is a variation of cnt nice subarrays 
 *  - Identifaction of variable sliding window counting variation 
 *  - Formula use for handling all subarrs: 
 *      Exactly(goal) = AtMost(goal) - AtMost(goal - 1); 
 */

// VSWCV 
class Solution {
public:
    int AtMost(vector<int>& nums, int goal) { 
        // edge case 
        if(goal < 0) return 0;
        
        long long sum = 0; 
        int cnt = 0; 

        int left = 0; 

        // traverse nums array 
        for(int right = 0; right < nums.size(); right++) { 
            // calculation 
            sum += nums[right]; 

            // invalid subarr 
            while(sum > goal) {
                // remove left calculation 
                sum -= nums[left]; 

                left++;
            }

            // calculation of ans 
            cnt += right - left + 1; 
        }

        // return ans 
        return cnt; 
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return AtMost(nums, goal) - AtMost(nums, goal - 1);    
    }
};