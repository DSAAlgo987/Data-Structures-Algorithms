class Solution {
public:
    // Time complexity: O(nlgn)
    void sortDiagonal(int row, int col, vector<vector<int>> &grid, bool asc) {
        int i = row;
        int j = col;
        int n = grid.size();

        vector<int> v;

        // Iterate over diagonal
        while(i < n && j < n) {
            v.push_back(grid[i][j]);
            i++;
            j++;
        }

        // Then perform sort as per given boolean
        if(asc) {
            sort(v.begin(), v.end()); // Sort ASC
        } else {
            sort(v.begin(), v.end(), greater<int>()); // Sort DESC
        }

        // Then again store back to the grid 
        i = row;
        j = col;

        for(auto &val: v) {
            grid[i][j] = val;
            i++; j++;
        }

    }

    // Time complexity: O(n^2 logn)
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        // Bottom Left 
        for(int row = 0; row < n; row++) {
            sortDiagonal(row, 0, grid, false); // Flase: Sort DESC
        }

        // Top Left 
        for(int col = 1; col < n; col++) {
            sortDiagonal(0, col, grid, true); // True: Sort ASC
        }

        return grid;
    }
};