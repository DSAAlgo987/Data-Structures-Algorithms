#include <bits/stdc++.h>
using namespace std;

/**
 * Category      : Prefix Sum + HashMap
 * Variation     : Count subarrays with sum = k
 * Observation   : We want subarrays where sum == length
 *                   -> sum - length == 0
 *                   -> Transform: prefixSum[i] - (i + 1) == 0
 * Trick         : Use hashmap to store frequency of (prefixSum - index)
 *                   and accumulate counts when this diff repeats.
 */


// Brute force  -> n^2
int goodSubbarrBruteForce(vector<int> nums){
    int n = nums.size();
    int count = 0;

    // Generate all possible subarrays
    for(int i = 0; i < n; i++){
        int sum = 0;
        for(int j = i; j < n; j++){
            sum += nums[j]; // Caculte sum 

            if(sum == j+1){ // if sum == length  (good subarray)
                count++;    // then INC count
            }
        }   
    }

    return count;
}

// Optimal -> n
int goodSubarray(vector<int> nums){
    int sum = 0, count = 0;
    int n = nums.size();

    unordered_map<int, int> mp; // <sum, count> 
    mp[0] = 1; // Initally 0 is present freq : 1

    // Start calc prefix sum & identify good subarray 
    for(int i = 0; i < n; i++){
        sum += nums[i]; // calculate sum 

        if(mp.find(sum - (i + 1)) != mp.end()){ // if sum - i + 1 present 
            count += mp[sum - (i + 1)]; // INC count 
        }

        mp[sum]++; // Store sum with freq 
    }

    return count;
}

int main(){
    vector<int> nums = {1 , 2 , 0};

    cout << goodSubarray(nums);
    
    return 0;
}