#include <bits/stdc++.h>
using namespace std;

/*
   Problem: Target Sum (LeetCode 494)
   ---------------------------------
   - Hume + / - sign assign karke target sum banana hai.
   - Ye problem "Count Subset with Given Difference" me convert hoti hai.

   Derivation:
   Let sumOfArr = sum(nums)
   Positive subset = P, Negative subset = N

   P - N = target
   P + N = sumOfArr
   => 2P = target + sumOfArr
   => P = (target + sumOfArr) / 2

   Matlab: problem reduce ho gayi "Count of Subsets with sum = P"

   Baat wohi hai, bas tarika alag hai puchhne ka 🙂
*/



int M = 1e9 + 7; // 10^9 + 7
// difference -> target
int findTargetSumWays(vector<int> &nums, int target)
{
    int n = nums.size();

    // Calculate whole array sum
    int sumOfArr = 0;

    for (auto n : nums)
    {
        sumOfArr += n;
    }

    // Check if odd return false
    if ((sumOfArr + target) % 2 != 0)
    {
        return 0;
    }

    // Calculate sum1 Using Derived formula
    int sum1 = (sumOfArr + target) / 2;

    vector<vector<int>> t(n + 1, vector(sum1 + 1, 0)); // declaration

    t[0][0] = 1; // Initialization

    // Start, filling remaining the parts: i -> n, j-> sum1
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 0; j < sum1 + 1; j++)
        {
            if (nums[i - 1] <= j)
            {
                t[i][j] = (t[i - 1][j - nums[i - 1]] + t[i - 1][j]) % M;
            }
            else
            {
                t[i][j] = t[i - 1][j];
            }
        }
    }

    return t[n][sum1];
}

int main(){
    vector<int> nums = {1, 1, 2, 3};
    int target = 1;

    cout << findTargetSumWays(nums, target) << endl;

    return 0;
}