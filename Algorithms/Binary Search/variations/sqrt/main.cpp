#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Statement: Find sqrt of a number.
 * 
 * Ip:
 * int number;
 * 
 * Op:
 * int sqrtNumber;
 * 
 * Constraints:
 * 0 <= x <= 2^31-1
 */

// Linear Search Approach: O(N) O(N)
int sqrtLinear(int n) {
    // Create vector from 0 -> n 
    vector<int> numbers(n + 1, 0);

    // Initialize vector 
    for(int i = 0; i < n + 1; i++) {
        numbers[i] = i;
    }

    // Identify sqrt number of given n 
    int sqrtNumber;

    for(int i = 0; i < n + 1; i++) {
        if( i * i > n) {
            break;
        }

        sqrtNumber = i;
    }

    return sqrtNumber;
}

// Binary Search Square Root
// Time: O(log n), Space: O(1)
int sqrtBinary(int n) {
    int low = 0, high = n, ans = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;   // prevent overflow
        long long mult = 1LL * mid * mid;   // prevent overflow

        if (mult == n) {
            return mid; // perfect square
        }
        else if (mult < n) {
            ans = mid;     // store last valid value
            low = mid + 1; // move right
        }
        else {
            high = mid - 1; // move left
        }
    }
    return ans; // floor(sqrt(n)) if not perfect square
}



int main(){
    int n = 9;

    cout << sqrtBinary(90) << endl;
    
    return 0;
}