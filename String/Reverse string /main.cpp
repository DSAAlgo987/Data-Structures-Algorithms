#include <bits/stdc++.h>

using namespace std;

void reverseString(string &s){
    // Reverse string using two point approach 
    int left = 0, right = s.size() -1;

    while(right > left){
        int temp = s[right];
        s[right] = s[left];
        s[left] = temp;
        left++; right--;
    }

    // Display that string 
    for(auto &c: s){
        cout << c << " ";
    }
}

int main() {
    string s= "faisal";
    reverseString(s);
    
    return 0;
}