#include <bits/stdc++.h>
using namespace std;

/**
 *Category: Prefix Sum Variation
 *Problem: Product of Array Except Self
 *Technique: Prefix Product + Suffix Product
 *Insight: No division allowed, so we simulate left and right product
 */

// Brute Force -> n^2
vector<int> productExceptSelfBruteForce(vector<int> &nums)
{
    int n = nums.size();

    vector<int> ans(n);

    for (int i = 0; i < n; i++)
    {
        int left = 1;
        for (int j = 0; j < n; j++)
        {
            // Product except self;
            if (i != j)
            {
                left *= nums[j];
            }
        }
        // Store product at ith position
        ans[i] = left;
    }

    return ans;
}

vector<int> productExceptSelf(vector<int> &nums){
    int n = nums.size();
    
    vector<int> prefixProd(n);
    vector<int> suffixProd(n);

    // Initialize 0th index of prefix prod as 1  
    prefixProd[0] = 1;

    // Start calculating prefix prod from 1st index 
    for(int i = 1; i < n; i++){
        prefixProd[i] = prefixProd[i - 1] * nums[i-1];
    }

    // Intialize n-1th  index of suffix prod as 1
    suffixProd[n-1] = 1;

    // Start calculating suffix prod from n-2th index 
    for(int i = n-2; i >= 0; i--){
        suffixProd[i] = suffixProd[i + 1] * nums[i + 1];
    }

    // Now, calulcate final ans by multiplying both prefix[i] * suffix[i]
    for(int i = 0; i < n; i++){
        nums[i] = prefixProd[i] * suffixProd[i];
    }

    return nums;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4};

    vector<int> ans = productExceptSelf(nums); 
    

    for(auto n: ans){
        cout << n << " ";
    }
    return 0;
}