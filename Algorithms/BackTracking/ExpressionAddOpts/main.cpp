#include <bits/stdc++.h>
using namespace std; 

/**
 * PS: Expression Add Operators
 *
 * Problem:
 * Given a string `num` containing only digits and an integer `target`,
 * return all possible expressions formed by inserting the binary operators
 * '+', '-', and/or '*' between the digits such that the resulting expression
 * evaluates to `target`.
 *
 * Notes:
 * - Operands must not contain leading zeros (e.g., "05" is invalid).
 * - An operand may consist of multiple digits.
 *
 * Input:
 * - string num
 * - int target
 *
 * Output:
 * - vector<string> containing all valid expressions
 *
 * Approach:
 * - Use backtracking to try all possible splits of the string and insert
 *   operators between operands.
 * - Maintain:
 *   - `eval`: current evaluated value of the expression
 *   - `prev`: last evaluated operand (with sign), required to correctly
 *     handle multiplication due to operator precedence
 *
 * Time Complexity:
 * - O(4^L) in the worst case, where L is the length of the string
 *   (each position can branch into +, -, *, or digit continuation)
 *
 * Space Complexity:
 * - O(L) recursion depth (excluding output storage)
 *
 * Key Learning:
 * - `prev` stores the last evaluated operand (including its sign).
 * - For multiplication, undo the previous operation:
 *     eval = eval - prev + (prev * curr)
 *   to correctly maintain operator precedence.
 */


// Aliases 
using v = vector<string>;
using LL = long long;

// Global Vars
v ans; 
 
// Expression Add Operators Function 
void solve(int idx, string &nums, int target, LL p, LL e, string op) {
    // BC 
    if(idx == nums.size()) {
        // Check that evaluated result == target ?
        if(e == target) {
            ans.push_back(op);
        }
        return; 
    }
    
    LL c = 0;
    // Traverse each numbers 
    for(int i = idx; i < nums.size(); i++) {
        
        // leading zero check 
        if(i > idx && nums[idx] == '0') break;
        
        // Multidigit handler
        c = c * 10 + (nums[i] - '0');
        string currStr = nums.substr(idx, i - idx + 1);
        
        if(idx == 0) {
            // single choice 
            solve(i + 1, nums, target, c, c, op + currStr);
        } else {
            // Multiple choices 
            // 1. Addition 
            solve(i + 1, nums, target, c, e + c, op + '+' + currStr);
            
            // 2. Subtraction 
            solve(i + 1, nums, target, -c, e - c, op + '-' + currStr);
            
            // 3. Multiplicaiton
            solve(i + 1, nums, target, p * c, e - p + (p * c), op + '*' + currStr);
        }
    }
} 

int main()
{
    string nums = "123";
    int target = 6;
    string op = "";
    
    solve(0, nums, target, 0, 0, op);
    
    // Display ans 
    for(auto x: ans) {
        cout << x << " ";
    }
    return 0;
}