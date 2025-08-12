#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: ways to express an integer as sum of powers.
 * It is a variation of *Count Of Subset Sum*.
 */

// Time Complexity: O(m * n)
class Solution {
public:
    int M = 1e9 + 7; // 10^9 + 7
    int numberOfWays(int n, int x) {
        // Generate powers vector 
        vector<int> powers;

        for(int base = 1; pow(base, x) <= n; base++){
            // Store base with power
            powers.push_back((int)pow(base,x));
        }

        int m = powers.size();
        vector<vector<int>> t(m + 1, vector<int>(n+1, 0)); // Declaration 

        // Initialization : when sum = 0
        for(int i = 0; i < m + 1; i++){
            t[i][0] = 1; // One way to make sum = 0;
        }

        // Now, start filling the inner cells : m -> i, n -> j
        for(int i = 1; i < m + 1; i++){
            for(int j = 1; j < n + 1; j++){
                if(powers[i-1] <= j){
                    t[i][j] = (t[i-1][j - powers[i-1]] + t[i-1][j]) % M;
                }else {
                    t[i][j] = t[i-1][j];
                }
            }   
        }

        return t[m][n];
    }
};

int main(){
    Solution soln;

    cout << soln.numberOfWays(4, 1) << endl;
    return 0;
}