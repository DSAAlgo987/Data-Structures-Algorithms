#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *lChild , *rChild;
}*root = NULL;

int heighOfTree(struct Node *ptr){
    // Base condition 
    if(ptr == nullptr){
        return -1;
    }

    // Induction 
    else{
        int a = heighOfTree(ptr->lChild);
        int b = heighOfTree(ptr->rChild);

        return (a > b) ? a + 1: b + 1;
    }
}


// create Node 
struct Node *createNode(int data){
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    temp->lChild = temp->rChild = NULL;

    return temp;
}

// Insert : TC : O(nlogn) where n : insert & logn for searching 
void insert(int key){
    struct Node *parent  ,*newNode , *temp;

    newNode = createNode(key); // creation of new Node
    if(root == NULL){
        root = newNode;
    }else{
        temp = root;
        while(temp!=NULL){
            parent = temp;
            if(key > temp->data){
                temp = temp->rChild;
            }else{
                temp = temp->lChild;
            }
        }
        if(key > parent->data){
            parent->rChild = newNode;
        }else{
            parent->lChild = newNode;
        }
    }
}

int main(){
    insert(5);
    insert(4);
    insert(3);
    insert(10);
    printf("%d", heighOfTree(root));
    return 0;
}