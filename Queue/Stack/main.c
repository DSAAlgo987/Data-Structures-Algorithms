#include <stdio.h>
#include <stdlib.h>

struct Stack{
    int size;
    int top;
    int *s;
} st1, st2;

void create() {
    int value;
    printf("Enter the size of the queue: ");
    scanf("%d", &value);

    st1.size = value;
    st2.size = value;

    st1.top = -1;
    st2.top = -1;

    st1.s = (int *)malloc(st1.size * sizeof(int));
    st2.s = (int *)malloc(st2.size * sizeof(int));
}

int isEmpty(struct Stack *st) {
    return (st->top == -1);
}

int isFull(struct Stack *st) {
    return (st->top == st->size - 1);
}

void push(struct Stack *st, int x) {
    if (!isFull(st)) {
        st->top++;
        st->s[st->top] = x;
    } else {
        printf("Stack is full.\n");
    }
}

int pop(struct Stack *st) {
    int x = -1;
    if (!isEmpty(st)) {
        x = st->s[st->top];
        st->top--;
    } else {
        printf("Stack is empty.\n");
    }
    return x;
}

void enqueue(int x) {
    if (!isFull(&st1)) {
        push(&st1, x);
    } else {
        printf("Queue is full.\n");
    }
}

int dequeue() {
    if (isEmpty(&st2)) {
        if (isEmpty(&st1)) {
            printf("Queue is empty.\n");
            return -1;
        } else {
            while (!isEmpty(&st1)) {
                push(&st2, pop(&st1));
            }
        }
    }
    return pop(&st2);
}

int main() {
    int choice, value;

    create();

    while (1) {
        printf("\nEnter your choice: ");
        printf("\n1. Enqueue \n2. Dequeue \n3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter the element to insert: ");
            scanf("%d", &value);
            enqueue(value);
            break;
        case 2:
            value = dequeue();
            if (value != -1) {
                printf("\nDeleted Element: %d\n", value);
            }
            break;
        case 3:
            exit(0);
            break;
        default:
            printf("\nInvalid choice.\n");
            break;
        }
    }

    return 0;
}
