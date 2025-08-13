// Recursion based: log(N)
class Solution {
public:
    bool isPowerOfThree(int n) {
        // Base conditions 
        if(n <= 0){ // Powers are only in positive  
            return false;
        }
        else if(n == 1){
            return true;
        }else if(n % 3 != 0){
            return false;
        } 
        return isPowerOfThree(n/3);
    }
};

// Loop based: log(N)
class Solution {
public:
    bool isPowerOfThree(int n) {
        // Negative 
        if(n <= 0){
            return false;
        }

        while(n % 3 == 0){
            n /= 3;
        }

        return n == 1;
    }
};

// Log based: O(1) : This will not satisfy all the test cases.
class Solution {
public:
    bool isPowerOfThree(int n) {
        double x = log(n) / log(3);
        return n > 0 && x == (int) x;
    }
};

// Math based: O(1) 
class Solution {
public:
    bool isPowerOfThree(int n) {
        // Negative number 
        if(n <= 0){
            return false;
        }

        
        // 3^p % n == 0 -> (yes) 1 (no)
        // 3^19 = 1162261467
        return 1162261467 % n == 0;
    }
};
