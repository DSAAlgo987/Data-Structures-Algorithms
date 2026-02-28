
// Brute Force: TC: O(n^3)  SC:O(k) 
class Solution {
public:
    using v = vector<int>;
    using vv = vector<v>;
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<v> s; 
        int n = nums.size();

        // first sort array to avoid duplicates 
        sort(nums.begin(), nums.end()); 

        // Now Idenitfy those elmenets whose sums are == 0
        for(int i = 0; i < n; i++) { 
            for(int j = i + 1; j < n; j++) { 
                for(int k = j + 1; k < n; k++) { 
                    if(nums[i] + nums[j] + nums[k] == 0) { 
                        s.insert({nums[i], nums[j], nums[k]});
                    }
                }
            }
        }
        

        // Now set all those vector in 2d vector 
        vv ans(s.begin(), s.end()); 

        return ans; 
    }
};

// Optimized appraoch: Three pointer : TC: O(n^2) SC: O(k)
class Solution {
public:
    using v = vector<int>;
    using vv = vector<v>;
    vector<vector<int>> threeSum(vector<int>& nums) {
        // first sort nums vector to avoid duplicates 
        sort(nums.begin(), nums.end());

        int n = nums.size();
        vv ans; 
        for(int i = 0; i < n; i++) {

            // Skip duplicate fixed element 
            if(i > 0 && nums[i] == nums[i-1]) continue; 

            int j = i + 1, k = n - 1; 

            while(j < k) { 
                int total = nums[i] + nums[j] + nums[k];

                if(total == 0) {
                    ans.push_back({nums[i], nums[j], nums[k]});

                    // To avoid duplicates 
                    while(j < k && nums[j] == nums[j + 1]) j++;

                    while(j < k && nums[k] == nums[k - 1]) k--;
                    j++; k--; 
                }
                else if(total < 0) j++;
                else k--; 
            }
        }

        return ans; 
    }
};