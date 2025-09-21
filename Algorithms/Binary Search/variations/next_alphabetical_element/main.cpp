#include <bits/stdc++.h>
using namespace std; 

/**
 * Problem Statement: Return next alphabetical element which is greater than target.
 * 
 * Ip:
 * vector<char> arr, char key
 * 
 * Op:
 * Return that element if found o/w '#'
 */

char BinarySearchNextAlphabet(vector<char> &arr, char key) {
    int start = 0;
    int end = arr.size() - 1;
    char res = '#';
    
    while(start <= end) {
        int mid = start + (end - start) / 2;
        
        if(arr[mid] == key) {
            start = mid + 1;
        }
        else if(arr[mid] < key) { // Key is greater 
            start = mid + 1;
        } else { // Key is lesser
            res = arr[mid]; 
            end = mid - 1;
        }
    }
    
    return res;
}

int main()
{
    vector<char> arr = {'a', 'b','c','f','h','i'};
    
    cout << BinarySearchNextAlphabet(arr, 'f') << endl; // Op : h 
    cout << BinarySearchNextAlphabet(arr, 'l') << endl; // Op : #
    return 0;
}