// Variation: 3 Sum


// BF: O(n^3) 
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int mn = INT_MAX, sum = 0, ans; 
        int n = nums.size();

        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) { 
                for(int k = j + 1; k < n; k++) { 
                    int sum = nums[i] + nums[j] + nums[k];
                    
                    if(sum == target) return sum; 
                    else {
                        int diff = abs(sum - target);

                        if(diff < mn) {
                            mn = diff; 
                            ans = sum; 
                        }
                    }
                }
            }
        }

        return ans; 
    }
};

// Optimized approach: O(n^2)
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int mn = INT_MAX, sum = 0, ans; 
        int n = nums.size();

        // Sort the array first 
        sort(nums.begin(), nums.end());

        for(int i = 0; i < n; i++) { 
            int j = i + 1, k = n-1; 

            while( j < k) { 
                sum = nums[i] + nums[j] + nums[k];

                if(sum == target) return sum; 
                else if (sum > target) k--;
                else j++;

                // calculations
                int diff = abs(sum - target);
                if(diff < mn) {
                    mn = diff;
                    ans = sum; 
                }
            }
        }

        return ans; 
    }
};