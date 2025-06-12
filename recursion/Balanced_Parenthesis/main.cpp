#include <bits/stdc++.h>

using namespace std;

void solve(int open, int close, string op, vector<string> &v){
    // Base condition 
    if(open == 0 && close == 0){
        v.push_back(op);
        return;
    }

    // Choices 
    if(open != 0){
        string op1 = op;
        op1.push_back('(');
        solve(open - 1, close, op1, v);
    }

    // Choices
    if(close > open){
        string op2 = op;
        op2.push_back(')');
        solve(open, close - 1, op2, v);
    }
}

void printVector(vector<string> &v){
    for(auto s: v){
        cout << s << endl;
    }
}   

int main() {
    vector<string> v;
    int n = 3;

    int open = n;
    int close = n;

    string op = "";

    solve(open, close, op, v);

    printVector(v);
    return 0;
}