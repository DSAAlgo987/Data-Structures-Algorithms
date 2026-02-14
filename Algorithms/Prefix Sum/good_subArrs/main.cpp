#include <stdio.h>
#include <bits/stdc++.h>

using namespace std; 

/**
 * PROBLEM: Good Subarrays
 *
 * Given an array a1, a2, …, an (values 0 → 9).
 * A subarray a[l..r] is GOOD if:
 *
 *      sum(l..r) = length of subarray = (r - l + 1)
 *
 * Example:
 * a = [1,2,0]
 * Good subarrays = [1], [2,0], [1,2,0] → answer = 3
 *
 *
 * INPUT:  vector<int> A
 * OUTPUT: count of good subarrays
 *
 *
 * APPROACH:
 *
 * 1) Brute Force
 *    Generate all (l, r), compute sum, check:
 *          if sum == r-l+1 → count++
 *    TC: O(n²)
 *
 *
 * 2) Optimized (Prefix Sum + HashMap)  ⭐ IMPORTANT
 *
 *    We want:
 *          sum(l..r) = length
 *
 *    Move length to left:
 *          sum(l..r) - length = 0
 *
 *    Observe:
 *          length = 1 + 1 + 1 + ... (for each element)
 *
 *    So subtract 1 from every element beforehand.
 *
 *          b[i] = a[i] - 1
 *
 *    Now condition becomes:
 *          sum of b[l..r] = 0
 *
 *    → Problem reduces to counting subarrays with sum = 0.
 *
 *
 * HASHMAP IDEA:
 *
 *    If two prefix sums are equal,
 *    the subarray between them has sum = 0.
 *
 *    For each prefix:
 *          answer += frequency of this prefix seen before.
 *
 *    m[0] = 1 → handles subarrays starting from index 0.
 *
 *
 * TC: O(n)
 * SC: O(n)
 *
 *
 * LEARNING / PATTERN:
 *
 *    Whenever you see:
 *      - sum = length
 *      - equal distribution
 *      - balance
 *
 *    Think:
 *      → Can I modify each element to remove the length?
 *
 *    Convert to:
 *      → subarray sum = 0
 *
 */


// aliases
using v = vector<int>; 


int solve(v &A) { 
    int n = A.size(); 
    int cnt = 0; 
    
    // generate all possible subarrs 
    for(int l = 0; l < n; l++) {
        int sum = 0; 
        for(int r = l; r < n; r++) {
            sum += A[r]; 
            
            if(sum == r - l + 1) cnt++;
        }
    }
    
    return cnt; 
}

// Prefix sum + Hashmap 
int goodSubarrs(v &A) { 
    int n = A.size(); 
    v B(n, 0); 
    
    
    // Subtract 1 from each element of A
    for(int i = 0; i < n; i++) B[i] = A[i] - 1; 
    
    unordered_map<int, int> m; // <sum, freq> 
    
    // subarry sum == 0 -> INC Cnt 
    m[0] = 1; // seen sum = 0; 
    int cnt = 0; 
    int sum = 0; 
    
    for(int i = 0; i < n; i++) { 
        sum += B[i]; 
        
        if(m.find(sum) != m.end()) cnt += m[sum];
        
        m[sum]++;
    }
    
    return cnt; 
}



int main()
{
    v A = { 1,1,0,1,1 };
    cout << "# of good subarrs: " << solve(A) << endl;
    
    cout << "# of good subarrs: " << goodSubarrs(A) << endl;
    return 0;
}