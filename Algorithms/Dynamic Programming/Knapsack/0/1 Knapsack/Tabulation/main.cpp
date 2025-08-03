#include <iostream>
#include <bits/stdc++.h>

using namespace std;
/*
    Constraints:
    n = 100;
    W = 1000;
*/

// Knapsack Time complexity: O(2^n)
int Knapsack(vector<int> &wt, vector<int> &val, int W, int n)
{
    // base condition
    if (n == 0 || W == 0)
    {
        return 0;
    }

    // choice diagram
    if (wt[n - 1] <= W)
    {
        int a = val[n - 1] + Knapsack(wt, val, W - wt[n - 1], n - 1);
        int b = Knapsack(wt, val, W, n - 1);
        return max(a, b);
    }
    return Knapsack(wt, val, W, n - 1);
}

int dp[102][1002];

// TC : O(n * W)
int knapsack(vector<int> &wt, vector<int> &val, int W, int n)
{
    // Initialize dp usig base case of recursion
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < W + 1; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
        }
    }

    // Start sovling knapsack problem
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < W + 1; j++)
        {
            if (wt[i - 1] <= j)
            {
                dp[i][j] = max(
                    val[i - 1] + dp[i - 1][j - wt[i - 1]], // Include
                    dp[i - 1][j]                           // Exclude
                );
            }
            else
            {
                dp[i][j] = dp[i - 1][j]; // Exclude
            }
        }
    }

    // Return Ans
    return dp[n][W];
}

int main()
{
    vector<int> wt = {1, 2, 4};
    vector<int> val = {1, 4, 5};
    int W = 6;

    cout << knapsack(wt, val, W, wt.size()) << endl;
    return 0;
}