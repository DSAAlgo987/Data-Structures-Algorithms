#include <bits/stdc++.h>
using namespace std; 

/**
 * PS: Binary to decimal.
 * Problem: You are given a string which contains binary digits.
 * Your task is to convert it into decimal no. 
 * 
 * IP: string s; 
 * OP: int n; 
 * 
 * TC: O(n)
 * SC: O(1) constant time 
 * 
 * LEARNING: 
 *  - Simple math 
 */
 
// Binary to decimal 
int binaryDecimal(string s) {
    int p2 = 1, num = 0; 
    
    for(int i = s.size() - 1; i >= 0; i--) { 
        if(s[i] == '1') { 
            num += p2; 
        }
        
        p2 *= 2; 
    }
    
    return num; 
}

int main()
{
    string s = "111";
    
    cout << "Decimal No: " << binaryDecimal(s) << endl;

    return 0;
}