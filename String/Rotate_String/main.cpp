#include <bits/stdc++.h>
using namespace std;

/**
 * PS: Check if one string is a rotation of another string.
 *
 * IP: Strings S and R
 * OP: Return true if R is a rotation of S, otherwise false.
 *
 * APPROACHES:
 *  1. Built-in method:
 *     - Concatenate S with itself and check if R is a substring.
 *     - TC: O(n)
 *     - SC: O(n)
 *
 *  2. Brute-force substring matching:
 *     - Manually check if R exists as a continuous substring in S + S.
 *     - TC: O(n)
 *     - SC: O(n)
 *
 * LEARNING:
 *  - Implementation of substring matching
 *  - Usage of the string::find() method
 *  - Understanding the scope resolution operator (::)
 *    - string::npos is a static constant member of std::string
 *    - It represents "not found" (conceptually equal to -1)
 */


bool isSubstring(string temp, string r, int m, int n) {
    // start < m - n this handles overflow (out of bound)
    for(int start = 0; start < m - n; start++) {
        int j = 0; // To reset if discontinue occurs
        
        while(j < n && temp[start + j] == r[j]) {
            j++;
        }

        // if r string is processed 
        if(j == n) return true;
    }

    // if substring not found 
    return false; 
}

bool solve(string &s, string &r) {
    // BC 
    if(s.size() != r.size()) return false; 

    string temp = s + s; 
    int m = temp.size();
    int n = r.size();

    // Substring logic 
    return isSubstring(temp, r, m, n);
}

bool rotateString(string s, string goal){
    // Base case
    if(s.size() != goal.size()){
        return false;
    }

    string temp = s + s;
    return temp.find(goal) != string::npos;
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