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

vector<vector<int>> t;
int M = 1e9 + 7;

int countSubsetsDiff(vector<int> &arr, int d)
{
    // Code here
    int n = arr.size();

    int sumOfArr = 0;
    // First caculate whole array's sum
    for (auto i : arr)
    {
        sumOfArr += i;
    }

    // Check feasibility: if odd or d is greater than sum of arr.
    if ((d + sumOfArr) % 2 != 0 || d > sumOfArr)
        return 0;

    // Calculate sum1 using the formula:
    int sum1 = (d + sumOfArr) / 2;

    t.assign(n + 1, vector<int>(sum1 + 1, 0)); // Initialize with all 0s

    t[0][0] = 1;
    // Start filling remaining parts : n -> i, sum -> j
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 0; j < sum1 + 1; j++)
        {
            if (arr[i - 1] <= j)
            {
                t[i][j] = (t[i - 1][j - arr[i - 1]] + t[i - 1][j]) % M;
            }
            else
            {
                t[i][j] = t[i - 1][j];
            }
        }
    }

    return t[n][sum1];
}

int main()
{
    vector<int> arr = {0, 1, 2, 2, 2, 3, 0, 3, 0, 1};
    int diff = 12;

    cout << "Final count: " << countSubsetsDiff(arr, diff) << endl;

    return 0;
}