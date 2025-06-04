#include <bits/stdc++.h>
using namespace std;

void solve(int s, int d, int h, int n){
    // BC 
    if(n == 1){
        cout << "Move "<< n << " plate from "<< s << " " << d << endl;
        return;
    }

    // Smaller input 
    solve(s, h, d, n - 1);

    cout << "Move "<< n << " plate from "<< s << " " << d << endl;

    // Induction 
    solve(h, d, s, n-1);
}

int main(){
    int n = 3;
    int s = 1;
    int h = 2; 
    int d = 3;

    solve(s, h, d, n);

    return 0;
}