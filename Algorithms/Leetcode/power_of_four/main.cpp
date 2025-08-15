// Recursion: logn
class Solution {
public:
    bool isPowerOfFour(int n) {
        // Base case
        if(n <= 0) // Negative + 0
            return false; 
        else if(n == 1)
            return true;
        // 4^x logic
        else if(n / 4 == 1 && n % 4 == 0){
            return true;
        }
        // Handle odd 
        else if(n % 4 != 0){
            return false;
        }
        return isPowerOfFour(n/4);
    }
};

// Loop : logn
class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n <= 0){ // 4 powers are positive 
            return false; 
        }

        while(n % 4 == 0){ // if mode 0 then enter the loop 
            n /= 4; // keep divide by 4 
        }
        
        return n == 1 ? true : false;
    }
};

// Bit manipulation : logn
class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n <= 0){ // 4 powers are positive 
            return false; 
        }

        while(n > 1){
            if(n % 4 != 0){ // handle odd case 
                return false;
            }
            // perform right shift 
            n >>= 2;
        }
        
        // Reached to 1
       return true;
    }
};


// Math based : O(1) but this will not work will all the test cases
class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n <= 0){ // 4 powers are positive 
            return false; 
        }

        // 4^mx_p % n == 0 ? true : false;
        // mx_p = 1073741824
        return 1073741824 % n == 0;
    }
};