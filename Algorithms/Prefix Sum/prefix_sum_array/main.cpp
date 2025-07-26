#include <bits/stdc++.h>
using namespace std;

void display(vector<int> &arr){
    for(auto n: arr){
        cout << n << " ";
    }
    cout << endl;
}

// Brute force
void solve(vector<int> &nums){
    int n = nums.size();

    vector<int> prefixSum(n);

    for(int i = 0; i < n; i++){
        int sum = 0;
        for(int j = 0; j <= i; j++){
            sum += nums[j];
        }
        // store sum for each index 
        prefixSum[i] = sum;
    }

    display(prefixSum);
}

// Prefix sum 
void solve1(vector<int> &nums){
    int n = nums.size();

    vector<int> prefixSum(n);

    // Intially same 
    prefixSum[0] = nums[0]; 

    // Start calulcating sum for each index 
    // Iterate from index 
    for(int i = 1; i < n; i++){
        // Formula
        prefixSum[i] = prefixSum[i-1] + nums[i];
    }

    display(prefixSum);
}

// Optimal: if space is constraint
void solve2(vector<int> &nums){

    for(int i = 1; i < nums.size(); i++){
        nums[i] = nums[i-1] + nums[i];
    }

    display(nums);
}

int main(){
    vector<int> nums = {0, 1, 2, 3, 4, 5};

    solve2(nums);
    return 0;
}