#include <bits/stdc++.h>
using namespace std;

// Brute force -> n^2
int solve(vector<int> &nums, int k)
{
    int count = 0, n = nums.size();

    // Step 1: Generate all possible subArrs
    for (int i = 0; i < n; i++)
    {
        int sum = 0;

        for (int j = i; j < n; j++)
        {
            sum += nums[j]; // calculate sum for each subArr

            if (sum == k)
            { // sum == k then increment count
                count++;
            }
        }
    }

    return count;
}

// Optimal -> n
int subarraySum(vector<int> &nums, int k)
{
    int count = 0, sum = 0;

    unordered_map<int, int> mp; // <sum, count>

    mp[0] = 1;

    // Start calculating prefix sum & count
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i]; // calculate sum

        // present sum - k -> map
        if (mp.find(sum - k) != mp.end())
        {
            count += mp[sum - k]; // INC count
        }

        mp[sum]++; // store sum with freq
    }
    return count;
}

int main()
{
    vector<int> nums = {1, 2, 3};
    int k = 3;

    cout << subarraySum(nums, k) << endl;

    return 0;
}