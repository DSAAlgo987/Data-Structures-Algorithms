//Approach (Just find the minRow, maxRow, minCol and maxCol where we see 1)
//T.C : O(m * m)
//S.C : O(1)
class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int m = grid.size(); //Rows
        int n = grid[0].size(); //Columns

        int minRow = m;
        int maxRow = -1;
        int minCol = n;
        int maxCol = -1;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
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
};