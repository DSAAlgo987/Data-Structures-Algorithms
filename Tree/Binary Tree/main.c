#include <stdio.h>
#include "operations.h"

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


int main()
{
    createTree();
    
    printf("Tree Traversal : \n");
    printf("\nPreOrder : ");
    preOrder(root);
    printf("\nInOrder : ");
    inOrder(root);
    printf("\nPostOrder : ");
    postOrder(root);

    printf("\n");
    insert();
    preOrder(root);
    return 0;
}
