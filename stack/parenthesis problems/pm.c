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

int isMatching(char a , char b){
    if(a == '(' && b == ')'){
        return 1;
    }else if(a == '{' && b == '}'){
        return 1;
    }else if(a == '[' && b == ']'){
        return 1;
    }
    return 0;
}

int isBalanced(char *exp){
    st.size = strlen(exp);
    st.top = -1;
    st.s = (char *)malloc(st.size * sizeof(char));
    char temp;
    for(int i = 0 ; exp[i]!='\0' ; i++){
        if(exp[i] == '{' || exp[i] == '(' || exp[i] == '['){
            push(exp[i]);
        }else if(exp[i] == '}' || exp[i] == ')' || exp[i] == ')'){
            if(isEmpty()){
                return 0;
            }
            temp = pop();
            if(!isMatching( temp , exp[i] )){
                return 0;
            }
        }
    }
    //                 T   F 
    return isEmpty() ? 1 : 0;
}

int main(){
    char exp[] = "([a+b)*(a-b))";
    
    if(isBalanced(exp)){
        printf("Paranthesis Matched.");
    }else{
        printf("Not matched");
    }
    return 0;
}
