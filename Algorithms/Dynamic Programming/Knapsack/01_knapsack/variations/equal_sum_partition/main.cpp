#include <bits/stdc++.h>
using namespace std;

/**
 * Constraints: 
 * n = 100
 * sum = 1000
 */

bool t[102][1002]; // Declaration 


// Bottom up approach 
bool subsetSum(vector<int> &arr, int sum){
    int n = arr.size();

    // Intilize dp 
    for(int i = 0; i < n + 1; i++){
        for(int j = 0; j < sum + 1; j++){
            if(i == 0){
                t[i][j] = false;
            }

            if(j == 0){
                t[i][j] = true;
            }
        }
    }

    // Start tabular method : n -> i, sum -> j
    for(int i = 1; i < n + 1; i++){
        for(int j = 1; j < sum + 1; j++){
            // if current element <= sum 
            if(arr[i-1] <= j){
                t[i][j] = t[i-1][j-arr[i-1]] // Include 
                          || 
                          t[i-1][j]; // Exclude 
            }
            else { 
                t[i][j] = t[i-1][j]; // Exclude 
            }
        }
    }

    // Return ans: T/F
    return t[n][sum];
}

// Time complexity: O(n * sum)
bool equalSumPartition(vector<int> &arr){
    int n = arr.size();
    int sum = 0;

    // Calculate sum 
    for(int i = 0; i < n; i++){
        sum += arr[i];
    }

    // if odd 
    if(sum % 2 != 0){
        return false;
    }

    // if even : sum = 22 / 2 = (11)
    return subsetSum(arr, sum / 2);
}

int main(){
    vector<int> arr = {1,2,5};

    cout << (equalSumPartition(arr) ? "TRUE" : "FALSE") << endl;
    return 0;
}