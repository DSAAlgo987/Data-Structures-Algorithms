#include <bits/stdc++.h>
using namespace std;

// Time complexity: O(n^2)
int  fruitsBaskets(vector<int>& fruits, vector<int>& basket){
    int n = fruits.size();

    int rem = 0;

    // outer loop: Fruits
    for(int i = 0; i < fruits.size(); i++){
        bool assigned = false;
        // Inner loop : baskets
        for(int j = 0; j < basket.size(); j++){
            if(fruits[i] <= basket[j] && basket[j] != 0){
                basket[j] = 0; // Occupied;
                assigned = true;
                break;
            }
        }

        if(assigned == false){
            rem++; // One type of fruit is not placed
        }
    }
   
    return rem;
}

int main(){
    vector<int> fruits = {44,10};
    vector<int> baskets = {26,5};

    cout << fruitsBaskets(fruits, baskets);
    
    return 0;
}