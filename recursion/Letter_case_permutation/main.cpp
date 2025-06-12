#include <bits/stdc++.h>

using namespace std;

void solve(string ip, string op){
    // Base condition 
    if(ip.size() == 0){
        cout << op << endl;
        return;
    }

    // Copy op in op1 and op2 
    string op1 = op;
    string op2 = op;

    if(!isalpha(ip[0])){
        // Add char in lower case 
        op1.push_back(ip[0]);
        ip.erase(ip.begin() + 0);
        solve(ip, op1);

        return;
    }
    // Add char in lower case 
    op1.push_back(tolower(ip[0]));
    
    // Add char in upper case
    op2.push_back(toupper(ip[0]));

    // Remove first char from ip string
    ip.erase(ip.begin() + 0);

    // Again call for other chars 
    solve(ip, op1);
    solve(ip, op2);
}

int main() {
    string ip = "a1B2";

    string op;

    solve(ip, op);
    return 0;
}