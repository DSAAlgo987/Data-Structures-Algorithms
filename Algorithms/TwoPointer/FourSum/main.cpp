
// Variation: 3 Sum

// BF: O(n^4) -> Polynomial Time Complexity
class Solution {
public:
    using v = vector<int>;
    using vv = vector<v>;
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<v> s; 

        // Handle duplicates
        sort(nums.begin(), nums.end());


        int n = nums.size();
        for(int i = 0; i < n; i++) { 
            for(int j = i + 1; j < n; j++) { 
                for(int k = j + 1; k < n; k++) { 
                    for(int l = k + 1; l < n; l++) {
                        long long sum = (long long) nums[i] + nums[j] + nums[k] + nums[l];
                        if(sum == target) 
                            s.insert({nums[i], nums[j], nums[k], nums[l]});
                    }
                }
            }
        }

        vv ans(s.begin(), s.end());

        return ans; 
    }
};

// Optimized ApproacH: O(n^3) -> Cubic Time Complexity
class Solution {
public:
    using v = vector<int>;
    using vv = vector<v>;
    vector<vector<int>> fourSum(vector<int>& A, int t) {
        vv ans; 

        // Always sort array to apply two pointers aproach  
        sort(A.begin(), A.end());

        int n = A.size();

        // 4 sum 
        for(int i = 0; i < n - 3; i++) { 
            // Handle duplication
            if(i > 0 && A[i] == A[i-1]) continue; // skip if current element == prev element 

            // 3 sum 
            for(int j = i + 1; j < n - 2; j++) { 
                // handle duplication 
                if(j > i + 1 && A[j] == A[j-1]) continue; 

                int k = j + 1, l = n - 1; 

                while(k < l) { 
                    long long sum = (long long) A[i] + A[j] + A[k] + A[l];

                    if(sum == t) {
                        ans.push_back({A[i], A[j], A[k], A[l]});
                        // Handle duplication
                        while(k < l && A[k] == A[k+1]) k++;
                        while(k < l && A[l] == A[l-1]) l--;

                        // if no duplication 
                        k++; l--;
                    }
                    else if(sum > t) l--;
                    else k++;
                }
            }
        }


        return ans; 
    }
};