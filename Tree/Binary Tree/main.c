#include <stdio.h>
#include "operations.h"
#include "stack.h"

struct Node *root = NULL;

// Creation of binary tree 
void createTree(){
    struct Node *p, *temp;
    int value;
    
    struct Queue q; 
    createQ(&q , 100); // creation of queue 
    
    printf("Enter the value for Root Node : ");
    scanf("%d" , &value);
    
    root = createNode(value); // root node creation 
    enqueue(&q , root);
    while(!isEmpty(&q)){
        p = dequeue(&q);
        printf("Enter the left child for %d : " , p->data);
        scanf("%d" , &value);
        if(value != -1){
            temp = createNode(value);
        
            p->lChild = temp;
            enqueue(&q ,temp);
        }
        
        printf("Enter the right child for %d : " , p->data);
        scanf("%d" , &value);
        if(value != -1){
            temp = createNode(value);
        
            p->rChild = temp;
            enqueue(&q , temp);
        }
    }
}

void preOrder(struct Node *p){
    if(p){
        printf("%d" , p->data);
        preOrder(p->lChild);
        preOrder(p->rChild);
    }
}

void inOrder(struct Node *p){
    if(p){
        inOrder(p->lChild);
        printf("%d" , p->data);
        inOrder(p->rChild);
    }
}

void postOrder(struct Node *p){
    if(p){
        postOrder(p->lChild);
        postOrder(p->rChild);
        printf("%d" , p->data);
    }
}

void IPreOder(struct Node *t) {
    struct Stack st;
    createStack(&st , 100);

    // While there are nodes to process
    while (t != NULL || !isStackEmpty(&st)) {
        if (t != NULL) {
            printf("%d ", t->data);  // Visit the node (Pre-order)
            push(&st, t);  // Push the current node to the stack
            t = t->lChild;  // Move to the left child
        } else {
            t = pop(&st);  // Pop the node from the stack
            t = t->rChild;  // Move to the right child
        }
    }
}


void IInOrder(struct Node *t){
    struct Stack st;
    createStack(&st , 100);
    
    while(t != NULL || !isStackEmpty(&st)){
        if(t){
           push(&st , t);
           t = t-> lChild;
        }else{
            t = pop(&st);
            printf("%d" , t->data);
            t = t->rChild;
        }
    }
}

void insert(){
    struct Node *temp , *newNode , *parent;
    int value;
    
    printf("Enter the value to insert : ");
    scanf("%d" , &value);
    
    newNode = createNode(value);
    
    if(root == NULL){
        root = newNode;
    }else{
        temp = root;
        while(temp!=NULL){
            if(value > temp->data){
                parent = temp;
                temp = temp->rchild;
            }else{
                parent = temp;
                temp = temp->lchild;
            }
        }
        
        if(value > parent->data){
            parent->rchild = newNode;
        }else{
            parent->lchild = newNode;
        }
    }
}

void IPostOrder(struct Node *t){
     struct Stack st;
    createStack(&st, 100); // Initialize stack with size 100
    long int temp;
    
    while (t != NULL || !isStackEmpty(&st)) {
        if (t != NULL) {
            push(&st, (long int)t);  // Push node's address to the stack
            t = t->lChild;  // Move to the left child
        } else {
            temp = pop(&st);  // Pop the top element from the stack
            
            if (temp > 0) {  // If it's a positive value (node address)
                push(&st, -temp);  // Mark the node as processed by pushing a negative value
                t = ((struct Node *)temp)->rChild;  // Move to the right child
            } else {  // Negative value means the node has been processed
                printf("%d ", ((struct Node *)(-temp))->data);  // Print the node's data
                t = NULL;  // Set t to NULL to continue popping from the stack
            }
        }
    }
}


void LevelOrder(struct Node *p){
    struct Queue q;
    createQ(&q , 100);

    printf("%d " , p->data);
    enqueue(&q , p);

    while(!isEmpty(&q)){
        p = dequeue(&q);
        if(p->lChild){
            printf("%d " , p->lChild->data);
            enqueue(&q , p->lChild);
        }
        if(p->rChild){
            printf("%d " , p->rChild->data);
            enqueue(&q , p->rChild);
        }
    }    
}

int countInternal(struct Node *p){
    if(p){
        if( p->lChild || p->rChild){
            return countInternal(p->lChild) + countInternal(p->rChild) + 1;
        }
    }
    return 0;
}

int height(struct Node *p){
    int x , y;
    if(p){
        x = height(p->rChild);
        y = height(p->lChild);
        if(x > y){
            return x + 1;
        }else {
            return y + 1;
        }
    }
    return -1;
}

int level(struct Node *p){
    int x , y;
    if(p){
        x = level(p->rChild);
        y = level(p->lChild);
        if(x > y){
            return x + 1;
        }else {
            return y + 1;
        }
    }
    return 0;
}


int main()
{
    int choice;
    while(1){
        printf("\n========== Menu ==========\n");
        printf("1. Create Binary Tree\n");
        printf("2. Iterative PreOrder Traversal\n");
        printf("3. Recursive PreOrder Traversal\n");
        printf("4. Iterative InOrder Traversal\n");
        printf("5. Recursive InOrder Traversal\n");
        printf("6. Iterative PostOrder Traversal\n");
        printf("7. Recursive PostOrder Traversal\n");
        printf("8. Level Order Traversal\n");
        printf("9. Count Nodes\n");
        printf("10. Count of Internal Nodes\n");
        printf("11. Count of External Nodes\n");
        printf("12. Height\n");
        printf("13. Level\n");
        printf("14. Exit\n");
        printf("===========================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                createTree();
                break;
            case 2:
                printf("\nIterative PreOrder: ");
                IPreOrder(root);
                break;
            case 3:
                printf("\nRecursive PreOrder: ");
                preOrder(root);
                break;
            case 4:
                printf("\nIterative InOrder: ");
                IInOrder(root);
                break;
            case 5:
                printf("\nRecursive InOrder: ");
                inOrder(root);
                break;
            case 6:
                printf("\nIterative PostOrder: ");
                IPostOrder(root);
                break;
            case 7:
                printf("\nRecursive PostOrder: ");
                postOrder(root);
                break;
            case 8:
                printf("\nLevel Order Traversal: ");
                LevelOrder(root);
                break;
            case 9:
                printf("\nCount Of Nodes: %d" , count(root));
                break;
            case 10:
                printf("\nCount Of Internal Nodes: %d" , countInternal(root));
                break;
            case 11:
                printf("\nCount Of External Nodes: %d" , count(root) - countInternal(root));
                break;
            case 12:
                printf("\nHeight: %d" , height(root));
                break;
            case 13:
                printf("\nLevel: %d" , level(root));
                break;
            case 14:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Please select a valid option.\n");
        }
        
    }
    return 0;
}
