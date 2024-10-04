#include <stdlib.h>
#include <stdio.h>


// Structure for stack 
struct Stack{
    int size;
    int top;
    int *s;
};

// ADT stack 

// 1. isEmpty 
int isEmpty(struct Stack *st){
    if(st->top == -1){
        return 1; // 1 true
    }
    return 0; // false
}


// 2. isFull
int isFull(struct Stack *st){
    if(st->top == st->size-1){
        return 1;
    }
    return 0;
}

// stack top : to get the top value in the stack 
int stackTop(struct Stack st){
    if(st.top == -1){
        return 0;
    }else {
        return st.s[st.top];
    }
}

// Time complexity : O(1)
void push(struct Stack *st ,int value){
    if(!isFull(st)){
        st->top++;
        st->s[st->top] = value;
    }else {
        printf("\nStack is full.");
    }
}

// Time complexity : O(1)
int pop(struct Stack *st ){
    int value = -1;
    if(!isEmpty(st)){
        value = st->s[st->top];
        st->top--;
        printf("\nThe %d value is deleted from the stack." , value);
    }else{
        printf("\nStack is empty!");
    }
    return value;
}

// knowing the value by position
// time complexity : O(1);
int peak(struct Stack st , int pos){
    int x = -1;
    if(pos < st.top-pos +1){
        printf("Invalid Position!");
    }else{
        x = st.s[st.top-pos+1];
    }
    
    return x;
}

void display(struct Stack *st){
    for(int i=0 ; i<=st->top ; i++){
      printf("\n Element : %d" , st->s[i]);
    }
}

int main()
{
    struct Stack st;
    printf("Enter the size of the array : ");
    scanf("%d" , &st.size);
    
    st.s = (int*)malloc(st.size * sizeof(int));
    
    st.top = -1;
    
    // insert values to the stack
    push(&st , 10);
    push(&st , 20);
    push(&st , 30);
    
    // traverse stack
    display(&st);
    
    // Delete value from the stack;
    // pop(&st);
    
    
    // traverse stack;
    display(&st);
    
    
    // int value = peak(st , 4);
    // if(value !=-1){
    //     printf("The value is %d" , value);
    // }else{
    //     printf("Invalid");
    // }
    
    int value = stackTop(st);
    if(value){
        printf("\nTop value is : %d" , value); 
    }else{
        printf("\nThere is no top element in the stack.");
    }   
    
    

    return 0;
}