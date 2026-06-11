#include <bits/stdc++.h> 
using namespace std; 

/**
 * Topic: Singly Linked List 
 * Desc: It is collection of nodes which are connected in a linear fashion. 
 *       It stores elements in non contingous manner and it's linear DS. 
 * Dynamic Memory allocation: New , malloc 
 *  new: An operator which is used to dynamic allocation and initlization heap memory 
 *       Type safety (no need to type casting)
 *       used only in cpp 
 *  malloc: It is a function which is used to intilize heap memory 
 *       There is no type safety 
 *       used in both c and cpp
 * 
 * Operations: 
 *  1. create -> O(n) 
 *  2. insert after value -> O(n)
 *  3. deletion using value -> O(n)
 *  4. search -> O(n)
 *  5. traverse -> O(n)
 *  6. length -> O(n);
 */

class Node { 
    public: 
        int data; 
        Node* next; 
    
    Node(int val): data(val), next(nullptr) {}
}; 

Node* head = nullptr; 

void create() { 
    int n; 
    cin >> n; 
    Node* tail = nullptr; 
    
    for(int i = 0; i < n; i++) { 
        int val;
        cin >> val; 
        
        Node* temp = new Node(val);
        
        if(head == nullptr) {
            head = temp; 
            tail = temp; 
        } else { 
            tail->next = temp; 
            tail = temp; 
        }
    }
}

void traverse() { 
    if(head == nullptr) {
        cout << "Empty \n";
        return; 
    }
    
    Node* temp = head; 
    
    while(temp) { 
        cout << temp->data;
        
        if(temp->next) cout << " -> ";
        temp = temp->next; 
    }
    cout << endl; 
}

void insert() { 
    int val, x; 
    cin >> val>> x; 
    
    Node* newNode = new Node(x); 
    Node* temp = head; 
    
    while(temp && temp->data != val) { 
        temp = temp -> next;    
    }
    
    if(temp == nullptr) {
        cout << "value not found \n";
        return; 
    }
    
    newNode->next = temp->next; 
    temp->next = newNode; 
}

void deleteNode() { 
    int x; 
    cin >> x; 
    
    Node* newNode = new Node(x);
    Node* temp = head; 
    Node *prev = nullptr; 
    
    while(temp && temp->data != x) {
        prev = temp; 
        temp = temp->next; 
    }
    
    if(temp == nullptr) {
        cout << "not found \n";
        return;  
    } else if(temp == head) { 
        head = head->next; 
        delete temp; 
    } else { 
        prev->next = temp->next; 
        delete temp; 
    }
    cout << "Value Deleted: " << x << endl; 
}

void search() { 
    int x;
    cin >> x; 
    
    Node* temp = head; 
    
    while(temp && temp->data != x) { 
        temp = temp->next; 
    }
    
    if(temp == nullptr) cout << "404 \n";
    else cout << "Found! \n";
}

int length() { 
    Node* temp = head; 
    
    int count = 0; 
    
    while(temp) {
        count++; 
        temp = temp->next; 
    }
    return count; 
}


int main() { 
    // traverse(); 
    create(); 
    // traverse(); 
    // insert(); 
    // search(); 
    // deleteNode();
    cout << length() << endl;
    return 0; 
}