#include <bits/stdc++.h>

using namespace std;

/**
 * Problem: Min Subset sum difference 
 * Constraint:
 * 1 <= n <= 100
 */

int t[102][1002]; // Declaration 

void subsetSum(vector<int> &arr, int range){
    int n = arr.size();
    // Initialization   
    for(int i = 0; i < n + 1; i++){
        for(int j = 0; j < range + 1; j++){
            if(i == 0){
                t[i][j] = false;
            }
            if(j == 0){
                t[i][j] = true;
            }
        }
    }

    // Now, start filling the main part : i -> n, j->sum
    for(int i = 1; i < n + 1; i++){
        for(int j = 1; j < range + 1; j++){
            if(arr[i-1] <= j){
                t[i][j] = t[i-1][j - arr[i-1]] || t[i-1][j];
            }else {
                t[i][j] = t[i-1][j];
            }
        }
    }

    
}

int minSubsetSum(vector<int> &arr){
    // Step 1: caculate range 
    int range = 0;
    int n = arr.size();
    for(int i = 0; i < n; i++){
        range += arr[i];
    }

    // Step 2: call subset function
    subsetSum(arr, range);

    // Step 3: filter nth row from dp table to range / 2 & store in s1 vector
    vector<int> s1;
    for(int j = n; j < range / 2; j++){
        if(t[n][j] == true){
            s1.push_back(j);
        }
    }

    // Step 4: now apply formula to find min subset differnce (range - 2S1[i])
    int mn = INT_MAX;
    for(int i = 0; i < range / 2; i++){
        mn = min(mn, range - 2 * s1[i]);
    }

    return mn;
}

int main(){
    vector<int> arr = {1, 2, 7};

    cout << minSubsetSum(arr) << endl; // op: 4
    return 0;
}