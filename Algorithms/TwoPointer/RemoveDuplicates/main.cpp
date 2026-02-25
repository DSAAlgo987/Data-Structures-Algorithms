
// TC: O(n) SC: O(1)
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int left = 0; 

        for(auto x: nums) { 
            if(x != nums[left]) nums[++left] = x; 
        }

        return left + 1; 
    }
};