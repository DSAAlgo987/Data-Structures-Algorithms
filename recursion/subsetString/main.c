#include <bits/stdc++.h>
#include <stdio.h>

using namespace std; 

/* 
    Problem: Print Unique Subsets
    Time complexity: O(2^n)
    Space complexity: O(n. 2^n)
*/

// ALiases 
using st = unordered_set<string>;

st subsets; 

void displaySet(st &s) {
    for(auto c: s) {
        cout << c << " ";
    }
    
    cout << endl;
}

// PrintUniqueSubsets: Ip/Op Method 
void PrintUniqueSubsets(string ip, string op, int idx) {
    // base condition 
    if(idx == ip.size()) {
        subsets.insert(op);
        return;
    }
    
    // Include 
    PrintUniqueSubsets(ip, op + ip[idx], idx+1);
    
    // Exclude 
    PrintUniqueSubsets(ip, op, idx+1);
}


int main()
{
    string ip = "aab";
    string op = "";
    PrintUniqueSubsets(ip, op, 0);
    
    displaySet(subsets);

    return 0;
}