#include <bits/stdc++.h>
using namespace std;

// Brute force: n^6
int numSubmat(vector<vector<int>> &mat) {
    int rows = mat.size();
    int cols = mat[0].size();

    int count = 0;

    for(int s_r = 0; s_r < rows; s_r++) {
        for(int s_c = 0; s_c < cols; s_c++) {
            for(int e_r = s_r; e_r < rows; e_r++) {
                for(int e_c = s_c; e_c < cols; e_c++) {
                    // Check all ones ?
                    bool allOnes = true;

                    for(int i = s_r; i <= e_r; i++) {
                        for(int j = s_c; j <= e_c; j++) {
                            if(mat[i][j] != 1) {
                                allOnes = false;
                                break;
                            }
                        }
                    }

                    // if true 
                    if(allOnes) {
                        count++;
                    }
                }
            }
        }
    }

    return count;
}

// Better Approach: O(n^3)
class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> newmat(n, vector<int>(m, 0));

        // Precompute consecutive ones to the right
        for (int i = 0; i < n; i++) {
            newmat[i][m-1] = mat[i][m-1] == 0 ? 0 : 1;
            for (int j = m-2; j >= 0; j--) {
                newmat[i][j] = mat[i][j] == 0 ? 0 : newmat[i][j+1] + 1;
            }
        }

        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int minwidth = newmat[i][j];
                for (int d = i; d < n; d++) {
                    if (newmat[d][j] == 0) break;
                    minwidth = min(minwidth, newmat[d][j]);
                    count += minwidth;
                }
            }
        }
        return count;
    }
};


int main(){
    vector<vector<int>> mat = {{1,1}, {1,1}};

    cout << numSubmat(mat) << endl;
    return 0;
}