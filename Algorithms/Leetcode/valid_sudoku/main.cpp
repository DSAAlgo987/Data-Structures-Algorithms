/**
    Time complexity: O(1) -> Constant time 
    Space complexity: O(1) -> Constant time 
*/

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool rows[9][9] = {false}; 
        bool cols[9][9] = {false}; 
        bool boxes[9][9] = {false}; 

        // Iterate all over the grid 
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(board[i][j] != '.') {
                    // Convert char to int ('1' -> 0 why bcoz indexing starts from 0 to 8)
                    int num = board[i][j] - '1';
                    
                    // Compute box index 
                    int boxIdx = (i / 3) * 3 + (j / 3);

                    // If number repreated 
                    if(rows[i][num] || cols[j][num] || boxes[boxIdx][num]) {
                        return false;
                    }

                    // if not repeated 
                    rows[i][num] = cols[j][num] = boxes[boxIdx][num] = true;
                }
            }
        }

        return true; // No Repeatation of digits
    }
};