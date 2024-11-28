#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *createNode(int data){
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    
    return temp;
}

void Insert(struct Node **start , int data){
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

int Delete(struct Node **start){
    int x;
    struct Node *temp;
    temp = *start;
    x = temp->data;
    *start = (*start)->next; // fifo fashion delete
    return x;
}

int findMax(int A[] , int n){
    int max =0;
    for(int i = 0 ; i < n ; i++){
        if(A[i] > max){
            max = A[i];
        }
    }
    return max;
}

int countDigits(int n){
    int count = 0;
    while( n > 0){
        count++;
        n /= 10;
    }
    
    return count;
}

// for decimal no system : base is 10
void Radix(int A[] , int n){
    int d, i , j , division = 1;
    struct Node **Bin; 
    Bin = (struct Node **)malloc(sizeof(struct Node *) * 10);
    
    // initialize Bin as NULL 
    for(i = 0 ; i < 10 ; i++){
        Bin[i] = NULL;
    }
    
    d = countDigits(findMax(A , n));
    for(int p = 0 ; p <d ; p++){
        // store all the element of A in Bin array of pointers
        for(i = 0 ; i < n ;i++){
            Insert(&Bin[(A[i]/division) %10] , A[i]);
        }
        
        //delete all the elements from Bin and copy it to the A for p times 
        i = 0 , j = 0;
        while(i != 10){
            while(Bin[i]!=NULL){
                A[j++] = Delete(&Bin[i]);    
            }
            i++;
        }
        
        division *=10;
    }
}

int main()
{
    int A[] = {237 , 146 , 259 , 348 , 152 , 163 , 235 , 48 , 36 , 62} , n;
    n = sizeof(A) / sizeof(A[0]);
    Radix(A , n);
    
    for(int i = 0 ; i < n ; i++)
        printf("%d " , A[i]);

    return 0;
}
