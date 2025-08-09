// Time complexity : logn 
// Space complexity: logn

class Solution {
public:
    bool isPowerOfTwo(int n) {
        // Base conditions 
        if(n == 1){
            return true;
        }
        if (n < 1){
            return false;
        }
        else if(n % 2 == 1){
            return false;
        }else {
            return isPowerOfTwo(n/2);
        }
    }
};

// Optimized Approach: 
// Time complexity: O(1)

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n > 0){
            return !(n & (n - 1)) ? true: false;
        }
        return false;
    }
};