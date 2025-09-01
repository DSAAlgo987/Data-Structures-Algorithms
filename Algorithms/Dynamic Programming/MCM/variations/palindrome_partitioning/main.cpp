#include <bits/stdc++.h>
using namespace std; 

/**
    Problem Statement: Partitioning Palindromic 
    
    Ip:
    String s;

    Op:
    Minimize partitions;
*/

// Time complexity: O(n)
bool isPalindromic(string &s, int left, int right) {

    while(left <= right) {
        // if char not matches 
        if(s[left] != s[right]) {
            return false; // Not a palindrome
        }

        left++;
        right--;
    }

    return true; 
}

/**
    Recursive Approach: 
    Time complexity: O(2^n)
*/
int solve(string &s, int i, int j) {
    // Base conditions 
    // Empty and one letter is a palindromic string 
    if(i >= j) {
        return 0; // partition
    }

    // If string is a palindromic string 
    if(isPalindromic(s, i, j)) {
        return 0;
    }

    int ans = INT_MAX;
    // K loop scheme 1 
    for(int k = i; k <= j - 1; k++) {
        int tempAns = 1 + solve(s, i , k) + solve(s, k + 1, j);

        // Cal ans <- tempAns 
        ans = min(ans, tempAns);
    }

    return ans;
}

/**
 * Memoized Approach: 
 * Time complexity: O(n^3) 
 */
vector<vector<int>> t; // Global Declaration
int solveMemoize(string &s, int i, int j) {
     // Base conditions 
    // Empty and one letter is a palindromic string 
    if(i >= j) {
        return 0; // partition
    }

    // If string is a palindromic string 
    if(isPalindromic(s, i, j)) {
        return 0;
    }

    // Present in t?
    if(t[i][j] != -1) {
        return t[i][j];
    }

    int ans = INT_MAX;
    // K loop scheme 1 
    for(int k = i; k <= j - 1; k++) {
        int tempAns = 1 + solve(s, i , k) + solve(s, k + 1, j);

        // Cal ans <- tempAns 
        ans = min(ans, tempAns);
    }

    return t[i][j] = ans;
}

/**
 * Optimized Memoized approach:
 * Time complexity: O(n^3)
 * Other optimization we can only one partition which can be left or right 
 * why becoz if left partition is already a palindrome so don't need to call it again avoid recursive calls.
 * Template: 
        for (int k = i; k < j; k++) {
            if (palindrome[i][k]) { // only cut if left part is palindrome
                int temp = 1 + solve(s, k + 1, j);
                ans = min(ans, temp);
            }
        }
 */
int solveOptimized(string &s, int i, int j) {
    // Base conditions 
    // Empty and one letter is a palindromic string 
    if(i >= j) {
        return 0; // partition
    }

    // If string is a palindromic string 
    if(isPalindromic(s, i, j)) {
        return 0;
    }

    // Present in t?
    if(t[i][j] != -1) {
        return t[i][j];
    }

    int ans = INT_MAX;
    // K loop scheme 1 
    for(int k = i; k <= j - 1; k++) {
        // Main Issue: We are not checking that ans of sub-problems will be stored/ presnet in t. (i->k) or (k+1 -> j) 
        int left, right;

        // left (i -> k) present in t?
        if(t[i][k] != -1) {
            left = t[i][k];
        } else {
            left = solve(s, i, k);
            t[i][k] = left; 
        }

        // right (k + 1-> j) present in t?
        if(t[k+1][j] != -1) {
            right = t[k+1][j];
        } else {
            right = solve(s, k+1, j);
            t[k+1][j] = right;
        }

        int tempAns = 1 + left + right;

        // Cal ans <- tempAns 
        ans = min(ans, tempAns);
    }

    return t[i][j] = ans;
}


int main() {
    string s = "geek";
    int n = s.length();

    cout << "Recursive Approach: " << endl;
    cout << solve(s, 0, n - 1) << endl; // op: 2

    t.assign(n + 1, vector<int>(n+1, -1));

    cout << "Memoized Approach: " << endl;
    cout << solveMemoize(s, 0, n-1) << endl; // op: 2
    
    t.assign(n + 1, vector<int>(n+1, -1));

    cout << "Optimized Memoized Approach: " << endl;
    cout << solveOptimized(s, 0, n-1) << endl; // op: 2

    return 0;
}