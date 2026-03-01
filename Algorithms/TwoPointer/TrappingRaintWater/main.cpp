// Other Appraoches: Prefix Sum, Monotic Stack 

// Brute Force: O(n^2) SC: O(1)
class Solution {
public:
    int trap(vector<int>& H) {
        int water = 0;
        int n = H.size(); 

        for(int i = 0; i < n; i++) { 
            int mxL = 0, mxR = 0; 

            // Max Left 
            for(int j = 0; j <= i; j++) mxL = max(mxL, H[j]);

            // Max right 
            for(int j = i; j < n; j++) mxR = max(mxR, H[j]);

            water += min(mxL, mxR) - H[i];
        }

        return water;
    }
};

// Two Pointer Optimized approach: TC: O(n) SC: O(1)
class Solution {
public:
    int trap(vector<int>& H) {
        int water = 0;
        int n = H.size(); 

        int l = 0, r = n - 1;
        int mxL = 0 , mxR = 0;

        while(l <= r) { 
            if(mxL <= mxR) { 
                mxL = max(mxL, H[l]);
                water += mxL - H[l];


                l++;
            } else {
                mxR = max(mxR, H[r]);
                water += mxR - H[r];

                r--;
            }
        }

        return water;
    }
};