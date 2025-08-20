#include <bits/stdc++.h>
using namespace std;

// Brute force: O(n^6)
int solve(vector<vector<int>> &mat) {
    int rows = mat.size();
    int cols = mat[0].size();
    int count = 0;

    // Generate all the submatrices 
    for(int s_r = 0; s_r < rows; s_r++) {
        for(int s_c = 0; s_c < cols; s_c++) {
            for(int e_r = s_r; e_r < rows; e_r++) {
                for(int e_c = s_c; e_c < cols; e_c++) {
                    // If it is a square matrix 
                    if((e_r - s_r) == (e_c - s_c)) {
                        bool allOnes = true;
                        // Access cells 
                        for(int i = s_r; i <= e_r; i++) {
                            for(int j = s_c; j <= e_c; j++) {
                                if(mat[i][j] != 1){
                                    allOnes = false;
                                    break;
                                }
                            }
                        }

                        if(allOnes) {
                            count++;
                        }
                    }
                }
            }
        }
    }

    return count;
}

// Recursion approach: O(3^(m + n))
int solveRecursion(vector<vector<int>> &mat, int i, int j) {
    // Base conditions
    if(i < 0 || j < 0) {
        return 0;
    }
    if(mat[i][j] == 0) {
        return 0;
    }

    // if it is not equal to 0 then check for remaining cells 
    int up = solveRecursion(mat, i-1, j);
    int left = solveRecursion(mat, i, j-1);
    int diagonal = solveRecursion(mat, i-1, j-1);

    // return currentCell + min({up, left, diagonal})
    return 1 + min({up, left, diagonal});
}

// Memoized approach: O(m * n) + Recursive calls
vector<vector<int>> t; // declaration
int solveMemoize(vector<vector<int>> &mat, int i, int j) {
    // Base conditions
    if(i < 0 || j < 0) {
        return 0;
    }
    if(mat[i][j] == 0) {
        return 0;
    }

    // Preset in t ?
    if(t[i][j] != -1){
        return t[i][j];
    }

    // if it is not equal to 0 then check for remaining cells 
    int up = solveRecursion(mat, i-1, j);
    int left = solveRecursion(mat, i, j-1);
    int diagonal = solveRecursion(mat, i-1, j-1);

    // return currentCell + min({up, left, diagonal})
    return t[i][j] = 1 + min({up, left, diagonal});
}

// Tabular Approach: O(m * n)
int solveTabular(vector<vector<int>> &mat, int rows, int cols) {
    vector<vector<int>> t1(rows + 1, vector<int>(cols + 1, 0)); // Declaration
    int total = 0;
    // start filling sub problems 
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            // Current cell is == 1?
            if(mat[i][j] == 1){
                if(i == 0 || j == 0){
                    t1[i][j] = 1; // first row/col so only 1X1 sqaure is possible
                }else {
                    t1[i][j] = 1 + min({t1[i-1][j], t1[i][j-1], t1[i-1][j-1]});
                }
                total += t1[i][j];
            }
        }
    }
    return total;
}

int main(){
    vector<vector<int>> mat = {{1, 0}, {1, 1}};

    // cout << solve(mat) << endl; // OP: 3
    int rows = mat.size();
    int cols = mat[0].size();
    int total = 0;

    t.resize(rows + 1, vector<int>(cols+1, -1)); // Initialization with -1

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            total += solveMemoize(mat, i, j);
        }
    }
    cout << total << endl;

    cout << solveTabular(mat, rows, cols) << endl;
    return 0;
}