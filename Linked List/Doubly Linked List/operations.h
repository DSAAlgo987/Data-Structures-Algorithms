#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
}*start = NULL;

struct Node* createNode(int x){
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = NULL;
    temp->prev = NULL;

    return temp;
}

void create(){
    struct Node *temp , *newNode;
    int n = 5, value;

    // printf("Enter the no of nodes to insert :");
    // scanf("%d" , &n);

    for(int i = 0 ; i < n ; i++){
        // printf("Enter the value for node %d" , i+1);
        // scanf("%d" , &value);

        newNode = createNode(i+1);

        // If LL is not created
        if(start == NULL){
            start = newNode;
        }else{
            temp = start;
            while(temp->next != NULL){
                temp = temp->next;
            }

            temp->next = newNode;
            newNode->prev = temp;
        }
    }
}

void insertBefore(){
    int x = 5 , value = 10;
    struct Node *newNode , *temp , *prev;
    // printf("Enter the value before which you want to insert : ");
    // scanf("%d" , &x);

    // printf("Enter the value to insert : ");
    // scanf("%d" , &value);
    newNode = createNode(value);
    
    temp = start;
    while(temp->data != x){
        prev = temp;
        temp = temp->next;
    }

    // case 1 : insert newNode before 1st Node
    if(temp == start){
        newNode->next = temp;
        temp->prev = newNode;
        start = newNode;
    }else{
        // case 2 : insert newNode in between
        newNode->next = temp;
        newNode->prev = prev;
        prev->next = newNode;
        temp->prev = newNode;
    }
}

void insertAfter(){
    struct Node *newNode , *temp , *post;
    int x = 5 , value = 10;

    // printf("Enter the value before which you want to insert : ");
    // scanf("%d" , &x);

    // printf("Enter the value to insert : ");
    // scanf("%d" , &value);
    newNode = createNode(value);

    temp = start;
    while(temp->data != x){
        temp = temp->next;
    }

    post = temp->next;
    temp->next = newNode;
    newNode->prev = temp;

    if(post != NULL){
        newNode->next = post;
        post->prev = newNode;
    }
}

void delete(){
    struct Node *temp , *post , *prev;
    int x = 5;

    // printf("Enter the value to delete : ");
    // scanf("%d" , &x);

    temp = start;
    while(temp->next != NULL && temp->data != x){
        prev = temp;
        temp = temp->next;
    }

    // case 1 : valued not found
    if(temp->data != x){
        printf("Value not found");
    }else if(temp == start){  // case 2 : if temp is a first node 
        post = temp->next;
        if(post != NULL){
            start = post;
            post->prev = NULL;
        }else{
            start = NULL; //list becomes empty
        }
        free(temp);
        return;
    }else{// case 3 : if temp is a middle node or last node
        post = temp->next;
        if(post!=NULL){
            prev->next = post;
            post->prev = prev;
        }else {
            prev->next = post; // if it's the last node
        }
        free(temp);
    }
}

void traverse(){
    if(start == NULL){
        printf("Linked list is empty.");
        return;
    }

    struct Node *p = start;
    struct Node *last;

    printf("\ntraverse in forward direction : ");
    // traverse in forward direction
    while(p != NULL){
        printf("\nElement : %d" , p->data);
        last = p;
        p= p->next;
    }

    printf("\nTraverse in backward direction : ");
    // traverse in backward direction(reverse dispaly linked list)
    while(last != NULL){
        printf("\n Element : %d", last->data );
        last = last->prev;
    }
}