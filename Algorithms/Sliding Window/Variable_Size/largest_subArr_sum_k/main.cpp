#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &A, int n, int k){
    int i = 0, j = 0, sum = 0, mx = INT_MIN; 

    while(j < n){
        // Calculation 
        sum += A[j];

        // Achieve condition 
        if(sum < k){
            j++;
        }

        // Hit condition 
        else if(sum == k){
            // Ans calculation 
            mx = max(mx, j - i + 1);
            j++;
        }

        else if(sum > k){
            // Remove ith element if sum > k 
            while(sum > k){
                sum -= A[i];
                i++;
            }

            j++;
        }
    }

    return mx;
}

int main(){
    vector<int> A = {4, 1, 1, 1, 1, 1};

    int k = 5;

    int ans = solve(A, A.size(), k);

    cout << "Ans: " << ans << endl;
    return 0;
}