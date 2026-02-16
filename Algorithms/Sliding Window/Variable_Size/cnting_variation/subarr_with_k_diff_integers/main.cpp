/**
 * PS: Subarr with k different integers 
 * 
 * PROBLEM: You are given an array and k. 
 * Your task is to find all those subarrs which has k 
 * different integers. Return # of those subarrs.
 * 
 * IP: vector<int> A, int k; 
 * OP: # -> cnt of those subarrs (int) 
 * 
 * APPROACH: 
 *  - BF: O(n^2) 
 *  - VSWCV: O(n)
 * 
 * LEARNING: 
 *   
 */

// Brute force 
class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int k) {
        int cnt = 0; 

        // Generate all PSAs 
        for(int i = 0; i < A.size(); i++) { 
            unordered_map<int, int> m; // <#, f> 

            for(int j = i; j < A.size(); j++) { 
                // Store freq # and freq -> map 
                m[A[j]]++; 

                // == k 
                if(m.size() == k) cnt++; 
            }
        }

        return cnt; 
    }
};

// Variable Sliding Window Couting variation 
class Solution {
public:
    int AtMost(vector<int> &A, int k) { 
        // edge case 
        if(k < 1) return 0; 

        int cnt = 0; // m.size
        int i = 0, ans = 0; 

        unordered_map<int, int> m; // <#, f> 

        // traverse A 
        for(int j = 0; j < A.size(); j++) { 
            // calculation 
            m[A[j]]++;

            if(m[A[j]] == 1) cnt++; 

            // invalid window 
            while(cnt > k) {
                // remove ith calculations
                m[A[i]]--;

                if(m[A[i]] == 0) cnt--; 
                i++; 
            }

            // calculation of ans 
            ans += j - i + 1; 
        }

        return ans; 
    }

    int subarraysWithKDistinct(vector<int>& A, int k) {
       return AtMost(A, k) - AtMost(A, k - 1); 
    }
};