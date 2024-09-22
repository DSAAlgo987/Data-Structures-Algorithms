#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack {
    int top;
    int size;
    int *s;
};

int isEmpty(struct Stack *st){
    return (st->top ==-1) ? 1: 0;
}

int isFull(struct Stack *st){
    return (st->top == st->size-1) ? 1 : 0;
}

void push(struct Stack *st , int x){
    if(isFull(st)){
        printf("Stack is full");
    }else{
        st->top++;
        st->s[st->top] = x;
    }
}

int pop(struct Stack *st){
    int x = -1;
    if(!isEmpty(st)){
        x = st->s[st->top--];
    }else{
        printf("Stack is empty");
    }
    return x;
}

int isOperand(char x){
    if(x == '+' || x == '-' || x == '/' || x == '*'){
        return 0;
    }
    return 1;
}

int eval(char *prefix){
    struct Stack st;
    st.size = strlen(prefix);
    st.top = -1;
    st.s = (int *)malloc(st.size * sizeof(int));

    int i, x1 , x2 , r;
    for(i = strlen(prefix) -1 ; i >=0 ; i--){
        if(isOperand(prefix[i])){
            push(&st , prefix[i] - '0');
        }else{
            x1 = pop(&st); x2 = pop(&st);
            switch (prefix[i])
            {
            case '+':
                r = x1 +x2;
                push(&st , r);
                break;
            case '-':
                r = x1 -x2;
                push(&st , r);
                break;
            case '/':
                if (x2 != 0) {
                        r = x1 / x2; // Integer division
                } else {
                    printf("Error: Division by zero\n");
                    return -1; // Handle division by zero error
                }
                push(&st , r);

                break;
            case '*':
                r = x1 *x2;
                push(&st , r);
                break;
            
            default:
                printf("Invalid case.");
                break;
            }
        }
    }

    return pop(&st);
}