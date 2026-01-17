#include <bits/stdc++.h>
using namespace std;

/**

* PS: Rod Cutting Problem
*
* Problem:
* Given a rod of length N and an array price[],
* where price[i] represents the value of a rod
* piece of length (i + 1), determine the maximum
* profit obtainable by cutting the rod.
*
* IP:
* * vector<int> price → prices for each rod length
*
* OP:
* * int → maximum obtainable profit
*
* APPROACH:
* Bottom-Up Dynamic Programming (Tabulation)
*
* TC:
* * O(n * n)
*
* SC:
* * O(n * n)
*
* VARIATION:
* * Unbounded Knapsack
*
* MAPPING (Rod Cutting → Unbounded Knapsack):
* * wt[]   → length[]
* * val[]  → price[]
* * W      → N (rod length)
*
* LEARNING:
* * Rod Cutting is conceptually identical to the Unbounded Knapsack problem.
* * An item (rod piece) can be chosen multiple times.
* * The DP transition remains on the same index when an item is picked, enabling reuse.
* * Understanding problem mapping makes complex* problems feel trivial.
* * Rod Cutting == Unbounded Knapsack 
* * Ganga dhar hi shakti maan hai 
*/


// Aliases 
using v = vector<int>; 
using vv = vector<v>; 

// Rod Cutting Problem 
int cutRod(v &price) {
    int n = price.size(); 

    // Step 1: Make length vector 
    v length(n, 0); 
    for(int i = 0; i < n; i++)
        length[i] = i + 1; 

    // Step 2: DP Table 
    vv t(n + 1, v(n + 1, 0)); // Initially, INIT with 0 
    
    // Step 3: Start filling, i = 1, j = 1
    for(int i = 1; i < n + 1; i++) {
        for(int j = 1; j < n + 1; j++) {
            if(length[i-1] <= j) {
                t[i][j] = max(
                    price[i-1] + t[i][j-length[i-1]], 
                    t[i-1][j]
                );
            } else {
                t[i][j] = t[i-1][j];
            }
        }
    }

    // Step 4: Return the final ans 
    return t[n][n];
}


int main() { 
    v price = {1, 5, 8, 9, 10, 17, 17, 20};

    cout << "MX Profit: " << cutRod(price) << endl; 

    return 0;
}