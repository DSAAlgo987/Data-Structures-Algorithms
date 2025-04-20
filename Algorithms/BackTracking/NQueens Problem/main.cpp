#include <bits/stdc++.h>
using namespace std;

bool isSafe(int row, int col, vector<string> &board, int n) {
    int dupRow = row;
    int dupCol = col;

    // Check upper diagonal
    while (row >= 0 && col >= 0) {
        if (board[row][col] == 'Q') return false;
        row--;
        col--;
    }

    // Check left
    col = dupCol;
    row = dupRow;
    while (col >= 0) {
        if (board[row][col] == 'Q') return false;
        col--;
    }

    // Check lower diagonal
    row = dupRow;
    col = dupCol;
    while (row < n && col >= 0) {
        if (board[row][col] == 'Q') return false;
        row++;
        col--;
    }

    return true;
}

void solve(int col, vector<string> &board, vector<vector<string>> &ans, int n) {
    if (col == n) {
        ans.push_back(board);
        return;
    }

    for (int row = 0; row < n; row++) {
        if (isSafe(row, col, board, n)) {
            board[row][col] = 'Q';
            solve(col + 1, board, ans, n);
            board[row][col] = '.';
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> ans;
    vector<string> board(n, string(n, '.'));

    solve(0, board, ans, n);
    return ans;
}

int main() {
    int n = 4;
    vector<vector<string>> ans = solveNQueens(n);

    for (auto &solution : ans) {
        for (auto &row : solution) {
            cout << row << endl;
        }
        cout << endl;
    }

    return 0;
}
