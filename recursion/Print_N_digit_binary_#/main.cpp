#include <bits/stdc++.h>

using namespace std;

void solve(string op, int zero, int one, int N){
    // Base condition 
    if(N == 0){
        cout << op << endl;
        return;
    }

    // Single Choice: Add 1 when zero == one
    if(zero == one){
        string op1 = op;
        op1.push_back('1');
        solve(op1, zero, one + 1, N - 1);
    }
    // Double choices: Add 1 or 0 
    else{
       string op1 = op;
       op1.push_back('1');
       solve(op1, zero, one + 1, N - 1);
       
       string op2 = op;
       op2.push_back('0');
       solve(op2, zero + 1, one, N - 1);
    }
}

int main() {
    int N = 3;
    int zero = 0;
    int one = 0;

    string op = "";

    solve(op, zero , one , N);

    return 0;
}