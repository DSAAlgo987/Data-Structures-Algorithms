#include <bits/stdc++.h>
using namespace std;

// Time complexity : O(n * k) 
// Not an optimal soln

void solve(){
    vector<int> arr = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    
    int i = 0, j = 0, mx = INT_MIN; 
    
    while(j < arr.size()){
        // Cacl 
        if(arr[j] > mx){
            mx = arr[j];
        }
        
        // Achieve window size 
        if(j - i + 1 < k){
            j++;
        }
        // Hit window size 
        else if(j - i + 1 == k){
            // Ans <- calc 
            cout << mx << " ";
            
            // Slide window
            if(arr[i] == mx){
                mx = INT_MIN;
                // Reset max 
                for(int m = i + 1; m <= j; m++){
                    mx = max(mx, arr[m]);
                }
            }
            i++;
            j++;
        }
    }
}

int main(){
    solve();
    return 0;
}