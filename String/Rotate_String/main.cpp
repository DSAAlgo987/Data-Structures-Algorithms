#include <bits/stdc++.h>
using namespace std;

bool rotateString(string s, string goal){
    // Base case
    if(s.size() != goal.size()){
        return false;
    }

    string concatedStr = s + s;

    if(concatedStr.find(goal) != string::npos){
        return true; // Found
    }

    return false; // Not Foundṇ
}
int main(){
    string s = "abcde";

    string goal = "cdeab";

    if(rotateString(s, goal)){
        cout << "True" << endl;
    }else {
        cout << "False" << endl;
    }
    return 0;
}