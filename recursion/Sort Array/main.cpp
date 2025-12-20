#include <bits/stdc++.h>
#include <iostream>

using namespace std;

// Problem: Sort array in ascending order 

// Aliases
using v = vector<int>; 

// Display arr 
void displayArr(v &arr) {
    for(auto ele: arr){ 
        cout << ele << " ";
    }
    cout << endl; 
}

// Insert temp element at correct position 
void insort(v &arr, int temp) { 
    // Base condition 
    if(arr.size() == 0 || arr[arr.size() - 1] <= temp) {
        arr.push_back(temp);
        return; 
    }
    
    // Make the ip smaller 
    int v = arr[arr.size() - 1];
    arr.pop_back();
    
    insort(arr, temp);
    
    // push the popped element form the vector
    arr.push_back(v);
}

// SortArr 
void sortArr(v &arr) {
    // Base condition 
    if(arr.size() == 1) {
        return;
    }
    
    // Induction: Make ip smaller 
    int temp = arr[arr.size() - 1]; 
    arr.pop_back();
    
    sortArr(arr); 
    
    insort(arr, temp);
}



int main()
{
    v arr = { 1, 5, 0, 2};
    
    sortArr(arr); 
    
    displayArr(arr); 
    return 0;
}