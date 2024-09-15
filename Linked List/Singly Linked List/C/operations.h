#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


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
    int n = 5, value;
    struct Node *newNode , *temp;
    // printf("Enter the no of nodes to insert : ");
    // scanf("%d" , &n);
    
    for(int i = 0 ; i< n ; i++){
        // printf("Enter the value for node %d : " , i+1);
        // scanf("%d" ,&value );
        newNode = createNode(i+1);
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

struct Node *reverse(struct Node *head){
    struct Node *p , *q , *r;
    p = head;
    q = NULL;
    r = NULL;
    
    while(p){
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    
    return q;
}

bool isPalindrome(struct Node *head){
    if(head->next == NULL){
        return true;
    }
    
    // step 1 : find the middle value 
    struct Node *slow , *fast;
    slow = fast = head;
    
    while(fast != NULL && fast->next != NULL){
        fast = fast->next->next;
        if(fast!=NULL){
            slow = slow->next;
        }
    }
    
    // step 2 : reverse list
    struct Node *secondHalf = reverse(slow->next);
    
    // step 3 : check the value if it is equal or not with head list
    while(secondHalf !=NULL){
        if(head->data != secondHalf->data){
            return false;
        }
        secondHalf = secondHalf->next;
        head = head->next;
    }
    return true;
}

struct Node *oddEvenList(struct Node *head){
    struct Node *odd , *even , *even_start;
    odd = head;
    even = even_start = head->next;
    
    while(odd->next!=NULL && even->next != NULL){
        odd->next = even->next;
        even->next = odd->next->next;
        odd = odd->next;
        even = even->next;
    }
    
    odd->next = even_start;
    
    return head;
}

int avg(){
    struct Node *temp = start;
    int count = 0, sum = 0 ,avg;
    if(temp == NULL){
        return -1;
    }

    // traverse temp to identify count and sum 
    while(temp!= NULL){
        count++;
        sum += temp->data;
        temp=temp->next;
    }

    return avg = sum / count;

}