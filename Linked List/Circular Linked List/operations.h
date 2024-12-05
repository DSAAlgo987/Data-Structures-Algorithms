#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
}*start = NULL;

struct Node *createNode(int data){
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;

    return temp;
}

void create(){
    int n , value;
    struct Node *temp, *newNode;

    // printf("Enter the no of nodes : ");
    // scanf("%d" , &n);

    for(int i = 0 ; i < 5 ; i++){
        // printf("Enter the value for the Node %d " , i+1);
        // scanf("%d" , &value);

        newNode = createNode(i+1);
        if(start == NULL){
            start = newNode;
            newNode->next = start; //Circular linked list
        }else {
            temp = start;
            while(temp->next != start){
                temp = temp->next;
            }

            temp->next = newNode;
            newNode->next = start;
        }
    }
}

void insertBefore(){
    struct Node *temp , *newNode , *prev , *last;
    int x =3, value;

    // printf("Enter the value before which you want to insert : ");
    // scanf("%d" , &x);

    // printf("Enter the value ot insert : ");
    // scanf("%d" , &value);

    newNode = createNode(10);

    temp = start;
    while(temp->data != x){
        prev = temp;
        temp = temp->next;
    }

    // case 1 : if temp first node
    if(temp == start){
        last = temp;
        while(last->next != start){
            last = last->next;
        }

        last->next = newNode;
        newNode->next = start;
    }else{ // case 2 : between 
        prev->next = newNode;
        newNode->next = temp;
    }
}

void insertAfter(){
    struct Node *temp , *newNode;
    int x = 5 , value;

    // printf("Enter the value after which you want to insert : ");
    // scanf("%d" , &x);

    // printf("Enter the value ot insert : ");
    // scanf("%d" , &value);

    newNode = createNode(15);

    temp = start;
    while(temp->data != x){
        temp=temp->next;
    }   

    newNode->next = temp->next;
    temp->next = newNode;    
}

void deleteElement(){
    struct Node *temp ,*prev, *last;
    int x = 1;

    // printf("Enter the value to delete :");
    // scanf("%d" , &x);
    temp = start;
    while(temp->next != start && temp->data != x){
        prev = temp;
        temp = temp->next;
    }

    if(temp->data !=x){
        printf("Value not found!\n");
    }else if(temp == start){// case 2 : if temp is a first node 
        last = temp;
        while(last->next != start){
            last = last->next;
        }
        last->next = temp->next;
        start = start->next;
        free(temp);
    }else{
        prev->next = temp->next;
        free(temp);
    }
}

void traverse(){
    struct Node *temp = start;
    if(start == NULL){
        printf("List is empty!");
    }

    do{
        printf("Element : %d\n" , temp->data);
        temp = temp->next;
    }while(temp != start);
}

void insertBeforePos(){
    int x, value;
    struct Node *newNode , *temp , *prev;
    
    printf("Enter the position before which you want to insert : ");
    scanf("%d" , &x);
    
    printf("Enter the value to insert : ");
    scanf("%d" , &value);
    
    newNode = createNode(value);
    
    temp = start;
    for(int i = 1 ; i<x && temp->next !=start; i++){
        prev = temp;
        temp = temp->next;
    }
    
    if(temp == start){ // before first node 
        struct Node *last = temp;
        while(last->next != start){
            last = last->next;
        }
        last->next = newNode;
        newNode->next = start;
        start = newNode;
    }else { // before middle and last node 
        prev->next =newNode;
        newNode->next = temp;
    }
}

void insertAfterPos(){
    int x , value;
    struct Node *newNode , *temp;
    
    printf("Enter the position after which you want to insert : ");
    scanf("%d" , &x);
    
    printf("Enter the value to insert : ");
    scanf("%d", &value);
    
    newNode = createNode(value);
    
    temp = start;
    
    for(int i = 1 ; i < x  && temp->next != start ; i++){
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void deletePos(){
    int x , i;
    struct Node *temp , *prev , *last;
    
    printf("Enter the position to delete : ");
    scanf("%d" , &x);
    
    temp = start;
    for( i = 1 ;i != x && temp->next != start ; i++){
        prev = temp;
        temp = temp->next;
    }
    
    if(i != x){
        printf("value not found");
        return;
    }else if(temp == start){
        last = temp;
        while(last->next != start){
            last = last->next;
        }
        
        start = temp->next;
        last->next = start;
        free(temp);
    }else {
        prev->next = temp->next;
        free(temp);
    }
}

    int x;
    struct Node *temp = start, *prev= NULL;
    
    printf("Enter the node's position to delete : ");
    scanf("%d" , &x);
    
    // for 1st node 
    if(x == 1){
        struct Node *last = start;
        while(last->next !=  start){
            last = last->next;
        }
        
        last->next = start->next;
        start = start->next; 
        free(temp);
        return;
    }
    
    // for other nodes 
    for(int i = 1 ; i<x; i++){
        prev = temp;
        temp = temp->next;
        if(temp == start){ // if it is loopback to stack 
            printf("Index out of bound.");
            return; // we should exit from this so deletion will not happend
        }
    }
    
    // delete between and last node 
    prev->next = temp->next;
    free(temp);
}