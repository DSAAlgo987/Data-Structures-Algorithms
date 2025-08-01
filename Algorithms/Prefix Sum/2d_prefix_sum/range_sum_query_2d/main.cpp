#include <iostream>
#include <vector>
using namespace std;

/*
  -------------------------------------------------------
  🔷 Category: 2D Prefix Sum | Range Sum Query 2D
  📌 Problem: LeetCode 304 - Range Sum Query 2D: Immutable

  🧠 Goal:
     - Preprocess a 2D matrix so that we can find the sum 
       of any submatrix in O(1) time.

  ⏱️ Time Complexity:
     - Constructor: O(n * m)  -> to build prefixSum
     - sumRegion:   O(1)      -> constant time query

  📐 Formula (1-based indexing):
     prefixSum[i][j] = matrix[i-1][j-1] 
                       + prefixSum[i-1][j] 
                       + prefixSum[i][j-1] 
                       - prefixSum[i-1][j-1];

  ✅ sumRegion(row1, col1, row2, col2):
     Returns sum of submatrix from (row1,col1) to (row2,col2)
     = prefixSum[row2+1][col2+1]
       - prefixSum[row1][col2+1]
       - prefixSum[row2+1][col1]
       + prefixSum[row1][col1];
  -------------------------------------------------------
*/

class NumMatrix {
    vector<vector<int>> prefixSum;

public:
    NumMatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        // Resize and initialize prefixSum with 0s
        prefixSum.resize(rows + 1, vector<int>(cols + 1, 0));

        // Build 2D prefix sum (1-based indexing)
        for(int i = 1; i <= rows; ++i) {
            for(int j = 1; j <= cols; ++j) {
                prefixSum[i][j] = matrix[i-1][j-1]
                                + prefixSum[i-1][j]
                                + prefixSum[i][j-1]
                                - prefixSum[i-1][j-1];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return prefixSum[row2 + 1][col2 + 1]
             - prefixSum[row1][col2 + 1]
             - prefixSum[row2 + 1][col1]
             + prefixSum[row1][col1];
    }
};

int main() {
    vector<vector<int>> matrix = {
        {3, 0, 1, 4, 2},
        {5, 6, 3, 2, 1},
        {1, 2, 0, 1, 5},
        {4, 1, 0, 1, 7},
        {1, 0, 3, 0, 5}
    };

    NumMatrix obj(matrix);

    // Sample Queries
    cout << "Sum from (2,1) to (4,3): " << obj.sumRegion(2, 1, 4, 3) << endl; // Output: 8
    cout << "Sum from (1,1) to (2,2): " << obj.sumRegion(1, 1, 2, 2) << endl; // Output: 11
    cout << "Sum from (1,2) to (2,4): " << obj.sumRegion(1, 2, 2, 4) << endl; // Output: 12

    return 0;
}
