#include <bits/stdc++.h>
using namespace std;

/**
 * PS: 
 * Given an array of positive integers nums and a positive integer target, return the minimal length of a subarray whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.
 */

int minSubArrayLen(int target, vector<int> &nums)
{
    int i = 0, j = 0, mn = INT_MAX, sum = 0;

    while (j < nums.size())
    {
        // calculation
        sum += nums[j];

        if (sum < target)
        {
            j++;
        }
        else if (sum == target)
        {
            // ans <- calculation
            mn = min(mn, j - i + 1);
            j++;
        }
        else if (sum > target)
        {
            while (sum > target)
            {
                // remove ith calc
                mn = min(mn, j - i + 1);
                sum -= nums[i];
                i++;
            }

            if (sum == target)
            {
                mn = min(mn, j - i + 1);
            }

            j++;
        }
    }
    return (mn == INT_MAX) ? 0 : mn;
}

int main()
{
    vector<int> nums = {2, 3, 1, 2, 4, 3};
    int target = 7;

    cout << minSubArrayLen(target, nums);
    return 0;
}