#include <bits/stdc++.h>
using namespace std;

/**
 * In unbounded knapsack: Multiple instances of same item are allowed to put into the knapsack.
 * 
 * Ip: 
 * wt[], val[], W 
 * 
 * Op:
 * Max profit
 * 
 * Constraints: 
 * 1 <= n <= 100
 * 1 <= W <= 1000
 */

vector<vector<int>> t; // Dp declaration 

int unboundedKnapsack(vector<int> &wt, vector<int> &val, int W){
    int n = wt.size();

    t.assign(n+1, vector<int>(W + 1, 0)); // Assign size & Initilize with all 0s

    // Start bottom up approach : i -> n, j -> W 
    for(int i = 1; i < n + 1; i++){
        for(int j = 1; j < W + 1; j++){
            if(wt[i-1] <= j){
                t[i][j] = max(
                    val[i-1] + t[i][j - wt[i - 1]], // Include 
                    t[i-1][j]   // Exclude 
                );

                /**
                 * Only change we did:
                 * t[i-1] -> t[i] (In include)  
                 */
            }else {
                t[i][j] = t[i-1][j]; // Exclude 
            }
        }
    }

    return t[n][W];
}


int main(){
    vector<int> wt = {3, 4, 3};
    vector<int> val = {7, 8, 9};
    int W = 7; 

    cout << unboundedKnapsack(wt, val, W) << endl;

    return 0;
}