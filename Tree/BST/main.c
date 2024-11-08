#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

struct Node {
    int data;
    struct Node *lChild , *rChild;
}*root = NULL;

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

// Recursive Insert 
// TC : O(nlogn)
// SC : O(h)
struct Node *RInsert(struct Node *p ,int key){
    struct Node *temp;
    if(p== NULL){ // if root is empty
        temp = createNode(key);
        return temp;
    }
    if(key < p->data){
        p->lChild = RInsert(p->lChild, key);
    }else{
        p->rChild = RInsert(p->rChild , key);
    }
    return p;
}

// display 

void preOrder(struct Node *p){
    if(p){
        printf(" %d " , p->data);
        preOrder(p->lChild);
        preOrder(p->rChild);
    }
}

void inOrder(struct Node *p){
    if(p){
        inOrder(p->lChild);
        printf("%d " , p->data);
        inOrder(p->rChild);
    }
}

void postOrder(struct Node *p){
    if(p){
        postOrder(p->lChild);
        postOrder(p->rChild);
        printf(" %d " , p->data);
    }
}


// search : TC : O(logn) bcoz O(logn) <= h <= n
struct Node *search(struct Node *t , int key){
    while(t!=NULL){
        if(key == t->data){
            return t;
        }
        if(key < t->data){
            t = t->lChild;
        }else{
            t = t->rChild;
        }
    }
    return NULL;
}

// Recursive Search 
struct Node *RS(struct Node *t , int key){
    if(t == NULL){
        return NULL;
    }
    if(key == t->data){
        return t;
    }else if(key < t->data){
        return RS(t->lChild , key);
    }else{
        return RS(t->rChild , key);
    }
}

int height(struct Node *p){
    int x , y;
    if(p){
        x = height(p->lChild);
        y = height(p->rChild);
        if(x >y){
            return x + 1;
        }else{
            return y + 1;
        }
    }
    return -1;
}

struct Node * inPre(struct Node *p){
    while(p && p->rChild != NULL){
        p = p->rChild;
    }
    
    return p;
}

struct Node * inSucc(struct Node *p){
    while(p && p->lChild != NULL){
        p = p->lChild;
    }
    
    return p;
}

struct Node *delete(struct Node *p , int key){
    struct Node *q;
    
    if(p == NULL){
        return NULL;
    }
    
    if(p->lChild == NULL && p->rChild== NULL){
        if(p == root){
            root = NULL;
        }
        free(p);
        return NULL;
    }
    
    if(key <  p->data){
        p->lChild = delete(p->lChild , key);
    }else if(key > p->data){
        p->rChild = delete(p->rChild , key);
    }else{
        if(height(p->lChild) > height(p->rChild)){
            q = inPre(p->lChild);
            p->data = q->data;
            p->lChild = delete(p->lChild , q->data);
        }else{
            q = inSucc(p->rChild);
            p->data = q->data;
            p->rChild =delete(p->rChild , q->data);
        }
    }
    
    return p;
}

// Delete Iterative 
void deleteI(int key){
    struct Node *p  = root; 
    struct Node *parent,*pred;
    while(p && p->data != key){
        parent = p;
        if(key < p->data){
            p = p->lChild;
        }else{
            p = p->rChild;
        }
    }

    // case 1 : Value not foud.
    if(p == NULL){
        printf("Value Not Found.");
    }// case 2 : Leaf node
    else if(!p->lChild && !p->rChild){
        if(p == parent->rChild){ // if it is a right child
            parent->rChild = NULL;
            free(p);
        }else{ // other wise left child
            parent->lChild = NULL;
            free(p);
        }
    }// case 3(i) : if p's left child present
    else if(p->lChild && !p->rChild){ 
        if(p == parent->lChild){
            parent->lChild = p->lChild;
        }else{
            parent->rChild = p->lChild;
        }
        free(p);
    }// case 3(ii) : if p's right child present
    else if(!p->lChild && p->rChild){
        if(p == parent->lChild){
            parent->lChild = p->rChild;
        }else{
            parent->rChild = p->rChild;
        }
        free(p);
    }// case 4 : if p has 2 children
    else {
        parent = p;
        pred = p->lChild;

        // identify inoder predecessor 
        while(pred->rChild){
            parent = pred;
            pred = pred->rChild;
        }

        p->data = pred->data;
        parent->rChild = pred->lChild;
        free(pred);
    }
}

// Generate BST from PreOrder
// TC : O(n)
void createFromPre(int A[] , int n){
    struct Node *t , *p;
    struct Stack st;
    createStack(&st , 100);
    int i = 0;

    // Initial step
    root = createNode(A[i++]);
    p = root;

    // Repeatingn steps
    while(i < n){
        // left child case
        if(A[i] < p->data){
            t = createNode(A[i++]);
            p->lChild = t;
            push(&st , p);
            p = t;
        }// right child case 
        else if(A[i] > p->data && A[i] < (isStackEmpty(&st) ? 32767 : stackTop(&st)->data)){
            t = createNode(A[i++]);
            p->rChild = t;
            p = t;
        }else{
            p = pop(&st);
        }
    }
}

