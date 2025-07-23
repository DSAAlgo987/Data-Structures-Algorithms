#include <bits/stdc++.h>
using namespace std;

/**
 * Count is a reserved global variable 
 * Problem: Display all possible substring 
 */

int cnt = 0;

// O(n^2)
void solve(string &ip, char *op, int index, int currentLen){
    // BC: If ip string processed
    if(ip[index] == '\0'){
        op[currentLen] = '\0';
        cout << op << endl;
        cnt++;
        return;
    }
    op[currentLen] = ip[index];
    // Include current char 
    solve(ip, op, index + 1, currentLen + 1);

    // Exclude current char 
    solve(ip, op, index + 1, currentLen);
}

// n^3
void substrings(string &ip){

    cout << "Simpler method" << endl;
    int count = 0;
    for(int i = 0; i < ip.size(); i++){
        for(int j = i; j < ip.size(); j++){
            for(int k = i; k <= j; k++){
                cout << ip[k];

            }
            cout << endl;
            count++;
        }
    }

    cout << count << endl;
}

// n^2
void better(string &ip){
    string temp;
    for(int i = 0; i < ip.size(); i++){
        temp = "";
        for(int j = i; j <ip.size(); j++){
            temp += ip[j];
            cout << temp << endl;
        }
    }
}


int main(){
    string ip = "abc";

    // char op[100];
    // solve(ip, op, 0, 0);
    // cout << cnt << endl;

    // substrings(ip);

    better(ip);
    return 0;   
}