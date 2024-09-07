#include <stdio.h>
#include <stdlib.h>

struct Queue{
    int size;
    int front;
    int rear;
    char *Q;
};

void create(struct Queue *q , int size){
    q->size = size;
    q->front = q->rear = -1;
    q->Q = (char *)malloc(q->size * sizeof(char));
}

int isEmpty(struct Queue *q){
    return (q->front == q->rear) ? 1 : 0;
}

int isFull(struct Queue *q){
    return (q->rear == q->size-1) ? 1 : 0;
}

void enqueue(struct Queue *q , char ele){
    if(!isFull(q)){
        q->rear++;
        q->Q[q->rear] = ele;
    }else{
        printf("Queue is full.");
    }
}

int dequeue(struct Queue *q){
    int x = -1;
    if(!isEmpty(q)){
        q->front++;
        x = q->Q[q->front];
    }else{
        printf("Queue is empty.");
    }
    return x;
}

void insert(struct Queue *q1 , struct Queue *q2 , struct Queue *q3 , char ele , int pre){
    if(pre == 1){
        enqueue(q1 , ele);
    }else if(pre == 2){
        enqueue(q2 , ele);
    }else{
        enqueue(q3 , ele);
    }
}

int delete(struct Queue *q1 , struct Queue *q2 , struct Queue *q3){
    int x = -1;
    if(!isEmpty(q1)){
        x = dequeue(q1);
    }else if(!isEmpty(q2)){
        x = dequeue(q2);
    }else{
        x = dequeue(q3);
    }
    return x;
}

void display(struct Queue *q){
    if(isEmpty(q)){
        printf("Queue is Empty.");
    }else{
        int i = q->front +1;
        while(i <= q->rear){
            printf("%c " , q->Q[i++]);
        }
        printf("\n");
    }
}

int main(){
    struct Queue q1;
    struct Queue q2;
    struct Queue q3;

    create(&q1 , 10);
    create(&q2 , 10);
    create(&q3 , 10);

    insert(&q1 , &q2 , &q3 , 'A' , 1);
    insert(&q1 , &q2 , &q3 , 'B' , 1);
    insert(&q1 , &q2 , &q3 , 'C' , 2);
    insert(&q1 , &q2 , &q3 , 'D' , 3);
    insert(&q1 , &q2 , &q3 , 'E' , 2);
    insert(&q1 , &q2 , &q3 , 'F' , 1);
    insert(&q1 , &q2 , &q3 , 'G' , 2);
    insert(&q1 , &q2 , &q3 , 'H' , 3);
    insert(&q1 , &q2 , &q3 , 'I' , 2);
    insert(&q1 , &q2 , &q3 , 'J' , 2);

    display(&q1); display(&q2); display(&q3);

    delete(&q1 , &q2 , &q3);
    delete(&q1 , &q2 , &q3);
    delete(&q1 , &q2 , &q3);
    delete(&q1 , &q2 , &q3);

    printf("\n\n\n");

    display(&q1);display(&q2);display(&q3);printf("\n\n\n");

    insert(&q1,&q2,&q3,'Z',2);insert(&q1,&q2,&q3,'W',1);

    display(&q1);display(&q2);display(&q3);

    return 0;
}