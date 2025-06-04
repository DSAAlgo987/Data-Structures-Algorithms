#include <bits/stdc++.h>
using namespace std;

void printStack(stack<int> &st){
    // BC
    if(st.empty()){
        return;
    }

    // Induction 
    int top = st.top();
    st.pop();
    printStack(st);
    cout << top << " ";
}

void solve(stack<int> &st, int k){
    // BC
    if(k == 1){
        // Remove that element from stack 
        st.pop();
        return;
    }

    // Induction 
    int top = st.top();
    st.pop();
    solve(st, k-1);
    st.push(top);
}

int main(){
    stack<int> st;

    st.push(5);
    st.push(4);
    st.push(3);
    st.push(2);
    st.push(1);

    solve(st, 3);
    printStack(st);


    return 0;
}