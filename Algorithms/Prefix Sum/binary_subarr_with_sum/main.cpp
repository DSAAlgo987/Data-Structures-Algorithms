/**
 * PS: Binary Subarry with sum 
 * 
 * Problem: You are given an array and a goal as an input.
 * Your task is to identify the cnt of those subarrs whose 
 * sum == goal.
 * 
 * IP: vector<int> nums, int goal;
 * OP: int #; 
 * 
 * APPROACHES: 
 *  - BRUTE FORCE: O(n^2) , O(1)
 *  - PREFIX SUM: O(n^2), O(n) 
 *  - PREFIX SUM + HASHMAP: O(n), O(n)
 */

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int sum = 0; 
        int cnt = 0; 

        unordered_map<int, int> m; // Track seen sum 
        m[0] = 1; // sum : 0, Freq: 1

        // traverse nums 
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];

            // present -> m
            if(m.find(sum - goal) != m.end())
                cnt += m[sum - goal]; 

            m[sum]++; // DO INC seen sum  
        }

        return cnt;
    }
};