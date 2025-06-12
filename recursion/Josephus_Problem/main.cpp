#include <bits/stdc++.h>

using namespace std;

void solve(vector<int> &person, int current, int k){
    // Base condition 
    if(person.size() == 1){
        cout << person[0] <<endl;
        return;
    }

    // Induction 
    // Kill that person 
    int index = (current + k) % person.size();

    person.erase(person.begin() + index);

    solve(person, index, k);
}

int main() {

    vector<int> person = {1, 2, 3, 4, 5};

    int k = 2;
    k--;    
    solve(person, 0, k);
    
    return 0;
}