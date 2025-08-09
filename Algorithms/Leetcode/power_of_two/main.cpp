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