#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack{
    int top;
    int size;
    char *s;
};

int isEmpty(struct Stack *st){
    return (st->top == -1) ? 1 : 0; 
}

int isFull(struct Stack *st){   
    return (st->top == st->size-1) ? 1 : 0;
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

void reverse(char *infix){
    int start = 0;
    int end = strlen(infix) - 1;
    char temp;

    while (start < end) {
        // Swap characters
        temp = infix[start];
        infix[start] = infix[end];
        infix[end] = temp;
        start++;
        end--;
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

void removeParentheses(char *str) {
    int len = strlen(str);
    char *result = (char *)malloc((len + 1) * sizeof(char));
    int j = 0;

    for (int i = 0; i < len; i++) {
        if (str[i] != '(' && str[i] != ')') {
            result[j++] = str[i];
        }
    }

    result[j] = '\0'; // Null-terminate the result string
    strcpy(str, result); // Copy the result back to the original string
    free(result);
}

char *convert(char *infix){
    struct Stack st;
    st.size = strlen(infix);
    st.top = -1;
    st.s = (char *)malloc(st.size* sizeof(char));
    
    // reverse given infix 
    reverse(infix);

    // Replace ( with ) and vice versa
    for (int i = 0; i < strlen(infix); i++) {
        if (infix[i] == '(') {
            infix[i] = ')';
        } else if (infix[i] == ')') {
            infix[i] = '(';
        }
    }

    char *prefix = (char *)malloc(strlen(infix) +1);

    int i = 0 , j = 0;

    while(infix[i]!='\0'){
        if(isOperand(infix[i])){
            prefix[j++] = infix[i++]; 
        }else if(pre(infix[i]) >= pre(peek(&st))){
            push(&st , infix[i++]);
        }else{
            prefix[j++] = pop(&st);
        }
    }

    while(!isEmpty(&st)){
        prefix[j++] = pop(&st);
    }
    prefix[j] =  '\0';
    removeParentheses(prefix);
    // reverse prefix to get the real prefix
    reverse(prefix);
    return prefix;

}

// TC : O(N) , SC : O(N);
int palindrome(char *str){
    int length = strlen(str);

    struct Stack st;
    st.size = length;
    st.top = -1;
    st.s = (char *)malloc(st.size * sizeof(char));

    char rev[length + 1]; // Add null character

    for(int i = 0 ; str[i] !='\0' ; i++){
        push(&st , str[i]);
    }

    for(int i = 0 ; i<length ; i++){
        rev[i] = pop(&st);
    }

    rev[length] = '\0';

    if(strcmp(str , rev) ==0){
        return 1;
    }else {
        return 0;
    }
}

// TC : O(n) , SC : O(1)
int palindrome2(char *str){
    int i = 0 ; 
    int j = strlen(str)-1;
    
    
    while(i < j){
        if(str[i] != str[j]){
            return 0; // not a palindrome
        }
        i++;
        j--;
    }
    
    return 1;
}