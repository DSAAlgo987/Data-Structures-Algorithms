#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node *next;
};

// Function to create a new node
struct Node *createNode(int data) {
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

// Function to insert a node in sorted order into the linked list
struct Node *SortedInsert(struct Node **start, int value) {
    struct Node *temp, *p, *newNode;
    newNode = createNode(value);

    // Case: Insert at the beginning or into an empty list
    if (*start == NULL || value < (*start)->data) {
        newNode->next = *start;
        *start = newNode;
        return *start;
    }

    // General case: Find the correct position
    temp = *start;
    while (temp != NULL && value > temp->data) {
        p = temp;
        temp = temp->next;
    }

    // Insert the new node
    p->next = newNode;
    newNode->next = temp;
    return *start;
}

// Function to hash a key
int hash(int key) {
    return key % 10; // Hash function
}

// Insert a key into the hash table
// *H[] use bcoz point to array of pointers
void Insert(struct Node *H[], int key) {
    int index = hash(key);
    H[index] = SortedInsert(&H[index], key);
}

// Function to display the hash table
void display(struct Node *H[]) {
    struct Node *p;
    for (int i = 0; i < 10; i++) {
        printf("HT[%d]: ", i);
        p = H[i];
        while (p) {
            printf("%d -> ", p->data);
            p = p->next;
        }
        printf("NULL\n");
    }
}
struct Node *search(struct Node *p , int value){
    while(p!=NULL){
        if(p->data == value){
            return p;
        }
        p = p->next;
    }
    
    return NULL;
}

void delete(struct Node **start , int key){
    struct Node *temp , *prev;
    
    temp = *start;
    while(temp != NULL && temp->data !=key){
        prev = temp;
        temp = temp->next;
    }
    
    if(temp == NULL){
        printf("value not found");
    }else if(temp == *start){
        *start = temp->next;
        free(temp);
    }else {
        prev->next = temp->next;
        free(temp);
    }
}

int main() {
    // Create a hash table
    struct Node *HT[10] , *temp;

    // Initialize hash table to NULL
    for (int i = 0; i < 10; i++) {
        HT[i] = NULL;
    }

    // Insert values into the hash table
    Insert(HT, 22);
    Insert(HT, 42);
    Insert(HT, 32);
    Insert(HT, 52);
    Insert(HT, 12);

    // Display the hash table
    display(HT);
    
    // search key 
    temp = search(HT[hash(22)] , 22);
    printf("%d" , temp->data);
    
    // delete key 
    delete(&HT[hash(22)], 22);
    
    display(HT);
    return 0;
}
