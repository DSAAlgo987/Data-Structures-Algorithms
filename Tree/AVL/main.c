#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    int height;
    struct Node *lChild , *rChild;
}*root = NULL;

struct Node *createNode(int data , int height){
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    temp->height = height;
    temp->lChild = temp->rChild = NULL;

    return temp;
}

int nodeHeight(struct Node *p){
    int hl , hr;

    // use ternary operator
    hl = p && p->lChild ? p->lChild->height:0;
    hr = p && p->rChild ? p->rChild->height:0;

    return hl > hr ? hl + 1 : hr +1;
}

// balanceFactor = hight of left sub-tree - height of right sub-tree
int balanceFactor(struct Node *p){
    int hl , hr;
    
    hl = p && p->lChild ? p->lChild->height:0;
    hr = p && p->rChild ? p->rChild->height:0;
    
    return hl-hr;
}

struct Node *LLRotation(struct Node *p){
    struct Node *pl = p->lChild;
    struct Node *plr = pl->rChild;

    // assignments 
    pl->rChild =p;
    p->lChild = plr;

    // after rotation change height of nodes
    p->height = nodeHeight(p);
    pl->height = nodeHeight(pl);

    if(root == p){ // root was p
        root = pl; // change root 
    }

    return pl;
}

struct Node *LRRotation(struct Node *p){
    struct Node *pl = p->lChild;
    struct Node *plr = pl->rChild;

    // assignments :

    // connect with children of plr
    pl->rChild = plr->lChild;
    p->lChild = plr->rChild;

    // change location of nodes
    plr->rChild = p;
    plr->lChild = pl;

    // change the height 
    plr->height = nodeHeight(plr);
    p->height = nodeHeight(p);
    pl->height = nodeHeight(pl);

     if(root == p){ // root was p
        root = plr; // change root 
    }

    return plr;  
}

struct Node *RLRotation(struct Node *p){
    struct Node *pr = p->rChild;
    struct Node *prl = pr->lChild;

    // assignments :

    // connect with children of prl
    p->rChild = prl->lChild;
    p->lChild = prl->rChild;

    // change location of nodes
    prl->lChild = p;
    prl->rChild = pr;

    // change height of each node
    prl->height = nodeHeight(prl);
    p->height = nodeHeight(p);
    pr->height = nodeHeight(pr);

    if(root == p){
        root = prl;
    }

    return prl;
}

struct Node *RRRotation(struct Node *p){
    struct Node *pr = p->rChild;
    struct Node *prl = pr->lChild;

    // assignments 
    pr->lChild = p;
    p->rChild = prl;

    // change height 
    p->height = nodeHeight(p);
    pr->height = nodeHeight(pr);

    // change root
    if(root == p){
        root = pr;
    }

    return pr;
}

struct Node *rInsert(struct Node *p , int key){
    struct Node *t;
    if(p == NULL){
        // start height from 1
        t = createNode(key , 1);
        return t;
    }
    if(key < p->data){
        p->lChild = rInsert(p->lChild , key);
    }else{
        p->rChild = rInsert(p->rChild , key);
    }

    p->height = nodeHeight(p);

    // Identify rotation type to use
    if(balanceFactor(p) == 2 && balanceFactor(p->lChild) == 1){
        return LLRotation(p);
    }else if(balanceFactor(p) == 2 && balanceFactor(p->lChild) == -1){
        return LRRotation(p);
    }else if(balanceFactor(p) == -2 && balanceFactor(p->rChild) == 1){
        return RLRotation(p);
    }else if(balanceFactor(p) == -2 && balanceFactor(p->rChild) == -1){
        return RRRotation(p);
    }

    return p;
}

// inorder(left) , visit(node) , inorder(right)
void inOrder(struct Node *p){
    if(p){
        inOrder(p->lChild);
        printf("%d " , p->data);
        inOrder(p->rChild);
    }
}

int main(){
    int choice, key;
    struct Node *root = NULL;

    while(1) {
        printf("\n========== AVL Tree Menu ==========\n");
        printf("1. Insert Node\n");
        printf("2. In-Order Traversal\n");
        printf("3. Exit\n");
        printf("====================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter the key to insert: ");
                scanf("%d", &key);
                root = rInsert(root, key);
                break;
            case 2:
                printf("\nIn-Order Traversal: ");
                inOrder(root);
                break;
            case 3:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Please select a valid option.\n");
        }
    }

    return 0;
}