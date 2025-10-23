#include <bits/stdc++.h>
using namespace std;

/**
 * PS: Given n non-negative integers representing an elevation map where the width of each bar is 1, 
 *     compute how much water it is able to trap after raining.
 * IP: vector<int> arr = {3, 0, 0, 2, 0, 4};
 * OP: 10
 * 
 * APPROACH: Prefix-Suffix Max 
 */

// Aliases
using v = vector<int>;

// Time complexity: O(n)
int rainWater(v &arr) {
    int n = arr.size();
    v mxL(n); v mxR(n);

    mxL[0] = arr[0]; // Copy first element 
    // Pre-Compute mxL and mxR
    for(int i = 1; i < n; i++) 
        mxL[i] = max(mxL[i-1], arr[i]);

    mxR[n-1] = arr[n-1]; // Copy last element 
    for(int i = n - 2; i >= 0; i--) 
        mxR[i] = max(mxR[i+1], arr[i]);
    
    v water(n); int sum = 0;

    // Computer water trapping on each building and sum them 
    for(int i = 0; i < n; i++) {
        water[i] = min(mxL[i], mxR[i]) - arr[i];
        sum += water[i];
    }

    return sum;
}

int main(){
    v arr = {3, 0, 0, 2, 0, 4};

    cout << rainWater(arr) << endl; // OP: 10   
    return 0;
}