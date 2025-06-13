#include <bits/stdc++.h>
using namespace std;

bool isPanagram(string s){
    vector<bool> flags(26, false);

    // Read each char of str
    for(auto const &c: s){
        // Small ?
        if(islower(c)){
            flags[c - 'a'] = true;
        }
        // Upper?
        else{
            flags[c - 'A'] = true;
        }
    }

    // Check panagram or not ?
    for(auto const &i: flags){
        if(i == false){
            return false;
        }
    }

    return true;
}

int main(){
    string s1 = "abcdefghIjkLmnOpqRsTvuwyxZ";
    string s2 = "leetcode";

    if(isPanagram(s2)){
        cout << "True" << endl;
    }else {
        cout << "False" << endl;
    }


    return 0;
}