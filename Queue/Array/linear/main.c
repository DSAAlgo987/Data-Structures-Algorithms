#include<stdio.h>
#include<stdlib.h>

struct Queue{
    int size;
    int front;
    int rear;
    int *Q;
};

void enqueue(struct Queue *q , int data){
    if(q->rear == q->size-1){
        printf("Queue is full.");
    }else{
        q->rear++;
        q->Q[q->rear] = data;
    }
}

int dequeue(struct Queue *q){
    int x = -1;

    if(q->front == q->rear){
        printf("Queue is empty.");
    }else{
        q->front++;
        x = q->Q[q->front];
    }
    return x;
}

void display(struct Queue *q) {
    if (q->front == q->rear) {
        printf("Queue is empty\n");
        return;
    }

    // Use a temporary index to iterate through the queue
    int i = q->front + 1;

    printf("Queue elements: ");
    while (i <= q->rear) {
        printf("%d ", q->Q[i]);
        i++;
    }
    printf("\n");
}

int main(){
    // Initialization of Queue
    struct Queue q;
    // printf("Enter the size of the queue : ");
    // scanf("%d" , &q.size);
    q.size = 7;    
    q.Q = (int *)malloc(q.size * sizeof(int));
    q.front = q.rear = -1;

    enqueue(&q , 10);
    enqueue(&q , 20);
    enqueue(&q , 30);
    enqueue(&q , 40);

    display(&q);

    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);

    display(&q);
    
    return 0;
}