#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
}*front = NULL , *rear = NULL;

struct Node *newNode(int x){
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    if(temp==NULL){
        printf("Queue is full");
    }
    temp->data = x;
    temp->next = NULL;
    return temp;
}

// time complexity : O(1);
void enqueue(int x){
    struct Node *nNode = newNode(x);

    // first Node
    if(front == NULL){
        front = rear =  nNode;
    }else{
        rear->next = nNode;
        rear = nNode;
    }
}

// time complexity : O(1);
int dequeue(){
    int x=-1;
    struct Node *temp;
    if(front == NULL){
        printf("Queue is empty.");
    }else{
        temp = front;
        front = front->next;
        x = temp->data;
        free(temp);
    }
    return x;
}

void display(){
    struct Node *temp = front;
    if(front == NULL){
        printf("Queue is empty");
    }
    while(temp!=NULL){
        printf("\n Element : %d" , temp->data);
        temp=temp->next;
    }
}

int main(){
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
            enqueue(value);
            break;
        case 2:
            x = dequeue();
            if(x !=-1){
                printf("\n %d element is deleted from the queue.\n" , x);
            }
            break;
        case 3:
            display();
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