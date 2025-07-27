#include <bits/stdc++.h>
using namespace std;

// optimized -> n
int findMiddleIndex(vector<int> &nums)
{
    int n = nums.size();

    int leftSum = 0;
    int rightSum = 0;

    // Calculate total sum
    for (auto n : nums)
    {
        rightSum += n;
    }

    // Start finding middle index
    for (int i = 0; i < n; i++)
    {
        // Remove ith calculation from rightSum
        rightSum -= nums[i];

        // Compare left & rightSum
        if (leftSum == rightSum)
        {
            return i; // middleIndex
        }

        // then add ith element in leftSum
        leftSum += nums[i];
    }

    return -1;
}

int main()
{
    vector<int> nums = {2,3,-1,8,4};

    cout << findMiddleIndex(nums) << endl;
    return 0;
}