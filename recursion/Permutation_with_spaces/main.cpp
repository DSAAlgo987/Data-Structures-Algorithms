#include <bits/stdc++.h>

using namespace std;

void solve(string ip, string op){
    // Base condition 
    if(ip.size() == 0){
        cout << op << endl;
        return;
    }

    string op1 = op;
    string op2 = op;

    // Include char with spaces(_)
    op1.push_back('_');
    op1.push_back(ip[0]);

    // Include char without spaces
    op2.push_back(ip[0]);

    // Remove that char from ip string 
    ip.erase(ip.begin() + 0);

    // Again call solve for other chars 
    solve(ip, op1);
    solve(ip, op2);
}

int main() {
    string ip = "abc";
    string op;

    op.push_back(ip[0]);
    // Syntax: 
    // s.erase(itr)
    ip.erase(ip.begin() + 0); // 0 specify index we are deleting
    // ip.earse(ip.begin() + 2); // It means we are deleting 2nd index element

    solve(ip, op);
    return 0;
}