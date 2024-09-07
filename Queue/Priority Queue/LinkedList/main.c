// 10 / 2 , 20/ 1 , 30/1 , 40 /2 , 100/3
// 20 / 1 , 30 /1 , 10/2 , 40/2 , 100/3

#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    int priority;
    struct Node *next;
}*front = NULL;

struct Node *newNode(int data , int priority){
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    if(temp == NULL){
        printf("Queue is full");
    }
    temp->data = data;
    temp->priority = priority;
    temp->next = NULL;

    return temp;
}

int isEmpty(){
    return (front == NULL) ? 1 : 0;
}

void enqueue(int value , int priority){
    struct Node *temp,*prev , *nNode = newNode(value , priority);
    temp = front;
    // If the queue is empty or the new node has higher priority than the front
    if(front == NULL || nNode->priority < front->priority){
        nNode->next = front;
        front = nNode;   
    }else{
        while(temp != NULL && nNode->priority >= temp->priority){
            prev = temp;
            temp = temp->next;
        }
        // Insert the new node after prev
        prev->next = nNode;
        nNode->next = temp;
    }
}

int dequeue(){
    struct Node *temp = front;
    int x = -1;
    if(isEmpty()){
        printf("Queue is empty.");
    }else{
        x = temp->data;
        front = front->next;
        free(temp);
    }

    return x;
}

void display(){
    struct Node *temp = front;
    while(temp!=NULL){
        printf("%d " , temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){

    enqueue(10 , 2);
    enqueue(20 , 1);
    enqueue(30 , 1);
    enqueue(40 , 2);
    enqueue(100 , 3);
    display();

    dequeue();
    dequeue();
    dequeue();

    display();


    return 0;
}

