#include <bits/stdc++.h>
using namespace std;

// Brute force
int flippingGame(vector<int> &nums){
    int mx = INT_MIN, n = nums.size(); 

    for(int i = 0; i < n; i++){
        // copy nums 
        vector<int> temp = nums;

        // Generate all possible sub-arrs
        for(int j = i; j < n; j++){
            // flip
            // x = 1 - x 
            temp[j] = 1 - temp[j];
        }

        // Sum after flip 
        // accumulate(first, last, init)
        int sum = accumulate(temp.begin(), temp.end(), 0);

        // store max sum 
        mx = max(mx, sum);
    }

    return mx;
}

int main(){
    vector<int> nums = {1, 0, 0, 1, 0};

    cout << flippingGame(nums) << endl;

    return 0;
}