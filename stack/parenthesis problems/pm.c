#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Stack {
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

void push(char value){
    if(!isFull()){
        st.top++;
        st.s[st.top] = value;
    }else {
        printf("Stack is full");
    }
}

int pop(){
    
    if(isEmpty()){
        return '\0';
    }else{
        return st.s[(st.top)--];
    }
}

int isBalanced(char *exp){
    st.size = strlen(exp);
    st.top = -1;
    st.s = (char *)malloc(st.size * sizeof(char));

    for(int i = 0 ; exp[i]!='\0' ; i++){
        if(exp[i] == '('){
            push(exp[i]);
        }else if(exp[i] == ')'){
            if(isEmpty()){
                return 0;
            }
            pop();
        }
    }
    //                 T   F 
    return isEmpty() ? 1 : 0;
}

int main(){
    char exp[] = "((a+b)*(a-b))";
    
    if(isBalanced(exp)){
        printf("Paranthesis Matched.");
    }else{
        printf("Not matched");
    }
    return 0;
}
