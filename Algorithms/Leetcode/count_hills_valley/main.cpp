#include <bits/stdc++.h>
using namespace std;

// Optimal soln: TC: O(n) Sc: O(1)
int countHillValley(vector<int> &nums)
{
    int n = nums.size();

    // base case
    if (n <= 2)
    {
        return 0;
    }

    int count = 0;

    int i = 0, j = i + 1;

    while (j < n - 1)
    {
        // if hills
        if (nums[j] > nums[i] && nums[j] > nums[j + 1])
        {
            count++;
            // point i to j
            i = j;
        }
        // if valley
        else if (nums[j] < nums[i] && nums[j] < nums[j + 1])
        {
            count++;
            // point i to j
            i = j;
        }
        j++;
    }

    return count;
}

int main()
{

    vector<int> nums = {2, 4, 1, 1, 6, 5};

    cout << countHillValley(nums) << endl;

    return 0;
}