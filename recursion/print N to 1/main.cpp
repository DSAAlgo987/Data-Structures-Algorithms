#include <bits/stdc++.h>
using namespace std;

void print(int n){
    // Base condition 
    if(n == 0){
        return;
    }
    // Induction 
    else{
        cout << n << " ";
        print(n-1);
    }
}

int main(){
    int n = 7;
    print(n);
    return 0;
}