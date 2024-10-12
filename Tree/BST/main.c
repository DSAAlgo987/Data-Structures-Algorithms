#include <stdio.h>
#include <stdlib.h>

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

int main(){
    int choice , key;
    struct Node *temp;
    while(1){
        printf("\n========== Menu ==========\n");
        printf("1. Iterative Insert: \n");
        printf("2. Recursive Insert: \n");
        printf("3. Recursive PreOrder Traversal\n");
        printf("4. Recursive InOrder Traversal\n");
        printf("5. Recursive PostOrder Traversal\n");
        printf("6. Iterative Search\n");
        printf("7. Recursive Search\n");
        printf("8. Exit\n");
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
            root = insert(key);
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
            root = insert(key);
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
        
        default:
            break;
        }
    }

    return 0;
}