#include <bits/stdc++.h>
using namespace std;

void printV(vector<vector<int>> &matrix){
    for(auto i: matrix){
        for(auto j: i){
            cout << j << " ";
        }
        cout << endl;
    }
}

// Brute Force -> m*n*k^2
vector<vector<int>> solve(vector<vector<int>> &matrix, int k){
    int m = matrix.size(); // rows
    int n = matrix[0].size(); // cols 

    vector<vector<int>> ans(m, vector<int>(n, 0)); // Initialize ans with matirx(m,n)
    
    for(int i = 0; i < m; i++){ // m
        for(int j = 0; j < n; j++){ // m.n
            int sum = 0;
            for(int r = max(0, i - k); r < min(m, i + k + 1); r++){ // r -> k
                for(int c = max(0, j - k); c < min(n, j + k + 1); c++){// c-> k.k = k^2
                    // Calculate sum as per the range
                    sum += matrix[r][c];
                }
            }
            // Store sum at [i,j] position
            ans[i][j] = sum;
        }
    }

    return ans;
}

// Optimal -> n^2
vector<vector<int>> matrixBlockSum(vector<vector<int>> &matrix, int k){
    int m = matrix.size(); // rows
    int n = matrix[0].size(); // cols 

    vector<vector<int>> prefixSum(m+1, vector<int>(n+1, 0)); // 1-indexed based

    // Start calculate 2D prefix Sum 
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            prefixSum[i][j] = matrix[i-1][j-1] 
                            + prefixSum[i-1][j] 
                            + prefixSum[i][j-1] 
                            - prefixSum[i-1][j-1];

        }
    }

    vector<vector<int>> ans(m, vector<int>(n, 0)); // Initialize ans with matirx(m,n)

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            // Identify ranges
            int r1 = max(0, i - k);
            int r2 = min(m - 1, i + k);
            int c1 = max(0, j - k);
            int c2 = min(n - 1, j + k);

            // store ans as per the specified range, +1 offset bcoz 1-indexed based
            ans[i][j] = prefixSum[r2 + 1][c2 + 1]
                        - prefixSum[r1][c2 + 1]
                        - prefixSum[r2 + 1][c1]
                        + prefixSum[r1][c1];
        }
    }
    

    return ans;
}


int main(){
    vector<vector<int>> matrix = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    int k = 1;

    vector<vector<int>> ans = matrixBlockSum(matrix, k);

    printV(ans);
    
    return 0;
}