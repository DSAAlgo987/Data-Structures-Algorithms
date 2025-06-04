#include <bits/stdc++.h>
using namespace std;

void printStack(stack<int> &st){
    // Base condition 
    if(st.empty()){
        return;
    }
    int top = st.top();
    st.pop();
    printStack(st);
    cout << top << " ";
}

void inSort(stack<int> &st, int temp){
    // Base condition 
    if(st.empty() || st.top() <= temp){
        st.push(temp);
        return;
    }
    int top = st.top();
    st.pop();
    inSort(st, temp);
    st.push(top);
}

void sortStack(stack<int> &st){
    // Base condition 
    if(st.size() == 1){
        return;
    }

    // Induction 
    int temp = st.top(); 
    st.pop();
    sortStack(st);
    inSort(st, temp);
}


int main(){
    stack<int> st;

    st.push(0);
    st.push(5);
    st.push(1);
    st.push(2);

    // Hypothesis
    sortStack(st);

    printStack(st);


    return 0;
}