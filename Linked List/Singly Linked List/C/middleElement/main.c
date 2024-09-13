/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>


struct Node{
    int data;
    struct Node *next;
}*start = NULL;

struct Node *createNode(int data){
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    
    return temp;
}

void create(){
    int n, value;
    struct Node *newNode , *temp;
    printf("Enter the no of nodes to insert : ");
    scanf("%d" , &n);
    
    for(int i = 0 ; i< n ; i++){
        printf("Enter the value for node %d : " , i+1);
        scanf("%d" ,&value );
        newNode = createNode(value);
        if(start == NULL){
            start = newNode;   
        }else{
            temp = start;
            while(temp->next != NULL){
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
}

void traverse(){
    struct Node *temp = start;

    if(temp == NULL){
        printf("Linked List is empty");
    }
    while(temp!=NULL){
        printf("\n Element : %d" , temp->data);
        temp = temp->next;
    }
}

int middleNode(){
    struct Node *slow , *fast;
    slow = fast = start;
    
    if(start == NULL){
        printf("Empty LL");
        return -1;
    }
    
    while(fast!=NULL && fast->next !=NULL){
        fast = fast->next->next;
        if(fast!=NULL){
            slow = slow->next;
        }
    }
    
    return slow->data;
}

int main()
{
    // create linked list 
    create();
    
    // traverse 
    traverse();
    
    // middleNode
    printf("\n ELemenet ; %d" , middleNode());
    
    return 0;
}