#include <stdio.h>

int minCoins(int amount , int A[] , int n){
    if(amount == 0){
        return 0;
    }
    int ans = 1000000;
    for(int i = 0; i < n; i ++){
        if(amount-A[i] >= 0){
            int subAns = minCoins(amount-A[i] , A , n);
            if(subAns + 1 < ans){
                ans = subAns + 1;
            }
        }
    }
    return ans;
}

int main() {
    int A[] = { 7 , 5 , 1};
    int amount = 18;

    printf("%d" , minCoins(amount, A, 3));

    return 0;
}