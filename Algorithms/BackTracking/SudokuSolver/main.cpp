#include <bits/stdc++.h>
using namespace std;

/**
 * PS: Sudoku Solver (9 x 9 matrix) (1 indexed based)
 * IP: 9 x 9 matrix S with some empty and filled cells
 * OP: return S matrix with filled cells
 * BF: No should be unique in same row, col, and sub-BLK
 * APPROACH: Backtracking
 * NOTE: 0 -> empty cell 
 * TC: O(9^81) ~ O(1)
 * SC: O(81) ~ O(1) CONSTANT TIME 
 ** MOTIVATION: Don't Make Things Complicated  
 */

// Aliases
using v = vector<int>;
using vv = vector<v>;

// Global Variables: S matrix 
vv s = {
    {0,0,0,0,0,0,0,0,0,0},
    {0,5,3,0,0,7,0,0,0,0},
    {0,6,0,0,1,9,5,0,0,0},
    {0,0,9,8,0,0,0,0,6,0},
    {0,8,0,0,0,6,0,0,0,3},
    {0,4,0,0,8,0,3,0,0,1},
    {0,7,0,0,0,2,0,0,0,6},
    {0,0,6,0,0,0,0,2,8,0},
    {0,0,0,0,4,1,9,0,0,5},
    {0,0,0,0,0,8,0,0,7,9}
};

// Display Function 
void displayS(vv &s) {
    cout << "[" << endl;
    for(auto i: s) {
        cout << "   [ ";
        for(auto j: i) {
            cout << j << " ";
        }
        cout << "]," << endl;
    }
    cout << "]" << endl;
    cout << endl;
}

// Boudning Function 
bool isValid(int r, int c, int val) {
    // Same row 
    for(int j = 1; j <= 9; j++) if(s[r][j] == val) return false;

    // Same col 
    for(int i = 1; i <= 9; i++) if(s[i][c] == val) return false; 

    // Same sub-BLK 
    int bR = r - ((r-1) % 3);
    int bC = c - ((c-1) % 3);

    // Check 
    for(int i = 0; i < 3; i++) 
        for(int j = 0; j < 3; j++) 
            if(s[bR + i][bC + j] == val) return false; 

    // If all of above conditions false then we can place it safely
    return true; 
}


// Sudoku Solver Function 
void Sudoku(int r, int c) {
    // BC: Stop
    if(r == 10 && c == 1) {
        displayS(s);
        return;
    }
    else {
        // If it is not empty cell then just skip that cell 
        if(s[r][c] != 0) {
            // INC cell based on analysis 
            Sudoku(c == 9 ? r + 1: r, c == 9 ? 1: c + 1);
        }
        // If it is an empty cell 
        else {
            // Try out all valid values (1-9)
            for(int i = 1; i <= 9; i++) {
                // Before placing check bouding conditions/function
                if(isValid(r, c, i)) {
                    // Then place that iTh val to s[r][c]
                    s[r][c] = i;

                    // Again call for other cells 
                    Sudoku(c == 9 ? r + 1: r, c == 9 ? 1: c + 1);

                    // When it backtracks 
                    // make that cell as empty cell(0) again 
                    s[r][c] = 0;
                }
            }
        }
    }
}


int main(){

    Sudoku(1, 1);
    
    return 0;
}