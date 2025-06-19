#include <bits/stdc++.h>
using namespace std;

// Time complexity: O(n)
// Optimal soln

void solve(){
    vector<int> arr = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    
    int i = 0, j = 0;

    list<int> l; // Dequeue 

    while(j < arr.size()){
        // Calc 
        while(l.size() > 0 && l.back() < arr[j]){
            l.pop_back();
        }
        l.push_back(arr[j]);

        // Achieve window size 
        if(j - i + 1 < k ){
            j++;
        }
        else if(j - i + 1 == k){
            // Ans <- calc 
            cout << l.front() << " ";

            // Slide window 
            if(arr[i] == l.front()){
                l.pop_front();
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