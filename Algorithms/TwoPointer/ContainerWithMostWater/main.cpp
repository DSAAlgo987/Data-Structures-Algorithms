// TC: O(n) SC: O(1)
class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int res = 0;

        while(l < r) { 
            // calculation = l * w  
            int area = (r - l) * min(height[r], height[l]);
            res = max(area, res);

            // conditions 
            if(height[l] < height[r]) l++;
            else if(height[l] > height[r]) r--;
            else r--;
        }

        return res; 
    }
};