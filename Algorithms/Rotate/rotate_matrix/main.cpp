#include <bits/stdc++.h>
using namespace std;

/**
 * Problem statement: we have n x n matrix we have to rotate matrix clockwise
 * 
 * ip:
 * matrix(n, n) 
 * 
 * op:
 * rotatedMatrix(n,n)
 */

void displayMatrix(vector<vector<int>> &matrix) {
    int n = matrix.size();

    for(int i = 0; i < n; i++) { 
        for(int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;
}

// Brute Force: TC: O(n^2) SC: O(n^2) 
vector<vector<int>> rotateClockwiseBruteForce(vector<vector<int>> &matrix) {
    int n = matrix.size();

    vector<vector<int>> rotatedMatrix(n, vector<int>(n,0));

    for(int i = 0; i < n; i++) {
        for(int j = 0;j < n; j++) {
            rotatedMatrix[j][n-i-1] = matrix[i][j];
        }
    }

    return rotatedMatrix;
}

// Transpose approach: TC: O(n^2) SC: O(1)
vector<vector<int>> rotateClockwise(vector<vector<int>> &matrix) { 
    int n = matrix.size();

    // Perform tranpose(row -> col) 
    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    // Reverse each row 
    for(int i = 0; i < n; i++) 
        reverse(matrix[i].begin(), matrix[i].end());

    return matrix;
}

int main(){

    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    matrix = rotateClockwiseBruteForce(matrix);

    displayMatrix(matrix);

    matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    matrix = rotateClockwise(matrix);
    displayMatrix(matrix);
    return 0;
}