#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Count no. of subsets with given difference.
 * This question is related with count of subset sum.
 *
 * Constraints:
 * 1 <= n <= 100
 */

/*
    REASON 1:
    Pehle hum first column ko 1 se initialise kar rahe the, 
    yeh assume karke ki sirf ek hi tarika hai subset sum = 0 banane ka,
    jo hai empty subset {}.
    Lekin agar array me 0 present hai, 
    toh subsets banenge: {} aur {0}, dono ka sum 0 hoga.
    Matlab ek se zyada tarike ho sakte hain sum==0 banane ke.
    FIX:
    -> First column ko har row me 1 initialise mat karo.
    -> Poora table 0 se initialise karo, sirf dp[0][0] = 1 hoga.
    -> Aur 'j' ka loop 0 se start hoga, 1 se nahi.
*/

/*
    REASON 2:
    Hum target formula use karte hain: target = (diff + totalSum) / 2
    Lekin yeh tabhi kaam karega jab (diff + totalSum) even hoga,
    kyunki tabhi target ek whole number banega.
    Agar odd hai, toh target fractional hoga jo possible nahi hai.
*/

int dp[102][1002]; // Declaration
int M = 1e9 + 7; // 10^9 + 7

// Time complexity: O(n^2)
int countSubsetsDiff(int n, int d, vector<int> &arr)
{
    int sum = 0;
    for (auto i : arr)
        sum += i;
    if ((d + sum) % 2 != 0)
        return 0;
    int t = (d + sum) / 2;
    // REDUCED: find count of subset with sum equal to t
    vector<vector<int>> dp(n + 1, vector<int>(t + 1, 0));
    dp[0][0] = 1;
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 0; j < t + 1; j++)
        {
            if (arr[i - 1] <= j)
                dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - arr[i - 1]]) % M;
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][t];
}

int main()
{
    vector<int> arr = {0, 1, 2, 2, 2, 3, 0, 3, 0, 1};
    int diff = 12;

    cout << "Final count: " << countSubsetsDiff(arr.size(), diff, arr) << endl;

    return 0;
}