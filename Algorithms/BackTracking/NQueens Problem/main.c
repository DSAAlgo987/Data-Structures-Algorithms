#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX 10  // Maximum board size (you can change this based on needs)

char board[MAX][MAX];
char solutions[100][MAX][MAX]; // Stores up to 100 solutions
int solutionCount = 0;

bool isSafe(int row, int col, int n) {
    int r, c;

    // Check upward diagonal
    for (r = row, c = col; r >= 0 && c >= 0; r--, c--) {
        if (board[r][c] == 'Q') return false;
    }

    // Check left
    for (c = col; c >= 0; c--) {
        if (board[row][c] == 'Q') return false;
    }

    // Check downward diagonal
    for (r = row, c = col; r < n && c >= 0; r++, c--) {
        if (board[r][c] == 'Q') return false;
    }

    return true;
}

void copySolution(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            solutions[solutionCount][i][j] = board[i][j];
        }
    }
    solutionCount++;
}

void solve(int col, int n) {
    if (col == n) {
        copySolution(n);
        return;
    }

    for (int row = 0; row < n; row++) {
        if (isSafe(row, col, n)) {
            board[row][col] = 'Q';
            solve(col + 1, n);
            board[row][col] = '.';
        }
    }
}

int main() {
    int n = 4; // You can change the board size

    // Initialize board with '.'
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            board[i][j] = '.';
        }
    }

    solve(0, n);

    printf("Total Solutions: %d\n", solutionCount);
    for (int k = 0; k < solutionCount; k++) {
        printf("Solution %d:\n", k + 1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                printf("%c ", solutions[k][i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }

    return 0;
}
