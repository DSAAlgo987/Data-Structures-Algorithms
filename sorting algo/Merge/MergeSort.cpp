#include <bits/stdc++.h>
#include <stdio.h>

using namespace std; 

void Merge(int *A, int l, int mid, int h) { 
    int B[100];
    
    int i = l , j = mid + 1; 
    int k = l; 
    while(i <= mid && j <= h){
        if(A[i] < A[j]) B[k++] = A[i++];
        else B[k++] = A[j++];
    }
    
    while(i <= mid) B[k++] = A[i++];
    
    while(j <= h) B[k++] = A[j++];
    
    for(int i = l; i <= h; i++) A[i] = B[i];
}

void MergerSort(int *A, int l, int h) { 
    if(l < h) { 
        int mid = l + (h - l) / 2;   // Handle integer overflow 
        MergerSort(A, l , mid);
        MergerSort(A, mid + 1, h); 
        Merge(A, l, mid, h); 
    }
}


int main()
{
    int A[] = {50, 80, 70, 60, 10, 20, 30, 40};
    int n = sizeof(A) / sizeof(A[0]);
    
    // QuickSort(A, 0, n);
    MergerSort(A, 0, n - 1); 
    
    for(auto x: A) cout << x << " ";
    return 0;
}