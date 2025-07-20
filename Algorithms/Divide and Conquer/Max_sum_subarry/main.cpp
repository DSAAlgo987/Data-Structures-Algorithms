#include <bits/stdc++.h>
using namespace std;

int currentSum = 0;
int solve(vector<int> &arr, int low, int high){
    // BC: One Element 
    if(low == high){
        return arr[high];
    }
    // BC: Two elements
    else if(low == high - 1){
        return arr[low] + arr[high];
    }
    else {
        // Divide based on the middle 
        int mid = (low + high) / 2;

        // Left sub-tree
        currentSum = solve(arr, low, mid);
        currentSum = solve(arr, mid + 1, high);
    }

    return currentSum;
}

int main(){
    vector<int> arr = {4, -3, 4, 1, -4, 6};

    int ans = solve(arr, 0, arr.size()-1);

    cout << ans << endl;
    return 0;
}