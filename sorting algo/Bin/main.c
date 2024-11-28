// why we use doubly pointer here : 
/*
    bcoz we need to change the actual linked list that's why we have to use 
    ** double pointer so that the actual linked list would change.
    here call by reference function type is used for insert and deletion purposes
*/
#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *createNode(int data){
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    
    temp->data = data;
    temp->next = NULL;
    
    return temp;
}

void insert(struct Node **start  , int data){
    struct Node *temp , *newNode;
    newNode = createNode(data);
    if(*start == NULL){ // if it is a first node 
        *start = newNode;
    }else {
        temp = *start;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

int delete(struct Node **start){
    struct Node *temp , *prev;
    int x;
    
    temp = *start;
    x  = temp->data;
    *start = (*start)->next;
    free(temp);
    return x;
}

int findMax(int A[] , int n){
    int max = 0;
    for(int i = 0 ; i < n ; i++){
        if(A[i] > max){
            max = A[i];
        }
    }
    
    return max;
}



void BinSort(int A[] , int n){
    int max , i , j;
    
    // find max element from A 
    max = findMax(A , n);
    
    struct Node **Bin;
    // Create Bin Array as the size of max element
    Bin = (struct Node **)malloc(sizeof(struct Node *) * (max +1));
    
    // initialize Bin as NULL 
    for(i = 0 ; i < max+1 ; i++){
        Bin[i] = NULL;
    }
    
    // store each element in bin array from A 
    for(i = 0 ; i < n ; i++){
        insert(&Bin[A[i]] , A[i]);
    }
    
    // delete every element from the Bin array and store it in the original array 
    i = 0 , j =0;
    while(i < max+1){
        while(Bin[i] !=NULL){
            A[j++] = delete(&Bin[i]);
        }
        i++;
    }
    
}

int main()
{
    int A[] = {6 , 8 , 3 , 10 , 15 , 6 , 9 , 12 , 6 , 3}, n;
    n = sizeof(A) / sizeof(A[0]);
    
    BinSort(A , n);
    
    for(int i = 0 ; i < n ; i++){
        printf("%d " , A[i]);
    }
    
    return 0;
}