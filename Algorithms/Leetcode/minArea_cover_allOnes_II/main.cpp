//Approach (Trying all possible splits and rotating grid to cover other posisble splits as well)
//T.C : O(m^2 * n^2)
//S.C : O(m*n) for rotated matrix
class Solution {
public:
    int minArea(int startRow, int endRow, int startCol, int endCol, vector<vector<int>>& grid) {
        int m = grid.size(); //Rows
        int n = grid[0].size(); //Columns

        int minRow = m;
        int maxRow = -1;
        int minCol = n;
        int maxCol = -1;

        for(int i = startRow; i < endRow; i++) {
            for(int j = startCol; j < endCol; j++) {
                if(grid[i][j] == 1) {
                    minRow = min(minRow, i);
                    maxRow = max(maxRow, i);

                    minCol = min(minCol, j);
                    maxCol = max(maxCol, j);
                }       
            }
        }
        return (maxRow - minRow + 1) * (maxCol - minCol + 1);
    }

    vector<vector<int>> rotateClockwise(vector<vector<int>> &grid) { 
        int m = grid.size();
        int n = grid[0].size();

        // Now rotate grid and store in rotated grid 
        // When we rotate the matrix dimension change m x n -> n x m
        vector<vector<int>> rotatedGrid(n, vector<int>(m, 0));

        for(int i = 0; i < m; i++) { 
            for(int j = 0; j < n; j++) {
                rotatedGrid[j][m - i - 1] = grid[i][j];
            }
        }

        return rotatedGrid;
    }

    // O(n^2 * n^2)
    int utility(vector<vector<int>> &grid) {
        int m = grid.size();
        int n = grid[0].size();

        int res = INT_MAX;

        // Case 1: 
        for(int r_s = 1; r_s < m; r_s++) {
            for(int c_s = 1; c_s < n; c_s++) {
                int top = minArea(0, r_s, 0, n, grid);
                int bottomLeft = minArea(r_s, m, 0, c_s, grid);
                int bottomRight = minArea(r_s, m, c_s, n, grid);


                res = min(res, top + bottomLeft + bottomRight);
            }
        }

        // Case 2: 
        for(int r_s = 1; r_s < m; r_s++) {
            for(int c_s = 1; c_s < n; c_s++) {
                int topLeft = minArea(0, r_s, 0, c_s, grid);
                int topRight = minArea(0, r_s, c_s, n, grid);
                int bottomRight = minArea(r_s, m, 0, n, grid);


                res = min(res, topLeft + topRight + bottomRight);
            }
        }
        // Case 3: 
        for(int r_s1 = 1; r_s1 < m; r_s1++) {
            for(int r_s2 = r_s1 + 1; r_s2 < m; r_s2++) {
                int top = minArea(0, r_s1, 0, n, grid);
                int middle = minArea(r_s1, r_s2, 0, n, grid);
                int bottom = minArea(r_s2, m, 0, n, grid);


                res = min(res, top + middle + bottom);
            }
        }
        return res;
    }   

    int minimumSum(vector<vector<int>>& grid) {
        int result = utility(grid);

        vector<vector<int>> rotatedGrid = rotateClockwise(grid);

        result = min(result, utility(rotatedGrid));

        return result;
    }
};