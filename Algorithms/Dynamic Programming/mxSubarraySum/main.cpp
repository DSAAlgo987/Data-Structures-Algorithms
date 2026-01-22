#include <bits/stdc++.h>
using namespace std;

/**
 * PS: MX Subarray Sum
 * Problem: You are given an array of length n. 
 * Your task is to find the max subarray sum. 
 * 
 * IP: vector<int> arr;
 * OP: (int) -> max sum 
 * 
 * APPROACHES: 
 * 1. Brute Force           - n^3
 * 2. Better                - n^2
 * 3. DP                    - n
 * 4. Kadane's algorithm    - n
 * 5. DAC                   - nlogn
 * 
 * LEARNING: 
 *  - Learnt a lot from this question 
 *  - Solved this question with different approaches
 *  - All possible subarrays - n (n + 1) / 2
 */

// Aliases 
using v = vector<int>;
using vv = vector<v>;

// Brute Force 
int solveBruteForce(v &arr) { 
    int n = arr.size();
    int mx = INT_MIN;

    // Generate all the subArrs
    for(int i = 0; i < n; i++) { 
        for(int j = i; j < n; j++) { 
            // Now, Take some of each subarr 
            int sum = 0; 
            for(int k = i; k <= j; k++) {
                sum += arr[k];
            }
            // Identify max sum 
            mx = max(mx, sum);
        }
    }

    // Return the final ans
    return mx; 
}

// Better 
int solveBetter(v &arr) { 
    int n = arr.size(); 
    int mx = INT_MIN;

    // Generate all subArrs
    for(int i = 0; i < n; i++) { 
        // While generate take sum too & idetnify mx too 
        int sum = 0; 
        for(int j = i; j < n; j++) { 
            sum += arr[j];
            mx = max(mx, sum);
        }
    }

    // Return final ans 
    return mx; 
}

// DP (Kadane's version 1) 
/**
 * TC: O(n)
 * SC: O(n)
 */
int dpSum(v A) { 
    int n = A.size();
    
    v S(n, 0);

    // set S[0] = A[0]
    S[0] = A[0];

    // Start working 
    for(int i = 1; i < n; i++) {
        // Prev Sum -> Negative 
        if(S[i-1] < 0) { 
            S[i] = A[i];
        } else { 
            S[i] = S[i-1] + A[i];
        }
    }

    return *max_element(S.begin(), S.end());
}

// Kadane's Algorithm
/**
 * TC: O(n)
 * SC: O(1)
 */
int KadaneSum(v A) {
    // Start working 
    for(int i = 1; i < A.size(); i++) { 
        // Prev Sum -> Negative 
        if(A[i-1] < 0) { 
            continue;
        } else { 
            A[i] = A[i-1] + A[i];
        }
    }

    return *max_element(A.begin(), A.end());
}

// DAC 
/**
 * TC: O(nlogn) 
 */
 
int crossSum(int l, int mid, int h, v &A) { 
    int leftSub = INT_MIN, rightSub = INT_MIN;
    int sum = 0; 
    
    for(int i = mid; i >= l; i--) {
        sum += A[i];
        leftSub = max(leftSub, sum);
    }
    
    sum = 0; 
    for(int i = mid + 1; i <= h; i++) { 
        sum += A[i];
        rightSub = max(rightSub, sum);
    }
    
    return leftSub + rightSub;
}
 
int mxSub(int l, int h, v &A) { 
    // BC 
    if(l == h) return A[l];
    
    // Divide 
    int mid = (l + h) / 2; 
    
    int leftMx = mxSub(l, mid, A);
    int rightMx = mxSub(mid + 1, h, A);
    
    int cSum = crossSum(l, mid, h, A); // Handling subarray case 
    
    return max({leftMx, rightMx, cSum});
}



int main(){
    v arr = {4, -5, 8, -2, -1, 7, -6};
    int n = arr.size();

    cout << "MX SUM: " << solveBruteForce(arr) << endl;
    cout << "MX SUM: " << dpSum(arr) << endl;
    cout << "MX SUM: " << KadaneSum(arr) << endl;
    cout << "MX SUM: " << mxSub(0, n-1, arr) << endl;
    
    return 0;
}