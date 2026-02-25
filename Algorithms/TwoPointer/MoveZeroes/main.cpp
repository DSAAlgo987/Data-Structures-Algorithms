
// TC: O(n) SC: O(1)
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int insertPos = 0; 

        // Move all non-zero towards the left end 
        for(auto x: nums) {
            if(x != 0) nums[insertPos++] = x; 
        }

        // Add all remaining zeroes 
        while(insertPos < nums.size()) { 
            nums[insertPos++] = 0; 
        }
    }
};