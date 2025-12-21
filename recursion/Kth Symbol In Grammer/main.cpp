#include <bits/stdc++.h>

using namespace std; 

/* 
    Problem: Kth Symbol in Grammar 
    IP: N(col) and K(row) 1 indexed based 
    OP: Return 0/1
    Time Complexity: O(N)
    Space Complexity: O(N)
*/


int kThSymbol(int N, int K) {
    // Base condition 
    if(N == 1 && K == 1) {
        return 0; 
    }
    
    // Induction: Make Ip Smaller wisely 
    
    // Identify the mid point 
    int mid = pow(2, N-1) / 2; 
    
    // Check where k's lies 
    if(K <= mid) {
        // Normal Region
        return kThSymbol(N-1, K);
    } else {
        // Complement Region
        return !kThSymbol(N-1, K-mid);
    }
}

int main()
{
    cout << kThSymbol(3, 3) << endl;

    return 0;
}