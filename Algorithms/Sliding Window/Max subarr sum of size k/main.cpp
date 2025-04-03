/* Problem Statement: 
Maximum Sum Subarray of Size K
Given an integer array arr of size n and an integer k, find the maximum sum of any contiguous subarray of size k.
*/

#include <bits/stdc++.h>
using namespace std;

void maxSumSubarray(int arr[], int n, int k){
    int i = 0, j = 0;
    int sum = 0; 
    int mx = INT_MIN;
    while(j < n){
        sum += arr[j];
        // Achieve window size 
        if((j - i + 1) < k){
            j++;
        }else if((j - i + 1) == k){ // Maintain window size
            mx = max(mx, sum);
            sum -= arr[i];
            i++;
            j++;
        }
    }

    cout << mx << endl;
} 

int main(){
    int n, k;
    cin >> n >> k;

    int arr[n];

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    maxSumSubarray(arr, n, k);

    return 0;
}