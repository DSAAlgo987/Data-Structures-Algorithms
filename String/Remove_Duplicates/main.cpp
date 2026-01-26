#include <bits/stdc++.h>
using namespace std; 

/**
 * PS: Remove Duplicate Chars 
 * Problem: You are given a string s. 
 * Your task is to remove Duplicate Chars and return unique string.
 * 
 * IP: String s; 
 * OP: String uniqString; 
 * 
 * APPROACH: Map based 
 * 
 * TC: O(n) -> Traversal of s string 
 * SC: O(n) -> Map space & res space 
 * 
 * OTHER APPROACHES: Use set based approach too.
 */
 
// Remove Duplicate Chars 
string removeDuplicates(string &s) { 
    // map 
    map<char, int> m1; 
    
    // Traverse s string and increment freq 
    for(auto c: s) m1[c]++;
    
    
    // Now compute unique string 
    string res = "";
    
    // Traverse map and append first of map to res string 
    for(auto [c, freq]: m1) res += c; 
    
    // Return the final ans 
    return res; 
}

int main()
{
    string s = "abacdacd";
    
    cout << removeDuplicates(s) << endl;

    return 0;
}