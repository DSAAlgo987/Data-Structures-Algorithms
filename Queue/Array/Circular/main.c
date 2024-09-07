#include<stdio.h>
#include<stdlib.h>

struct Queue{
    int size;
    int front;
    int rear;
    int *Q;
};

// time complexity : O(1)
void enqueue(struct Queue *q , int x){
    if((q->rear +1) %q->size == q->front ){
        printf("Queue is full.");
    }else{
        // to iterate cicularary
        q->rear = (q->rear +1 ) % q->size;
        q->Q[q->rear] = x;
    }
}

// time complexity : O(1)
int dequeue(struct Queue *q){
    int x = -1;
    if(q->rear == q->front){
        printf("Queue is empty.");
    }else{
        // to iterate cicularary
        q->front = (q->front + 1)% q->size;
        x = q->Q[q->front];
    }

    return x;
}

void display(struct Queue *q){
    if(q->rear == q->front){
        printf("Queue is empty.");
        return;
    }
    // to iterate cicularly
    int i = q->front +1;
    while( i != (q->rear + 1) % q->size){
        printf("\nElement : %d" , q->Q[i]);
        i = (i+1) % q->size;
    }
}



int main(){
    struct Queue q;
    printf("Enter the size of the queue : ");
    scanf("%d" , &q.size);

    // initialize q's front and rear
    q.front = q.rear = 0;

    q.Q = (int *)malloc(q.size * sizeof(int));
    int value, choice , x;
    while(1){
        printf("\nEnter  your choice : ");
        printf("\n1.Enqueue \n2.Dequeue \n3.Display \n4.Exit\n");
        scanf("%d" , &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the element to insert : ");
            scanf("%d" ,&value);
            enqueue(&q , value);
            break;
        case 2:
            x = dequeue(&q);
            if(x !=-1){
                printf("\n %d element is deleted from the queue.\n" , x);
            }
            break;
        case 3:
            display(&q);
            break;
        case 4:
            exit(0);

        default:
            printf("\n Invalid choice.\n");
            break;
        }
    }

    return 0;
}