#include <bits/stdc++.h>
using namespace std;

// Time complexity: O(n^2)
int maxProduct(int n)
{
    // cut array = {1,2,...,n-1}
    vector<int> cut(n - 1);
    for (int i = 0; i < n - 1; i++)
        cut[i] = i + 1;

    vector<vector<int>> t(n - 1, vector<int>(n + 1, 0));

    // initialize first row (only cut=1 allowed)
    for (int j = 0; j <= n; j++)
    {
        t[0][j] = 1;
    }

    // now, start filling remaining cells: i -> cut, j -> n
    for (int i = 1; i < n - 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            if (cut[i - 1] <= j)
            {
                int take = cut[i] * max(j - cut[i], t[i][j - cut[i]]);
                t[i][j] = max(
                    take,
                    t[i - 1][j]);
            }
            else
            {
                t[i][j] = t[i - 1][j];
            }
        }
    }

    return t[n - 2][n]; // last row, col=n
}

int main(){
    int n = 5;

    cout << maxProduct(n) << endl;
    return 0;
}
