#include <bits/stdc++.h>
#include <iostream>

using namespace std;

// Problem Sort A Stack in ASC/DESC order 

// ALiase
using st = stack<int>; 

// Display Stack 
void displayStack(st &s) {
    while(s.size() != 0) {
        cout << s.top() << " "; 
        s.pop();
    }
    cout << endl;
}

// Insert Element in stack at valid position 
void insert(st &s, int temp) {
    // Base condition 
    if(s.size() == 0 || s.top() <= temp) {
        s.push(temp);
        return;
    }
    
    // Induction: making the ip smaller 
    int x = s.top(); 
    s.pop();
    
    insert(s, temp);
    
    s.push(x);
}

// Sort stack
void sortStack(st &s) {
    // Base condition 
    if(s.size() == 1) {
        return;
    }
    
    // Induction: Making the ip smaller 
    int temp = s.top(); 
    s.pop(); 
    
    sortStack(s); 
    insert(s, temp); 
    
}

int main()
{
    st s;
    s.push(0);
    s.push(5);
    s.push(2);
    s.push(1);
    
    // Hypothesis
    sortStack(s);
    
    displayStack(s);

    return 0;
}