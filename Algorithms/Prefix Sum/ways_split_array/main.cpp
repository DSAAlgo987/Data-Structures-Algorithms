#include <bits/stdc++.h>
using namespace std;

/**
 * int -> 10^9
 * long -> 10^12
 * long long int > 10 ^ 18 (LL)
 */

// Optimized 
int waysToSplit(vector<int> &nums){
    long long int L = 0, R = 0;

    int count = 0;
    // calulcate right sum 
    R = accumulate(nums.begin(), nums.end(), 0LL);

    // Start identifying valid splits 
    for(int i = 0; i < nums.size() - 1; i++){
        // Add ith cal in L and Remove from R 
        L += nums[i];
        R -= nums[i];

        // compare >= 
        if(L >= R) count++;
    }

    return count;
}

int main(){
    vector<int> nums = {10, 4, -8, 7};

    cout << waysToSplit(nums) << endl;
    
    return 0;
}