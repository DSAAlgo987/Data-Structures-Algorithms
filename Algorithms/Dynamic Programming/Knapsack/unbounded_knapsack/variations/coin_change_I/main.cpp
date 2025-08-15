#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Coin change I (Max. # of ways)
 * 
 * ip: 
 * coin[]
 * sum 
 * 
 * op:
 * max. numbmer ways 
 * 
 * Why __uint128_t?
 * - Constraints allow very large counts:
 *      1 <= coins.length <= 300
 *      0 <= amount <= 5000
 * - Worst-case ways grow exponentially (long long overflows easily)
 * - __uint128_t safely handles up to ~3.4e38
 *
 * Complexity:
 * - Time: O(n * sum)
 * - Space: O(n * sum)
 *
 * Constraints:

    1 <= coins.length <= 300
    1 <= coins[i] <= 5000
    All the values of coins are unique.
    0 <= amount <= 5000
 */

int coinChange(vector<int> coin, int sum){
    using u128 = __uint128_t; // alias for 128-bit unsigned integer
    int n = coin.size();

    vector<vector<u128>> t(n + 1,
                               vector<u128>(amount + 1, 0)); // Declaration

    // Initialization 
    for(int i = 0; i < n + 1; i++){
        t[i][0] = 1; 
    }

    // Now, Start filling inner parts: i -> n, j -> sum
    for(int i = 1; i < n + 1; i++){
        for(int j = 1; j < sum + 1; j++){
            if(coin[i-1] <= j){
                t[i][j] = t[i][j - coin[i-1]] + t[i-1][j];
                // # of ways -> (+)
            }else { 
                t[i][j] = t[i-1][j];
            }
        }
    }

    return (int)t[n][sum];
}

int main(){
    vector<int> coin = {1, 2, 5};
    int sum = 11;

    cout << coinChange(coin, sum) << endl; // OP: 5
    
    return 0;
}