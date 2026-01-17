#include <bits/stdc++.h>
using namespace std;

/**

* PS: Unbounded Knapsack
*
* Problem:
* Given weights and values of items, and a knapsack capacity W,
* determine the maximum profit when an item can be chosen
* unlimited number of times.
*
* IP:
* * vector<int> wt   → weights of items
* * vector<int> val  → values of items
* * int W            → knapsack capacity
*
* OP:
* * int → maximum achievable profit
*
* APPROACH:
* Bottom-Up Dynamic Programming (Tabulation)
*
* TC:
* * O(n * W)
*
* SC:
* * O(n * W)
*
* LEARNING:
* * Unlike 0/1 Knapsack, an item can be picked multiple times.
* * This is possible because we stay on the same item index
* after picking an item.
* * Key difference from 0/1 Knapsack lies in the DP transition:
* ```
   t[i][j] = max(val[i-1] + t[i][j - wt[i-1]], t[i-1][j])
  ```
* * Helps in understanding how small DP transition changes
* create entirely different problem behaviors.
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