// Brute Force : O(n^3)
class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long count = 0;
        int n = nums.size();

        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){ // Generate possible sub arrays 
                // Count continuous 0 sub arrys
                bool allZero = true;
                for(int k = i; k <= j; k++){
                    if(nums[k] != 0){
                        allZero = false;
                        break;
                    }
                }

                if(allZero){
                    count++;
                }

            }
        }
        return count;
    }   
};

// Optimized : O(n)
class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long count = 0;
        long long streak = 0;

        for(auto n: nums){
            // Current element is 0 
            if(n == 0){
                streak++;
                count += streak;
            }else {
                // if current element is not 0 
                streak = 0;
            }
        }
        return count;
    }
};