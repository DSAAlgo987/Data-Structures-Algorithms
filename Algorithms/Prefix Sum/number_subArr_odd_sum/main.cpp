#include <bits/stdc++.h>
using namespace std;

int M = 1e9 + 7; // -> 1* 10 ^9 + 7

// Brute Force -> n^3
int solve(vector<int> &nums){
    int count = 0;
    int n = nums.size();

    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            int sum = 0;
            for(int k = i; k <= j; k++){
                sum += nums[k];
            }

            // Check odd -> INC count 
            if(sum % 2 == 1) count = (count + 1) % M;
        }
    }

    return count;
}

// Better -> n^2
int solveBetter(vector<int> &nums){
    int count = 0;
    int n = nums.size();
    for(int i = 0; i < n; i++){
        int sum = 0;
        for(int j = i; j < n; j++){
            sum += nums[j];
            // Check odd -> INC count
            if(sum % 2 == 1) count = (count + 1) % M;
        }
        
    }

    return count;
}

// Optimal -> TC : n, SC : 1
int numOfSubarrays(vector<int> &nums){
    int count = 0; 
    int n = nums.size();

    /**
     * Instead of using prefix sum vector.
     * We can use sum variable in order to 
     * optimize space complexity.
     */
    int sum = 0; 

    int evenCount = 1; // Initially 1 (bcoz 0 is even);
    int oddCount = 0;
    int result = 0;

    // Start calculating sum, evenCount, oddCount and result 
    for(int i = 0; i < n; i++){
        sum += nums[i];

        if(sum % 2 == 0){ // odd + even = odd
            result = (result + oddCount) % M;

            // Increment evenCount 
            evenCount++;
        }else {  // even + odd = odd
            result = (result + evenCount) % M;

            // Increment oddCount 
            oddCount++;
        }
    }

    return result;
}


int main(){
    vector<int> nums = {1, 2, 3, 4};

    cout << numOfSubarrays(nums);
    
    return 0;
}