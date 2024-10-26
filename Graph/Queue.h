#include <stdlib.h>
struct Queue{
    int size;
    int front;
    int rear;
    int *Q;
};

struct Queue createQueue(int size) {
    struct Queue q;
    q.size = size;
    q.Q = (int *)malloc(q.size * sizeof(int));
    q.front = q.rear = -1;

    return q;
}
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

int isEmpty(struct Queue *q){
    return (q->front == q->rear)? 1 : 0;
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