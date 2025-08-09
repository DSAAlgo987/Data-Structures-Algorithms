#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Count subset sum with given sum.
 * 
 * Constraint: 
 * n <= 100
 * sum <= 1000
 */

int t[102][1002]; // declaration

// Time complexity: O(n^2)
int countSubsetSum(vector<int> &arr, int sum){
    int n = arr.size();
    
    // Initialization 
    for(int i = 0; i < n + 1; i++){
        for(int j = 0; j < sum + 1; j++){
            if(i == 0){
                t[i][j] = 0; // false
            }
            
            if(j == 0){
                t[i][j] = 1; // true
            }
        }
    }

    // Start bottom up approach : i -> n, j -> sum
    for(int i = 1; i < n + 1; i++){
        for(int j = 1; j < sum + 1; j++){
            if(arr[i-1] <= j){
                t[i][j] = t[i-1][j - arr[i-1]]  // Include 
                                + 
                          t[i-1][j]; // Exclude 
            }
            else { 
                t[i][j] = t[i-1][j]; // Exclude 
            }
        }
    }

    return t[n][sum];
}

int main(){
    vector<int> arr = {2, 3, 5, 8, 10};
    int sum = 10;

    cout << countSubsetSum(arr, sum) << endl;
    
    return 0;
}