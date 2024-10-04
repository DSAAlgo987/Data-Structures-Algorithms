#include <stdlib.h>
#include <stdio.h>

// Structure for stack 
struct Stack {
    int size;
    int top;
    struct Node **s;  // Array of pointers to tree nodes
};

// Stack operations
void createStack(struct Stack *st , int size) {
    st->size = size;
    st->top = -1;
    st->s = (struct Node **)malloc(st->size * sizeof(struct Node *));
}

// Check if stack is empty
int isStackEmpty(struct Stack *st) {
    return (st->top == -1);
}

// Check if stack is full
int isStackFull(struct Stack *st) {
    return (st->top == st->size - 1);
}

// Push a node onto the stack
void push(struct Stack *st, struct Node *value) {
    if (!isStackFull(st)) {
        st->top++;
        st->s[st->top] = value;
    } else {
        printf("\nStack is full.\n");
    }
}

// Pop a node from the stack
struct Node* pop(struct Stack *st) {
    struct Node *value = NULL;
    if (!isStackEmpty(st)) {
        value = st->s[st->top];
        st->top--;
    } else {
        printf("\nStack is empty!\n");
    }
    return value;
}
