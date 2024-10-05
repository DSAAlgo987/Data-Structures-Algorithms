#include <stdio.h>
#include <stdlib.h>

// Node structure for Binary Tree
struct Node {
    struct Node *lChild;
    int data;
    struct Node *rChild;
};

// Creation of a Node 
struct Node* createNode(int data){
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->lChild = NULL;
    temp->rChild = NULL;
    
    return temp;
}

struct Queue{
    int size;
    int front;
    int rear;
    struct Node **Q; // bcoz it stores address of the tree node 
};

void createQ(struct Queue *q , int size){
    q->size = size;
    q->front = q->rear = 0;
    q->Q = (struct Node **)malloc(q->size * sizeof(struct Node *));
}

void enqueue(struct Queue *q , struct Node* data){
    if(q->rear == q->size-1){
        printf("Queue is full.");
    }else{
        q->rear++;
        q->Q[q->rear] = data;
    }
}

struct Node * dequeue(struct Queue *q){
    struct Node * x = NULL;

    if(q->front == q->rear){
        printf("Queue is empty.");
    }else{
        q->front++;
        x = q->Q[q->front];
    }
    return x;
}

int isEmpty(struct Queue *q){
    return (q->front == q->rear) ? 1 : 0; 
}
