#include <bits/stdc++.h>
using namespace std;

void printStack(auto &st){
    // BC 
    if(st.empty()){
        return;
    }

    // Induction 
    int top = st.top();
    st.pop();
    cout << top << " "; 
    printStack(st);
}

void IReverse(stack<int> &st, int ele){
    // BC 
    if(st.empty()){
        st.push(ele);
        return;
    }

    // Induction 
    int temp = st.top();
    st.pop();
    IReverse(st, ele);
    st.push(temp);
}

void reverse(stack<int> &st){
    // BC 
    if(st.size() == 1 ){
        return;
    }

    // Induction 
    int temp = st.top();
    st.pop();
    reverse(st);
    IReverse(st, temp);
}

int main(){
    stack<int> st;

    st.push(5);
    st.push(4);
    st.push(3);
    st.push(2);
    st.push(1);

    reverse(st);

    printStack(st);
    return 0;
}