#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack{
    int size;
    int top;
    int *s;
};

int isEmpty(struct Stack *st){
    return (st->top ==-1)? 1:0;
}

int isFull(struct Stack *st){
    return (st->top == st->size-1) ? 1 : 0;
}

int peek(struct Stack *st){
    if(st->top == -1){
        return -1;
    }
    return st->s[st->top];
}

void push(struct Stack *st , int data){
    if(!isFull(st)){
        st->top++;
        st->s[st->top] = data;
    }else{
        printf("Stack is full");
    }
}

int pop(struct Stack *st){
    if(!isEmpty(st)){
        return st->s[st->top--];
    }
    printf("Stack is full");
}

int isOperand(char x){
    if(x == '+' || x == '-' || x == '/' || x == '*'){
        return 0;
    }
    return 1;
}

int eval(char *postfix){
    struct Stack st;
    st.size = strlen(postfix);
    st.top = -1;
    st.s = (int *)malloc(st.size * sizeof(int));

    int i, x1 , x2 , r;

    for(i = 0 ; postfix[i]!='\0' ; i++){
        if(isOperand(postfix[i])){
            push(&st , postfix[i]-'0');
        }else{
            x2 = pop(&st); x1 = pop(&st);
            switch (postfix[i])
            {
            case '+':
                r = x1 + x2;
                push(&st , r);
                break;
                
            case '-':
                r = x1 - x2;
                push(&st , r);
                break;
                
            case '/':
                r = x1 / x2;
                push(&st , r);
                break;
                
            case '*':
                r = x1 * x2;
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

int main(){
    char postfix[] = "35*62/+4-";

    int result= eval(postfix);

    if(result){
        printf("Evaluation of Postfix %s : %d" , postfix , result);
    }
    return 0;
}
