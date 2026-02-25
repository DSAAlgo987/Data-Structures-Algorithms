
// TC: O(n) SC: O(1)
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int left = 0; 
        // traverse nums 
        for(auto x: nums) {
            if(x != val) nums[left++] = x; 
        }

        return left; 
    }
};