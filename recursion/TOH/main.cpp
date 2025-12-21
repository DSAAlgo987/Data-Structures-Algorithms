#include <bits/stdc++.h>
using namespace std;

void solve(int s, int d, int h, int n){
    // Base condition 
    if(n == 1) {
        cout << "Move a Plate from " << s << " -> " << d << endl;
        return;
    }
    
    // Induction 
    // Step1: Move plates from src to helper (N-1) with the help of dest
    solve(s, h, d, n - 1);
    
    // Step2: Move last plate from src to destition 
    cout << "Move a Plate from " << s << " -> " << d << endl;
    
    // Step3: Move all the plates (n-1) from helper to the destination with help of the src 
    solve(h, d, s, n - 1);
}

int main(){
    int n = 3;
    int s = 1;
    int h = 2; 
    int d = 3;

    // Hypothesis
    solve(s, h, d, n);

    return 0;
}