#include <bits/stdc++.h>
using namespace std;

/**
 * Problem statement: Rod cutting problem 
 * 
 * ip : 
 * n -> length of the rod 
 * prices -> value of piece of length i
 * 
 * op : 
 * maximize profit 
 * 
 * This problem is ditto same as unbouded knapsack
 * *Rod cutting == unbouded Knapsack*
 * *Ganga Dhar hi shakti maan hai*
 */

int cutRod(vector<int> &price)
{
    int n = price.size();

    // First prepare length vector from 1 -> n
    vector<int> length(n);

    for (int i = 0; i < n; i++)
    {
        length[i] = i + 1;
    }

    vector<vector<int>> t(n + 1, vector<int>(n + 1, 0)); // Initialize with 0s

    // Now, start solving main parts: i -> price, j -> length of the rod
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            if (length[i - 1] <= j)
            {
                t[i][j] = max(
                    price[i - 1] + t[i][j - length[i - 1]], // Include
                    t[i - 1][j]                             // Exlcude
                );
            }
            else
            {
                t[i][j] = t[i - 1][j]; // Exclude
            }
        }
    }

    return t[n][n];
}

int main()
{
    vector<int> price = {1, 5, 8, 9, 10, 17, 17, 20};

    cout << cutRod(price) << endl; // op: 22
    return 0;
}