#include <stdio.h>
#include <limits.h>

int solve(int arr[], int i, int j){
    // Base condition
    if(i >= j){
        return 0;
    }
    
    int min = INT_MAX;
    // k loop
    for(int k = i; k <= j-1; k++){
        // temp ans 
        int tempAns = solve(arr, i, k) + solve(arr, k+1, j) + arr[i-1] * arr[k] * arr[j];
        
        // Idenitfy min cost from temp ans 
        if(tempAns < min){
            min = tempAns;
        }
    }
    
    return min;
}

int main()
{
    int arr[] = {40, 20, 30, 10, 30};
    
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Min Cost: %d", solve(arr, 1, n-1));

    return 0;
}