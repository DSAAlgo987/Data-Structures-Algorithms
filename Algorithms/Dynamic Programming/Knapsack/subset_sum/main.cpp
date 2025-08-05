#include <bits/stdc++.h>

using namespace std; 

/**
    PS: Check presence of sum in the given array. If yes -> TRUE, no -> FALSE 
    Constraints: 
    n = 100;
    sum = 1000;
*/

int t[102][1002]; // DP declaration 


// Bottom up approach 
bool sumSubset(vector<int> &arr, int sum){
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

int main(){
    vector<int> arr = {2, 3, 7, 8, 10};
    int sum = 11;

    cout << (sumSubset(arr, sum) ? "TRUE" : "FALSE") << endl;
    return 0;
}