#include <bits/stdc++.h>

using namespace std;

int reverse(int x){
    int rev = 0;

    while(x != 0){
        // Remove last digit 
        int digit = x % 10;

        // Check overflow or underflow before reversing a digit 
        if(rev > INT_MAX / 10 || rev < INT_MIN / 10){
            return 0; // Reversing digit will cause an error 
        }

        // Reverse digit by digit 
        rev = rev * 10 + digit;

        // Remove digit from that x 
        x /= 10;
    }

    return rev;
}

int main() {

    cout << "Reversed No: " << reverse(-123);
    
    return 0;
}