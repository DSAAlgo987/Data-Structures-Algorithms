#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Statement: Return Min # of ways to form a coin.
 * 
 * Ip:
 * coins[]
 * sum
 * 
 * op:
 * Min # of ways 
 * 
 */

int coinChange(vector<int> &coins, int sum){
    int n = coins.size();
    vector<vector<int>> t(n + 1, vector<int>(sum + 1, 0)); // Declaration 

    // Initialization of first row as Infinity 
    for(int j = 0; j < sum + 1; j++){
        t[0][j] = INT_MAX - 1; 
    }

    // Initialization of second row 
    for(int j = 1; j < sum + 1; j++){
        if(j % coins[0] == 0){ // Divisible
            t[1][j] = j / coins[0];
        } else { // Not divisible
            t[1][j] = INT_MAX - 1;
        }
    }

    // Start filling inner parts, i -> n, j -> sum 
    for(int i = 2; i < n + 1; i++){
        for(int j = 1; j < sum + 1; j++){
            if(coins[i-1] <= j){
                t[i][j] = min(
                    t[i][j - coins[i-1]] + 1,
                    t[i-1][j]
                );
            }else {
                t[i][j] = t[i-1][j];
            }
        }
    }

    return t[n][sum] == INT_MAX - 1 ? -1 : t[n][sum];
}

int main(){
    vector<int> coins = {2};
    int sum = 11;

    cout << coinChange(coins, sum) << endl;
    
    return 0;
}