#include <bits/stdc++.h>
using namespace std;

/**
 * PS: Implement Min Stack With Extra Space;
 * IP: vector<int> arr;
 * OP: Return min Element from Stack;
 */

// Aliases
using v = vector<int>;
using st = stack<int>;

// Global Stacks 
st s; 
st ss; // Supporting Stack: It stores all the min values 

int getMinElement() {
    if(ss.empty()) {
        return -1;
    }

    return ss.top();
}

void push(int a) {
    s.push(a);

    if(ss.size() == 0 || a <= ss.top()) 
        ss.push(a);

    return;
}

int pop() {
    int ans = s.top();
    s.pop();
    if(ans == ss.top()) 
        ss.pop();
    return ans;
}

int main(){
    v arr = {18, 19, 20, 15, 13, 12};

    for(int i = 0; i < arr.size(); i++) 
        push(arr[i]);
    
    cout << getMinElement() << endl;

    cout << pop() << endl;
    
    return 0;
}