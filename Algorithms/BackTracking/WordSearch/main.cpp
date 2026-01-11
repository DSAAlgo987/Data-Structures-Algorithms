#include <bits/stdc++.h>
using namespace std;

/**
 * PS: Word Search
 * Problem: Find whether a given word exists in a board[m][n].
 *        The word can be constructed from adjacent cells
 *        (up, down, left, right). Diagonal traversal is NOT allowed.
 *
 * IP:
 *   - Board[m][n]
 *   - Word (string)
 *
 * OP:
 *   - True / False
 *
 * APPROACH:
 *   - Backtracking (DFS)
 *   - Mark cell as visited, explore all 4 directions,
 *     then backtrack by restoring the cell.
 *
 * TC:
 *   - O(m * n * 4^L)
 *     where L = length of the word
 *
 * SC:
 *   - O(L)  (recursion stack)
 *
 * LEARNING:
 *   - How to design proper boundary conditions
 *   - Handling boolean return values in backtracking
 *   - Importance of backtracking (mark & unmark visited cells)
 */

// Aliases
using  v = vector<char>;
using vv = vector<v>;

// GLobal Vars
int m = 3, n = 4;

vv board = {
    {'A','B','C','E'},
    {'S','F','C','S'},
    {'A','D','E','E'}
};

string word = "SEE";

// Word Search function 
bool solve(int i, int j, int p) {
    // BC 
    if(p == word.size()) {
        return true;
    }

    // Bouding conditions: !=, out of bound
    if(i < 0|| j < 0 ||i >= m || j >= n ||board[i][j] != word[p]) return false;

    else {
        char temp = board[i][j]; // Tracking 
        board[i][j] = '#';      // Visited 
        
        bool found = 
             solve(i, j + 1, p + 1) || // Right 

             solve(i + 1, j, p + 1) ||  // Down

             solve(i, j - 1, p + 1) ||  // Left 

             solve(i - 1, j, p + 1);     // Up

        // Backtrack: Visited -> unvisited
        board[i][j] = temp; 
        return found;
    }
}

int main() {
    bool ans = false; 
     // Main loop: Traverse Every Cells To 
     for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(solve(i, j, 0)) {
                ans = true;
            }
        }
     }

     cout << (ans ? "TRUE" : "FALSE") << endl;

    return 0;
}