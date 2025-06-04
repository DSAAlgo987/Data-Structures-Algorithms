#include <bits/stdc++.h>
using namespace std;


int solve(int N, int k){
    // Base condition 
    if(N == 1 && k == 1){
        return 0;
    }

    // Induction 
    int mid = pow(2, N - 1);
    if(k <= mid){
        return solve(N - 1, k);
    }else{
        return !solve(N - 1, k - mid);
    }
}

int main(){
    
    // Hypothesis
    int ans = solve(4, 5);
    cout << ans << endl;

    return 0;
}