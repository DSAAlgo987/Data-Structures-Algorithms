// TC: O(n) SC: O(1)
class Solution {
public:
    vector<int> twoSum(vector<int>& A, int t) {
        int l = 0, r = A.size() - 1; 
        int sum = 0; 

        while(l < r) { 
            sum = A[l] + A[r];

            if(sum == t) return {l + 1, r + 1};
            else if(sum > t) r--; 
            else l++; 
        }

        // if there is no pair 
        return {}; 
    }
};