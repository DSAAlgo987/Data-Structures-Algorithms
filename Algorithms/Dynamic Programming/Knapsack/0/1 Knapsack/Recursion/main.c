#include <stdio.h>

int max(int a, int b){
    return (a > b) ? a : b;
}


// Knapsack
int Knapsack(int wt[], int val[], int W, int n){
    // base condition 
    if(n == 0 || W == 0){
        return 0;
    }
    
    // choice diagram
    if(wt[n-1] <= W){
        int a = val[n-1] + Knapsack(wt, val, W-wt[n-1], n-1);
        int b = Knapsack(wt, val, W, n-1);
        return max(a, b);
    }
    
    else if(wt[n-1] > W){
        return Knapsack(wt, val, W, n-1);   
    }
}

int main()
{
    int wt[] = {1, 3, 4, 5};
    int val[] = {1, 4, 5, 7};
    int W = 7;
    
    int n = sizeof(wt) / sizeof(wt[0]);
    
    printf("Max Profit: %d", Knapsack(wt, val, W, n));

    return 0;
}