// TC : O(n) , SC : O(h)
struct Node *mirror(struct TreeNode* root) {
    if(root == NULL){
        return NULL;
    }

    struct TreeNode *left = mirror(root->left);
    struct TreeNode *right = mirror(root->right);

    root->left = right;
    root->right = left;

    return root;
}

// find min value 
int minValue(struct Node *p){
    if(p->lChild){
        return minValue(p->lChild);
    }else {
        return p->data;
    }
}

// find max value 
int maxVaue(struct Node *p){
    if(p->rChild){
        return maxVaue(p->rChild);
    }else {
        return p->data;
    }
}

// find depth of a node 
int depthNode(struct Node *root , int value , int depth){
    // if node is empty
    if(root == NULL){
        return -1;
    }
    
    // if the node's data match with given value 
    if(root->data == value){
        return depth;
    }
    
    int leftDepth = depthNode(root->lChild , value , depth+1);
    // if value is identified in the left subtree
    if(leftDepth != -1){
        return leftDepth;
    }
    
    // search value in right subtree
    return depthNode(root->rChild , value ,depth+1);
}

struct Node *copyTree(struct Node *root){
    if(root == NULL){
        return NULL;
    }

    // create a newnode as root with same data
    struct Node *newNode = createNode(root->data);

    // recursively copy left and right children
    newNode->lChild = copyTree(root->lChild);
    newNode->rChild = copyTree(root->rChild);

    // return copied tree
    return newNode;
}

int main(){
    int choice , key;
    struct Node *temp;
    int A[] = {100 , 50 , 25 , 10 , 35 , 30 , 75 , 65 , 60 , 90 , 80 , 150 , 125 , 110 , 115 , 135 , 130 , 175 , 165 , 160 , 190 , 180};
    while(1){
        printf("\n========== Menu ==========\n");
        printf("1. Iterative Insert: \n");
        printf("2. Recursive Insert: \n");
        printf("3. Recursive PreOrder Traversal\n");
        printf("4. Recursive InOrder Traversal\n");
        printf("5. Recursive PostOrder Traversal\n");
        printf("6. Iterative Search\n");
        printf("7. Recursive Search\n");
        printf("8. Height\n");
        printf("9. Inorder Predecessor\n");
        printf("10. Inorder Successor\n");
        printf("11. Recursive Delete\n");
        printf("12. Generate Tree From PreOrder\n");
        printf("13. Delete Iterative\n");
        printf("14. Mirror of a tree\n");
        printf("15. Min value\n");
        printf("16. Max value\n");
        printf("17. Depth of a node\n");
        printf("18. Copy Tree\n");
        printf("19. Exit\n");
        printf("===========================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice)
        {
        case 1:
            printf("\nEnter the value to insert : ");
            scanf("%d" , &key);
            insert(key);
            break;
        case 2:
            printf("\nEnter the value to insert : ");
            scanf("%d" , &key);
            root = RInsert(root , key);
            break;
        case 3:
            printf("\nRecursive PreOrder : ");
            preOrder(root);
            break;
        case 4:
            printf("\nRecursive InOrder : ");
            inOrder(root);
            break;
        case 5:
            printf("\nRecursive PostOrder : ");
            postOrder(root);
            break;
        case 6:
            printf("Enter the value to search : ");
            scanf("%d", &key);
            temp = search(root , key);
            if(temp){
                printf("\n %d Element is present." , key);
            }else{
                printf("\n %d Elemetn is not present." , key);
            }
            break;
        case 7:
            printf("Enter the value to search : ");
            scanf("%d", &key);
            temp = RS(root , key);
            if(temp){
                printf("\n %d Element is present." , key);
            }else{
                printf("\n %d Elemetn is not present." , key);
            }
            break;
        case 8:
            printf("\nHeight : %d" , height(root));
            break;
        case 9:
            temp = inPre(root->lChild);
            printf("\nInorder Predecessor : %d" , temp->data);
            break;
        case 10:
            temp = inSucc(root->rChild);
            printf("\nInorderr Successor : %d" , temp->data);
            break;
        case 11:
            printf("\nEnter the value to delete : ");
            scanf("%d", &key);
            delete(root , key);
            break;
        case 12:
            createFromPre(A , 22);
            printf("\nTree Created...");
            break;
        case 13:
            printf("\nEnter the value to delete :");
            scanf("%d" , &key);
            deleteI(key);
            break;
        case 14:
            root = mirror(root);
            printf("\nMirror is created..");
            break;
        case 15:
            printf("\nMin Value : %d", minValue(root));
            break;
        case 16:
           printf("\nMax Value : %d", maxVaue(root));
            break;
        case 17:
           int value;
           printf("Enter the Node element to find depth : ");
           scanf("%d" , &value);
           printf("\n Depth of a node's Element %d : %d",value , depthNode(root, value , 0));
            break;
        case 18:
            struct Node *copiedTree = copyTree(root);
            printf("Copy Tree inorder traversal : ");
            inOrder(copiedTree);
            break;
        case 19:
            printf("\nExiting...");
            return 0;
        
        default:
            break;
        }
    }

    return 0;
}