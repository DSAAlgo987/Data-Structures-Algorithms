#include <bits/stdc++.h>
using namespace std;

/**
 * PS: Maximum of all sub arrays of size k
 * 
 * PROBLEM: You are given an array/vector and size of the window. 
 * Your task is to find out all the maximum number of all sub array of size k.
 * 
 * IP: vector<int> A, int k; 
 * OP: vector<int> -> containing max elments of subarray of size k 
 *
 * APPROACHES: 
 *  - Sliding window 
 *      TC: O(n) 
 *      SC: O(n)
 * 
 * LEARNING: 
 *  - For optimization Queue(list) is best data structure along with sliding window 
 */

// aliases
using v = vector<int>; 

// display vector 
void displayV(v A) { 
    cout << "[ ";
    for(auto x: A) 
        cout << x << " ";
    cout << "]";
}

// sliding window 
v mxSubarray(v &A, int k) { 
    v ans; 
    list<int> q; 

    int i = 0, j = 0; 
    int n = A.size(); 

    while(j < n) { 
        // calc 
        while(q.size() > 0 && q.back() < A[j]) 
            q.pop_back(); 

        q.push_back(A[j]);

        // achieve window size 
        if(j - i + 1 < k) j++;

        // hit window size 
        else if(j - i + 1 == k) { 
            // ans <- calc 
            ans.push_back(q.front());

            // slide window 
            if(A[i] == q.front()) q.pop_front(); 

            i++;
            j++;
        }
        
    }

    // return the ans 
    return ans; 
}

int main(){
    v A = {1, 3, 2, -1, 1, 4, 3};
    int k = 3;

    displayV(mxSubarray(A, k));
    
    return 0;
}