#include <bits/stdc++.h>
using namespace std;

// Brute force -> n^2
int findMaxLengthBruteForce(vector<int> &nums)
{
    int n = nums.size();
    int mx = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        int zeroCount = 0, oneCount = 0;
        for (int j = i; j < n; j++)
        {
            if (nums[j] == 0)
            {
                zeroCount++;
            }
            else
            {
                oneCount++;
            }

            // Check they are equal
            if (zeroCount == oneCount)
            {
                mx = max(j - i + 1, mx);
            }
        }
    }

    return (mx == INT_MIN) ? 0 : mx;
}

// Optimal -> n
int findMaxLength(vector<int> &nums)
{
    int n = nums.size();

    // Step 1: Convert 0 -> -1
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == 0)
            nums[i] = -1;
    }

    // Step 2: calulcate prefix sum, maintain map & mx length
    int sum = 0;
    unordered_map<int, int> mp; // mp<sum, pos>
    mp[0] = -1;                 // sum : 0, pos : -1
    int mx = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        sum += nums[i]; // calculate prefix sum

        // Present in mp
        if (mp.find(sum) != mp.end())
        {
            // Calulate max length
            mx = max(i - mp[sum], mx);
        }
        else
        { // not present
            // Store in mp : sum with pos
            mp[sum] = i;
        }
    }

    return (mx == INT_MIN) ? 0 : mx;
}

int main()
{
    vector<int> nums = {0, 1, 1, 1, 0, 0,0};

    cout << findMaxLength(nums) << endl;
    return 0;
}