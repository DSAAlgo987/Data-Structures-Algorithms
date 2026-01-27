#include <bits/stdc++.h>
using namespace std; 

/**
 * PS: First Negative Number in Every Window of size K 
 * 
 * PROBLEM: You are given an array and window size k.
 * Your task is to find first negative number in every window of size k.
 * 
 * IP: vector<int> A, int k;
 * OP: vector<int> containing all first negative numbers;
 * 
 * APPROACH: 
 *  1. Brute Force: TC: O(n^2) SC: O(n)
 *  2. Sliding window: TC: O(n) SC: O(n) 
 * 
 * LEARNING: 
 *  - How to do this with naive approach
 *  - Avoid repetitive work with sliding window approach
 *  - Learnt how to solve by using data structure to avoid redundency 
 * 
 * METHODS: 
 *  - Queue -> list<int>
 *  - front(), back()
 *  - push_front(), pop_front(), push_back(), pop_back()
 */

// Aliases
using v = vector<int>;

// Display vector
void displayV(v A) {
    cout << "[ " ;
    for(auto x: A) 
        cout << x << " ";
    cout << "]" << endl;
}

// Brute force 
v solve(v &A, int k) { 
    int n = A.size(); 

    v ans; 

    // Step 1: General possible subarray of size k
    for(int i = 0; i < n - k + 1; i++) { 
        // Step 2: While generating subarray check if any # is -ve
        bool found = false; 
        for(int j = i; j < i + k; j++) { 
            if(A[j] < 0) {
                ans.push_back(A[j]);
                found = true;
                break; 
            }

        }
        // There is no negative # 
        if(!found) ans.push_back(0);
    }

    // Step 3: Return ans vector 
    return ans; 
}

// Sliding window 
v firstNegative(v &A, int k) { 
    list<int> q; 
    v ans; 

    int n = A.size();
    int i = 0, j = 0; 
    
    while(j < n) { 
        // Calculation: A[j] -> -ve ?  
        if(A[j] < 0) q.push_back(A[j]); 

        // Achieve window size 
        if(j - i + 1 < k) j++; 

        // Hit window size 
        else if(j - i + 1 == k) { 
            // Ans <- calcuation 
            // Case 1: list(q) can be empty 
            if(q.empty()) ans.push_back(0);
            // Case 2: List contains -ve numbers  
            else ans.push_back(q.front());

            // Slide window 
            if(A[i] == q.front()) q.pop_front();

            i++;j++;
        }
    }

    // Return the ans vector 
    return ans; 
}


int main() {
    v A = {12, -1, -7, 8, -15, 30, 16, 28};
    int k = 3; 

    v ans; 

    ans = solve(A, k); 

    displayV(ans);
    

    ans = firstNegative(A, k);
    displayV(ans); 

    return 0; 
}