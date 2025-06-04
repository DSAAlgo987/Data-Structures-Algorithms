#include <bits/stdc++.h>
using namespace std;

// IBH Method

void print(int n){
    // Base condition 
    if(n == 0){
        return;
    }
    // Induction
    else{
        print(n-1);
        cout<< n << " ";
    }
}

int main(){
    int n = 7;

    // Hypothesis
    print(n);
    return 0;
}