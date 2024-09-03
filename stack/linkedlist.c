#include <stdlib.h>
#include <stdio.h>

struct Node{
    int data;
    struct Node *next;
}*top=NULL;

struct Node *newNode(int data){
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->next = NULL;
    temp->data = data;
    
    return temp;
}

void push(int x){
    struct Node *nNode;
  
    nNode = newNode(x);
    
    nNode->next = top;
    top = nNode;
}

void display(){
    struct Node *temp = top;
    if(top == NULL){
        printf("List is empty!");
    }else{
        while(temp!=NULL){
            printf("\nElement : %d",temp->data);
            temp = temp->next;
        }
    }
}


int pop(){
    int x =-1;
    struct Node *temp = top;
    if(top == NULL){
        return x;
    }else {
        x = top->data;
        top = top->next;
        free(temp);
        
        return x;
    }
}

// used to return top element
int peek(){
    if(top == NULL){
        return -1;
    }else { 
        return top->data;
    }
}

int main()
{
    
    push(10);
    push(20);
    display();

    int x = pop();
    if (x != -1) {  // Corrected the condition check
        printf("\nValue is deleted from stack: %d\n", x);
    } else {
        printf("\nStack is empty\n");
    }

    display();  // Display the stack after popping

    int topElement = peek();
    if(topElement!=-1){
        printf("\nTop element : %d" , topElement);
    }else{
        printf("\nStack is empty !");
    }

    return 0;
}