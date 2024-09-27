#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coef;
    int power;
    struct Node *next;
}*start = NULL;


struct Node* createNode(int coef , int power ){
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->coef = coef;
    temp->power = power;
    temp->next = NULL;
    
    return temp;
}


void createPolynomial(){
    int terms, coef , power;
    struct Node *newNode , *temp;
    printf("Enter the no of terms in polynomial : ");
    scanf("%d" , &terms);
    
    for(int i = 0 ; i < terms ; i++){
        
        printf("Enter the coeficient for term %d : " , i+1);
        scanf("%d" , &coef);
        
        printf("Enter the power for term %d : " , i+1);
        scanf("%d" , &power);
        
        newNode = createNode(coef , power);
        
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


void displayPolynomial(){
    struct Node *temp=start;
    while(temp!= NULL){
        if(temp->coef < 0){
            printf(" - %dx^%d" , temp->coef , temp->power);
        }else{
            if (temp != start) {
                printf(" + ");  // Add "+" sign between terms, but not before the first term
            }
            printf("%dx^%d", temp->coef, temp->power);
        }
        temp = temp->next;
    }
}