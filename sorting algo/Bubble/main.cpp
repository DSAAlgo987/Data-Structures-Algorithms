#include <bits/stdc++.h>
using namespace std; 

/**
 * Bubble Sort: It is a sorting algorithm. Which is used to sort the elements 
 * in ASC or DESC order.
 * It is called bubble bcoz heaviest element will go to the bottom and lighter element 
 * will come up.
 * TC: 
 *  B(n) = O(n) -> Linear TC
 *  W(n) = O(n^2) -> Qaudractic TC 
 * 
 * It is not adaptive by nature but we can make this algo as adaptive
 * 
 * It is stable (Preseves the order of duplicate elements)
 * 
 * 
 **/

void BubbleSort(int *A, int n) { 
    
    // # of passes 
    for(int i = 0; i < n - 1; i++) { 
        // Comparision 
        for(int j = 0; j < n - 1 - i; j++) { 
            if(A[j] > A[j+1]) {
                swap(A[j], A[j+1]);
            }
        }
    }
}

int main()
{
    int A[] = {8, 5, 7, 3, 2};
    int n = sizeof(A)/ sizeof(A[0]);
    
    BubbleSort(A, n);
    
    for(auto x: A) cout << x << " ";
    
    

    return 0;
}