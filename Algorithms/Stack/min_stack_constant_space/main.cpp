#include <bits/stdc++.h>
using namespace std;

/**
 * PS: Implement Min Stack Without Extra Space. 
 * IP: vector<int> arr;
 * OP: Return min Element from Stack;
 */

// Aliases
using v = vector<int>;

// Mn Stack Code 
int minEle;
stack<int> st;

// GetMinElement Function
int getMin() {
    if(st.empty())
        return -1;

    return minEle;
}

// Push: >=, <
void push(int x) {
    if(st.empty()) {
        st.push(x);
        minEle = x;
    } else {
        if(x >= minEle) {
            st.push(x);
        } else {
            long long flag = 2LL * x - minEle;
            st.push((int)flag);
            minEle = x;
        }
    }
}

// Pop: >=, <
void pop() {
    if(st.empty()) {
        return;
    } else {
        if(st.top() >= minEle) {
            st.pop();
        } else {
            // Move back to minELement using the mechanism
            // prevME = 2 * ME - Y
            minEle = (int)(2LL * minEle - st.top());
            st.pop();
        }
    }
}

// Top: >=, <
int top() {
    if(st.empty()) {
        return -1;
    } else {
        if(st.top() >= minEle) {
            return st.top();
        } else {
            return minEle;
        }
    }
}


int main(){
    v arr = {5, 7, 3};

    for(auto ele: arr) {
        push(ele);
    }    

    cout << getMin() << endl; // OP: 3
    cout << top() << endl;    // OP: 3

    pop();

    cout << getMin() << endl; // OP: 5
    cout << top() << endl;    // OP: 7

    return 0;
}