#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack{
    int size;
    int top;
    char *s;
};

int isEmpty(struct Stack *st){
    return (st->top == -1) ? 1 : 0;
}

int isFull(struct Stack *st){
    return (st->top == st->size-1) ? 1: 0;
}

int peek(struct Stack *st){
    if(st->top == -1){
        return -1;
    }else{
        return st->s[st->top];
    }
}

void push(struct Stack *st , char x){
    if(!isFull(st)){
        st->top++;
        st->s[st->top] = x;
    }else{
        printf("Stack is full!");
    }
}

int pop(struct Stack *st){
    if(!isEmpty(st)){
        return st->s[st->top--];
    }else{
        return -1;
    }
}

int isOperand(char x){
    if(x == '+' || x =='-' || x=='*' || x=='/'){
        return 0; // false
    }
    return 1;
}

int pre(char x){
    if(x == '+' || x =='-' ){
        return 1; 
    }else if( x=='*' || x=='/'){
        return 2;
    }else {
        return 0;
    }
}

char *convert(char *infix){
    // stack initialization
    struct Stack st;
    st.size = strlen(infix);
    st.top = -1;
    st.s = (char *)malloc(st.size * sizeof(char));

    char *postfix = (char *)malloc(strlen(infix));

    int i = 0 , j = 0;

    while(infix[i]!='\0'){
        if(isOperand(infix[i])){
            postfix[j++] = infix[i++]; 
        }else if(pre(infix[i]) > pre(peek(&st))){
            push(&st , infix[i++]);
        }else{
            postfix[j++] = pop(&st);
        }
    }

    while(!isEmpty(&st)){
        postfix[j++] = pop(&st);
    }

    postfix[j] =  '\0';

    return postfix;

}

int main(){
    char infix[] = "a+b*c-d/e";

    printf("%s" ,convert(infix));

   
    return 0;
}