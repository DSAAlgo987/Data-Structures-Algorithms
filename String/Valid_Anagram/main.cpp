#include <bits/stdc++.h>
using namespace std;

// Brute force approach
bool Anagram1(string s1, string s2){
    if(s1.size() != s2.size())
        return false; // Not an anagram

    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());

    return (s1 == s2) ? true : false;
}

// Hashing approach
bool Anagram2(string s1, string s2){
    if(s1.size() != s2.size())
        return false; // Not an anagram

    int count[26] = {0}; // Initially initialize with 0
    
    // Read s1 string 
    for(auto &c: s1){
        count[c - 'a']++;
    }

    // Read s2 string
    for(auto &c: s2){
        count[c - 'a']--;
    }

    // Check Anagram or not ?
    for(auto i: count){
        if(i != 0){
            return false; // Not an agnagram
        }
    }

    return true; // An anagram
}

// Unordered map approach
bool Anagram3(string s1, string s2){
    if(s1.size() != s2.size())
        return false; // Not an anagram

    unordered_map<char, int> m;

    // Read s1 string 
    for(auto &c: s1){
        m[c]++;
    }

    // Read s2 string
    for(auto &c: s2){
        m[c]--;
    }

    // Check Anagram or not ?
    for(auto &e: m){
        if(e.second != 0){
            return false;  // Not an anagram
        }
    }

    return true; // An anagram
}


int main(){

    string s1 = "silent", s2 = "listen";
    
    if(Anagram1(s1, s2)){
        cout << "Anagram1: True" << endl;
    }
    if(Anagram2(s1, s2)){
        cout << "Anagram2: True" << endl;
    }
    if(Anagram3(s1, s2)){
        cout << "Anagram3: True" << endl;
    }
    else{
        cout << "False" << endl;
    }

    return 0;
}