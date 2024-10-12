#include <stdio.h>
#include "operations.h"
#include "stack.h"

struct Node *root = NULL;

// Creation of binary tree 
void createTree(){
    struct Node *p, *temp;
    int value;
    
    struct Queue q; 
    createQ(&q , 100); // creation of queue 
    
    printf("Enter the value for Root Node : ");
    scanf("%d" , &value);
    
    root = createNode(value); // root node creation 
    enqueue(&q , root);
    while(!isEmpty(&q)){
        p = dequeue(&q);
        printf("Enter the left child for %d : " , p->data);
        scanf("%d" , &value);
        if(value != -1){
            temp = createNode(value);
        
            p->lChild = temp;
            enqueue(&q ,temp);
        }
        
        printf("Enter the right child for %d : " , p->data);
        scanf("%d" , &value);
        if(value != -1){
            temp = createNode(value);
        
            p->rChild = temp;
            enqueue(&q , temp);
        }
    }
}

void preOrder(struct Node *p){
    if(p){
        printf("%d" , p->data);
        preOrder(p->lChild);
        preOrder(p->rChild);
    }
}

void inOrder(struct Node *p){
    if(p){
        inOrder(p->lChild);
        printf("%d" , p->data);
        inOrder(p->rChild);
    }
}

void postOrder(struct Node *p){
    if(p){
        postOrder(p->lChild);
        postOrder(p->rChild);
        printf("%d" , p->data);
    }
}

void IPreOrder(struct Node *t) {
    struct Stack st;
    createStack(&st , 100);

    // While there are nodes to process
    while (t != NULL || !isStackEmpty(&st)) {
        if (t != NULL) {
            printf("%d ", t->data);  // Visit the node (Pre-order)
            push(&st, t);  // Push the current node to the stack
            t = t->lChild;  // Move to the left child
        } else {
            t = pop(&st);  // Pop the node from the stack
            t = t->rChild;  // Move to the right child
        }
    }
}


void IInOrder(struct Node *t){
    struct Stack st;
    createStack(&st , 100);
    
    while(t != NULL || !isStackEmpty(&st)){
        if(t){
           push(&st , t);
           t = t-> lChild;
        }else{
            t = pop(&st);
            printf("%d" , t->data);
            t = t->rChild;
        }
    }
}

void insert(){
    struct Node *temp , *newNode , *parent;
    int value;
    
    printf("Enter the value to insert : ");
    scanf("%d" , &value);
    
    newNode = createNode(value);
    
    if(root == NULL){
        root = newNode;
    }else{
        temp = root;
        while(temp!=NULL){
            if(value > temp->data){
                parent = temp;
                temp = temp->rChild;
            }else{
                parent = temp;
                temp = temp->lChild;
            }
        }
        
        if(value > parent->data){
            parent->rChild = newNode;
        }else{
            parent->lChild = newNode;
        }
    }
}

void IPostOrder(struct Node *t){
     struct Stack st;
    createStack(&st, 100); // Initialize stack with size 100
    long int temp;
    
    while (t != NULL || !isStackEmpty(&st)) {
        if (t != NULL) {
            push(&st, (long int)t);  // Push node's address to the stack
            t = t->lChild;  // Move to the left child
        } else {
            temp = pop(&st);  // Pop the top element from the stack
            
            if (temp > 0) {  // If it's a positive value (node address)
                push(&st, -temp);  // Mark the node as processed by pushing a negative value
                t = ((struct Node *)temp)->rChild;  // Move to the right child
            } else {  // Negative value means the node has been processed
                printf("%d ", ((struct Node *)(-temp))->data);  // Print the node's data
                t = NULL;  // Set t to NULL to continue popping from the stack
            }
        }
    }
}


void LevelOrder(struct Node *p){
    struct Queue q;
    createQ(&q , 100);

    printf("%d " , p->data);
    enqueue(&q , p);

    while(!isEmpty(&q)){
        p = dequeue(&q);
        if(p->lChild){
            printf("%d " , p->lChild->data);
            enqueue(&q , p->lChild);
        }
        if(p->rChild){
            printf("%d " , p->rChild->data);
            enqueue(&q , p->rChild);
        }
    }    
}

