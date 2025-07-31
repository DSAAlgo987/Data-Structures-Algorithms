#include <bits/stdc++.h>
using namespace std;

// Brute force -> n^2
int subarrayBitwiseORsBruteForce(vector<int> &nums){
    int n = nums.size();
    unordered_set<int> s;

    // Step 1: Generate all subarrays 
    for(int i = 0; i < n; i++){
        int OR = 0; // Initially
        for(int j = i; j < n; j++){
            // Step 2: Calculate bitwise
            OR |= nums[j];

            s.insert(OR); // Step 3: Store unique elements 
        }
    }

    // Step 4: Return size of unique ORs results
    return s.size();
}

// Optimal -> n * w (w = 30) -> n
int subarrayBitwiseORs(vector<int> &arr){
    unordered_set<int> prevOrs; // Store prev OR element 
    unordered_set<int> result;

    // Start calculating Unique Ors 
    for(auto n: arr){ // n 
        // Current set 
        unordered_set<int> currentOrs;

        // Step 1: OR with prev element and store in currentOr set
        for(auto val: prevOrs){ // w -> unique ors 
            currentOrs.insert(n | val);
        }

        // Step 2: Store current element in current set 
        currentOrs.insert(n);

        // Step 3: Store all OR elements in Result Set from currentOrs set 
        for(auto val: currentOrs){
            result.insert(val);
        }

        // Step 4: Update prevOrs Set by setting currentOr set 
        prevOrs = currentOrs;
    }

    // Step 5: Return result size 
    return result.size();
}


int main(){
    vector<int> nums = {1, 1, 4};

    cout << subarrayBitwiseORsBruteForce(nums) << endl;    
    return 0;
}