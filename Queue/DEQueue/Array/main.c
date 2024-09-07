#include<stdio.h>
#include<stdlib.h>

struct Queue{
    int size;
    int front;
    int rear;
    int *Q;
};

void enqueueR(struct Queue *q , int x){
    if(q->rear == q->size-1){
        printf("Queue is full");
    }else{
        q->rear++;
        q->Q[q->rear] = x;
    }
}

void enqueueF(struct Queue *q , int x){
    if(q->front == -1){
        printf("Queue is full");
    }else{
        q->Q[q->front] = x;
        q->front--;
    }
}

int dequeueR(struct Queue *q){
    int x = -1;
    if(q->front == q->rear){
        printf("Queue is empty.");
    }else{
        x = q->Q[q->rear];
        q->rear--;
    }
    return x;
}

int dequeueF(struct Queue *q){
    int x = -1;
    if(q->front == q->rear){
        printf("Queue is empty.");
    }else{
        q->front++;
        x = q->Q[q->front];
    }
    
    return x;
}

void display(struct Queue *q){
    if(q->front == q->rear){
        printf("Queue is empty.");
    }
    int i = q->front +1;
    while(i <= q->rear){
        printf("\nElement : %d" , q->Q[i]);
        i++;
    }
}

int main(){
    struct Queue q;
    printf("Enter the size of the Queue : ");
    scanf("%d" , &q.size);

    q.front = q.rear = -1;
    q.Q = (int *)malloc(q.size * sizeof(int));

    int choice, value;

    while(1){
        printf("\nEnter your choice : ");
        printf("\n1.Enqueue using rear");
        printf("\n2.Enqueue using front");
        printf("\n3.Dequeue using rear");
        printf("\n4.Dequeue using front");
        printf("\n5.Display");
        printf("\n6.Exit\n");
        scanf("%d" , &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the value to insert: ");
            scanf("%d" , &value);
            enqueueR(&q , value);
            break;
        case 2:
            printf("Enter the value to insert: ");
            scanf("%d" , &value);
            enqueueF(&q , value);
            break;
        case 3:
            value = dequeueR(&q);
            if(value !=-1){
                printf("\nDeleted Element : %d" , value);
            }
            break;
        case 4:
           value = dequeueF(&q);
            if(value !=-1){
                printf("\nDeleted Element : %d" , value);
            }
            break;
        case 5:
            display(&q);
            break;
        case 6:
            exit(0);            
        default:
            printf("\n Invalid choice.\n");
            break;
        }
    }

    return 0;
}
