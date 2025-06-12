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

    // Add smaller char in op1 
    op1.push_back(tolower(ip[0]));

    // Add capital char in op2
    op2.push_back(toupper(ip[0]));

    // Erase first char in ip 
    ip.erase(ip.begin() + 0);

    // Agagin call solve for other chars
    solve(ip, op1);
    solve(ip, op2);

}

int main() {
    string ip = "ab";

    string op;

    solve(ip, op);
    return 0;
}