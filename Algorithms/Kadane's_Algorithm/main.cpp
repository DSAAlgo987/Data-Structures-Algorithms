#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// O(n^2)
void solve(vector<int> &arr){
    int i, j;
    int currentSum, length = 0;
    int mx = INT_MIN;
    
    for(i = 0; i < arr.size(); i++){
        currentSum = 0;
        for(j = i; j < arr.size(); j++){
            
            currentSum += arr[j];
            
            mx = max(mx, currentSum);
            length = max(length, j - i + 1);
        }
    }
    cout << mx << length << endl;
}
// O(n)
void kadane(vector<int> &arr){
    int i, currentSum = 0, mx = INT_MIN;
    int start = 0, end = 0, tempStart = 0;
    
    for(i = 0; i < arr.size(); i++){
        currentSum += arr[i];
        
        
        if(currentSum < 0){
            currentSum = 0;
            tempStart = i + 1;
        }
        if(currentSum > mx){
            mx = currentSum;
            start = tempStart;
            end = i;
        }
    }
    
    cout << mx << end - start + 1<< endl;
}

int main()
{
    vector<int> arr = {4 , -3, 4, 1, -4, 6};
    solve(arr);
    
    kadane(arr);
    return 0;
}