#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Statement: Generate Pascal's Triangle by given no of rows.
 */

void printV(vector<vector<int>> vec){
    for(auto i: vec){
        for(auto j: i){
            cout << j << " ";
        }
        cout << endl;
    }
}

vector<vector<int>> generate(int numRows){
    // Step 1: Create a result 2d vector & size will numRows 
    vector<vector<int>> result(numRows);

    // Step 2: Start generating pascal's triangle 
    for(int i = 0; i < numRows; i++){
        // Step 2.1: fill col. with 1s initially 
        result[i] = vector<int>(i+1, 1);

        for(int j = 1; j < i; j++){
            // Step 2.2: Now fill pascal's values 
            result[i][j] = result[i-1][j] + result[i-1][j-1];
        }
    }
    // Step 3: Reutrn the result
    return result;
}

int main(){
    int n = 5;

    printV(generate(n));
    
    return 0;
}