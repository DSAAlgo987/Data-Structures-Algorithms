// TC: O(n) SC: O(1)
class Solution {
public:
    bool isPalindrome(string s) {
        // S1: clean and transform string s 
        int l = 0; 

        for(auto x: s) {
            if(isalnum(x)) { 
                s[l++] = tolower(x); 
            }
        }

        // S2: Find is it a palindrome or not 
        int r = 0; l-=1; 

        while(r < l) { 
            if(s[r] != s[l]) return false; 
            r++; l--; 
        }

        return true; 
    }
};