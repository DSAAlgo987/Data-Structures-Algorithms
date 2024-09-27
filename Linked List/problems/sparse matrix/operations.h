#include <stdio.h>
#include <stdlib.h>

struct Node {
    int col;
    int data;
    struct Node *next;
};

struct Node *createNode(int col , int data){
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->col = col;
    temp->data = data;
    temp->next = NULL;
    
    return temp;
}

// create 
void createSparseMatrix(struct Node** A , int m , int n){
    struct Node *last ,*newNode;
    int nz, col , value;
    
    for(int i = 0 ; i<m; i++){
        A[i] = NULL;
        printf("Enter the non zero elements for %d row : " , i);
        scanf("%d" , &nz);
        for(int j = 0 ; j<nz ; j++){
            printf("Enter column index and value: ");
            scanf("%d %d", &col, &value);
            newNode = createNode(col ,value);
            
            // case 1 : if it is a first node 
            if(A[i] == NULL){
                A[i] = newNode;
                last = newNode;
            }else { // case 2 : if it is not a first node 
                last->next = newNode;
                last =newNode;
            }
        }
    }
}

// display 
void displaySparseMatrix(struct Node **A , int m , int n){
    struct Node *temp;
    printf("Sparse matrix representation:\n");
    for(int i = 0 ; i < m ; i++){
        temp = A[i];
        for(int j = 0 ; j< n; j++){
            if(temp != NULL && j == temp->col){
                printf(" %d " , temp->data);
                temp = temp->next;
            }else{
                printf(" 0 ");
            }
        }
        printf("\n");
    }
}