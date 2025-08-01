#include <bits/stdc++.h>
using namespace std;

/**
 * 1. 2D Prefix Sum is used to apply on matrix.
 * 2. This will be a 1 based indexing matrix.
 * 3. Formula:
 *  PS[i, j] = PS[i, j-1] + PS[i-1, j] + matrix[i-1, j-1] - PS[i-1, j-1];
 */

void printV(vector<vector<int>> &matrix)
{
    for (auto i : matrix)
    {
        for (auto j : i)
        {
            printf("%2d ", j);
        }
        cout << endl;
    }
}

void twoDPrefixSum(vector<vector<int>> &matrix)
{
    int rows = matrix.size();
    int cols = matrix[0].size();

    // 1 - based indexing : initialize all elements with 0 initially
    vector<vector<int>> prefixSum(rows + 1, vector<int>(cols + 1, 0)); // (rows + 1, cols + 1)

    // Start calculating prefix sum
    for (int i = 1; i <= rows; i++)
    {
        for (int j = 1; j <= cols; j++)
        {
            // Formula:
            prefixSum[i][j] = matrix[i - 1][j - 1] + prefixSum[i - 1][j] + prefixSum[i][j - 1] - prefixSum[i - 1][j - 1];
        }
    }

    printV(prefixSum);
}

int main()
{
    vector<vector<int>> matrix = {
        {3, 0, 1, 4, 2},
        {5, 6, 3, 2, 1},
        {1, 2, 0, 1, 5},
        {4, 1, 0, 1, 7},
        {1, 0, 3, 0, 5}};

    twoDPrefixSum(matrix);

    return 0;
}