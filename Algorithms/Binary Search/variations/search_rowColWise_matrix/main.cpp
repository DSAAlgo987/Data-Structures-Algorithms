#include <bits/stdc++.h>
using namespace std;

/**
 * PS: Search an element in row + col wise in a matrix.
 * 
 * Ip:
 * vector<vector<int>> mat, int key;
 * 
 * Op:
 * return index if found o/w return -1;
 */

using v = vector<vector<int>>;

// Time complexity: O(n+m)
vector<int> BinarySearchMatrix(v &mat, int key) {
    int n = mat.size();
    int m = mat[0].size();
    int i = 0; 
    int j = m-1;

    while(i >= 0 && i < n && j >= 0 && j < m) {
        if(mat[i][j] == key) {
            return {i,j};
        }
        else if(mat[i][j] > key) {
            j--;
        }
        else {
            i++;
        }
    }

    return {-1,-1}; // Invalid search;
}

void printV(vector<int> &mat) {
    cout << "[ ";
    for(auto n: mat) {
        cout << n << " ";
    }
    cout << "]" << endl;
}

int main(){
    v mat = {
        {10, 20, 30, 40},
        {15, 25, 35, 45},
        {27, 29, 37, 48},
        {32, 33, 39, 49}
    };

    vector<int> ans = BinarySearchMatrix(mat, 29);
    printV(ans); // Op: (2, 1)

    ans = BinarySearchMatrix(mat, 23);
    printV(ans); // Op: (-1, -1)
    return 0;
}