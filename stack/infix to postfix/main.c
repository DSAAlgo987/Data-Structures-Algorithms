#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack{
    int size;
    int top;
    char *s;
}st;

int isEmpty(){
    return (st.top == -1) ? 1 : 0;
}

int isFull(){
    return (st.top == st.size-1) ? 1 : 0;
}

void push(char x){
    if(!isFull()){
        st.top++;
        st.s[st.top] = x;
    }else {
        printf("Stack is full");
    }
}

int pop(){
    char x;
    if(!isEmpty()){
        x = st.s[st.top];
        st.top--;
    }else {
        return -1;
    }
}

int stackTop(){
    if(st.top == -1){
        return -1;
    }
    return st.s[st.top];
}

int isOperand(char x){
    if(x == '+' || x=='-' || x=='*' || x=='/'){
        return 0;
    }
    return 1;
}

int pre(char x){
    if( x == '+' || x == '-'){
        return 1;
    }else if(x == '*' || x == '/'){
        return 2;
    }
    return 0;
}

char *convert(char *infix){

    // initialization of stack
    st.size = strlen(infix);
    st.top = -1;
    st.s = (char *)malloc(st.size * sizeof(char));

    char *postfix = (char *)malloc(strlen(infix)+1);
    int i = 0 , j= 0;

    while(infix[i]!='\0'){
        if(isOperand(infix[i])){
            postfix[j++] = infix[i++];
        }else{
            if(pre(infix[i]) > pre(stackTop())){
                push(infix[i++]);
            }else {
                postfix[j++] = pop();
            }
        }
    }

    while(!isEmpty()){
        postfix[j++] = pop();
    }

    postfix[j] = '\0';

    return postfix;
}


int main(){
    char exp[] = "a+b*c-d/e";

    printf("%s" , convert(exp));
    return 0;
}