// count nodes having degree(2)
int countNodesDegreeTwo(struct Node *p){
    if(p){
        if(p->lChild && p->rChild){
            return countNodesDegreeTwo(p->lChild) + countNodesDegreeTwo(p->rChild) + 1;
        }else{
            return countNodesDegreeTwo(p->lChild) + countNodesDegreeTwo(p->rChild);
        }
    }
    return 0;
}

// count nodes having degree (1,2)
int countInternal(struct Node *p){
    if(p){
        if( p->lChild || p->rChild){
            return countInternal(p->lChild) + countInternal(p->rChild) + 1;
        }else{
            return countInternal(p->lChild) + countInternal(p->rChild);
        }
    }
    return 0;
}

// count nodes having degree 1 
int countDegreeOne(struct Node *p){
    if(p){
        if(p->lChild != NULL ^ p->rChild != NULL){
            return countDegreeOne(p->lChild) + countDegreeOne(p->rChild) + 1;
        }else{
            return countDegreeOne(p->lChild) + countDegreeOne(p->rChild);
        }
    }
    return 0;
}

// count of external nodes 
int countExternal(struct Node *p){
    if(p){
        if(!p->rChild && !p->lChild){
            return 1;
        }else{
            return countExternal(p->lChild) + countExternal(p->rChild);
        }
    }
    return 0;
}

int height(struct Node *p){
    int x , y;
    if(p){
        x = height(p->rChild);
        y = height(p->lChild);
        if(x > y){
            return x + 1;
        }else {
            return y + 1;
        }
    }
    return -1;
}

int level(struct Node *p){
    int x , y;
    if(p){
        x = level(p->rChild);
        y = level(p->lChild);
        if(x > y){
            return x + 1;
        }else {
            return y + 1;
        }
    }
    return 0;
}


int main()
{
    int choice;
    while (1) {
    printf("\n========== Menu ==========\n");
    printf("1. Create Binary Tree\n");
    printf("2. Iterative PreOrder Traversal\n");
    printf("3. Recursive PreOrder Traversal\n");
    printf("4. Iterative InOrder Traversal\n");
    printf("5. Recursive InOrder Traversal\n");
    printf("6. Iterative PostOrder Traversal\n");
    printf("7. Recursive PostOrder Traversal\n");
    printf("8. Level Order Traversal\n");
    printf("9. Count Nodes\n");
    printf("10. Count of External Nodes\n");
    printf("11. Count of Nodes Having Degree 2\n");
    printf("12. Count of Nodes Having Degree 1 or 2\n");
    printf("13. Count of Nodes Having Degree 1\n");
    printf("14. Height of the Tree\n");
    printf("15. Level of the Tree\n");
    printf("16. Exit\n");
    printf("===========================\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            createTree();
            break;

        case 2:
            printf("\nIterative PreOrder: ");
            IPreOrder(root);
            break;

        case 3:
            printf("\nRecursive PreOrder: ");
            preOrder(root);
            break;

        case 4:
            printf("\nIterative InOrder: ");
            IInOrder(root);
            break;

        case 5:
            printf("\nRecursive InOrder: ");
            inOrder(root);
            break;

        case 6:
            printf("\nIterative PostOrder: ");
            IPostOrder(root);
            break;

        case 7:
            printf("\nRecursive PostOrder: ");
            postOrder(root);
            break;

        case 8:
            printf("\nLevel Order Traversal: ");
            LevelOrder(root);
            break;

        case 9:
            printf("\nCount of Nodes: %d", count(root));
            break;

        case 10:
            printf("\nCount of External Nodes (Leaf Nodes): %d", countExternal(root));
            break;

        case 11:
            printf("\nCount of Nodes Having Degree 2 (Two Children): %d", countNodesDegreeTwo(root));
            break;

        case 12:
            printf("\nCount of Nodes Having Degree 1 or 2: %d", countInternal(root));
            break;

        case 13:
            printf("\nCount of Nodes Having Degree 1 (One Child): %d", countDegreeOne(root));
            break;

        case 14:
            printf("\nHeight of the Tree: %d", height(root));
            break;

        case 15:
            printf("\nLevel of the Tree (root level): %d", level(root));
            break;

        case 16:
            printf("Exiting...\n");
            return 0;

        default:
            printf("Invalid choice! Please select a valid option.\n");
    }
}

    return 0;
}
