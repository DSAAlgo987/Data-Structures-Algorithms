#include <bits/stdc++.h>
using namespace std;

/**
 * It is a variation of count subArray sum equals k.
 * 
 * Problem: Count sub matrices sum equals target. 
 */

// Brute Force -> n^6 
int solve(vector<vector<int>> &matrix, int target){
    int count = 0;
    int m = matrix.size();
    int n = matrix[0].size();

    // Starting row 
    for(int s_r = 0; s_r < m; s_r++){
        // Starting col 
        for(int s_c = 0; s_c < n; s_c++){
            // Ending row 
            for(int e_r = s_r; e_r < m; e_r++){
                // Ending col 
                for(int e_c = s_c; e_c < n; e_c++){
                    int sum = 0; 
                    // Caculate sum of sub matrices 
                    for(int i = s_r; i <= e_r; i++){
                        for(int j = s_c; j <= e_c; j++){
                            sum += matrix[i][j];
                        }
                    }

                    // if sum equals target 
                    if(sum == target){
                        count++; // INC count
                    }
                }
            }
        }
    }

    // Return count 
    return count;
}

// Optimal -> O(n².m)
int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target){
    int m = matrix.size();
    int n = matrix[0].size();
    int count = 0;

    // Step 1: Prefix sum row-wise
    for (int row = 0; row < m; row++) {
        for (int col = 1; col < n; col++) {
            matrix[row][col] += matrix[row][col - 1];
        }
    }

    // Step 2: Fix two columns and compress rows
    for (int left = 0; left < n; left++) {
        for (int right = left; right < n; right++) {
            unordered_map<int, int> prefixSumFreq;
            prefixSumFreq[0] = 1;

            int currSum = 0;

            for (int row = 0; row < m; row++) {
                int sum = matrix[row][right];
                if (left > 0) sum -= matrix[row][left - 1];

                currSum += sum;

                if (prefixSumFreq.find(currSum - target) != prefixSumFreq.end()) {
                    count += prefixSumFreq[currSum - target];
                }

                prefixSumFreq[currSum]++;
            }
        }
    }

    return count;
}

int main(){
    vector<vector<int>> matrix = {
        {0,1,0},
        {1,1,1},
        {0,1,0}
    };

    int target = 0;

    cout << numSubmatrixSumTarget(matrix, target);
    return 0;
}