#include <bits/stdc++.h>
using namespace std;

bool isBalanced(string s){
    stack<char> st;

    // Read each char of str
    for(auto &c: s){
        // Stack empty?
        if(st.empty()){
            st.push(c);
        }
        else if((st.top() == '(' && c == ')') ||
        (st.top() == '{' && c == '}') ||
        (st.top() == '[' && c == ']')){
            st.pop();
        }else{
            st.push(c);
        }
    }

    return st.empty() ? true : false;
}


int main(){
    
    if(isBalanced("){[()]}")){
        cout << "True" << endl;
    }else{
        cout << "False" << endl;
    }
        
    
    return 0;
}