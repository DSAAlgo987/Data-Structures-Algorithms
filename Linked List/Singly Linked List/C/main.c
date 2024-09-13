#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node *next;
}*first =NULL , *second=NULL;

// Creation of LL
void create(int A[] , int n){
    struct Node *t , *l;
    
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    l = first;
    
    for(int i = 1; i< n;i++){
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        l->next = t;
        l = t;
    }
}

// Creation of second LL
void createSecondList(int B[] , int n){
    struct Node *t , *l;
    
    second = (struct Node *)malloc(sizeof(struct Node));
    second->data = B[0];
    second->next = NULL;
    l = second;
    
    for(int i = 1; i< n;i++){
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = B[i];
        t->next = NULL;
        l->next = t;
        l = t;
    }
}


//traversing using tail recursion
//Space complexity : O(n)
//time complexity : O(n)
void traverseT(struct Node *head){
    if(head){
        printf("Element : %d \n" , head->data);
        traverseT(head->next);
    }
}

//traversing using head recursion
//Space complexity : O(n)
//time complexity : O(n)
void traverseH(struct Node *head){
    if(head){
        traverseT(head->next);
        printf("Element : %d \n" , head->data);
    }
}

int countRecursive(struct Node *head){
    if(!head){
        return 0;
    }else{
        return countRecursive(head->next) + 1;
    }
}

int countNodes(struct Node *head){
    int count=0;
    while(head){
        count++;
        head= head->next;
    }
    return count;
}

int sumNodes(struct Node *head){
    int sum =0;
    while(head){
        sum = sum + head->data;
        head= head->next;
    }
    return sum;
}

int sumRecursive(struct Node *head){
    if(!head){
        return 0;
    }else{
        return sumRecursive(head->next)+head->data;
    }
}

int maxNum(struct Node *head){
    int max=0;
    while(head){
        if(head->data > max){
            max = head->data;
        }
        head = head->next;
    }
    return max;
}

void searchElement(struct Node *head , int n){
    bool isPresent=false;
    while(head){
        if(head->data == n){
            isPresent=true;
        }
        head = head->next;
    }
    
    if(isPresent){
        printf("%d is present." , n);
    }else {
        printf("%d is not present.", n);
    }
}

int searchElementRecursive(struct Node *head, int n) {
    if (head == NULL) {
        return -1; // Element not found
    }
    if (n == head->data) {
        return n; // Element found
    } else {
        return searchElementRecursive(head->next, n); // Continue searching in the next node
    }
}

//Time complexity : O(1)
struct Node * insertAtFirst(struct Node *head , int data){
    struct Node *new;
    
    new = (struct Node*)malloc(sizeof(struct Node));
    new->data = data;
    new->next = head;
    
    head = new;
    return head;
}

// Time complexity : 
// Min : o(1)
// Max : O(n)
struct Node * insertAtBetween(struct Node *head , int data , int index){
    
    if(index < 0){
        return NULL;
    }
    
    struct Node * new = (struct Node *)malloc(sizeof(struct Node));
    struct Node *ptr = head;
    
    
    int i =0;
    while(i != index-1){
        ptr =ptr->next;
        i++;
    }
    
    new->data = data;
    new->next =ptr->next;
    ptr->next = new;
    return head;
}

// Time complexity : O(1);
struct Node * insertAtEnd(struct Node *head , int data){
    struct Node * new = (struct Node *)malloc(sizeof(struct Node));
    struct Node * ptr = head;
    
    while(ptr->next!=NULL){
        ptr = ptr-> next;
    }
    
    new->data = data;
    new->next = NULL;
    ptr->next = new;
    return head;
}

// deletion
struct Node * deleteFirst(struct Node *head){

    if(head == NULL){
        return NULL;
    }
    struct Node *temp = head; // tracking the first node
    head = head->next;
    free(temp);
    temp = NULL;
    return head;
}

struct Node * deleteBetween(struct Node *head , int index){
    if(head==NULL || index < 0){
        return NULL;
    }
    
    if(index == 1){
        return deleteFirst(head);
    }
    
    struct Node * temp = head;
    struct Node * deleteNode = head->next;
    for(int i = 0 ; i<index-2 ; i++){
        temp = temp -> next;
        deleteNode = deleteNode->next;
    }
    
    temp->next = deleteNode->next;
    deleteNode->next = NULL;
    free(deleteNode);
    return head;
}

struct Node * deleteEnd(struct Node *head){
    if(head == NULL){
        return NULL;
    }
    if(head->next == NULL){
        free(head);
        return NULL;
    }
    
    struct Node * p = head;
    struct Node * q = head->next;
    
    while(q->next){
        p = p->next;
        q = q->next;
    }
    
    p->next = NULL;
    free(q);
    return head;
}

// Inserting a node in to the sorting LL
struct Node * insertNodeSortLL(struct Node *head , int data){
    if(head == NULL){
        return NULL;
    }
    struct Node * p = head;
    struct Node * q = NULL;
    
    
    if(data < p->data){
        return insertAtFirst(head ,data);
    }
    
    while(p && !(data < p->data) ){ // 23 < 30
        q = p;
        p = p->next;
    }
    struct Node * newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    
    q->next = newNode;
    newNode->next = p;
    
    //       q->  n->   p
    // 3 10 20 23 30 40
    
    return head;
}

struct Node * removeDuplicates(struct Node * head){
    if(!head){
        return NULL;
    }
    if(!head->next){
        return head;
    }
    
    struct Node *p = head;
    struct Node *temp ;
    
    while(p!=NULL && p->next!=NULL){
        if(p->data == p->next->data){
            temp = p->next;
            p->next = temp->next;
            free(temp);
        }else{
            p=p->next;
        }
    }
    
    return head;
}


struct Node * reverseList(struct Node *head , int size){
    
    if(!head || !head->next){
        return 0;
    }
    
    struct Node *p = head;
    int A[size];
    int i =0;
    
    while(p){
        A[i] = p->data;
        p = p->next;
        i++;
    }
    
    p = head;
    while(p){
        p->data = A[i-1];
        p = p->next;
        i--;
    }
    return head;
}

struct Node * revserListSlidingPointers(struct Node * head){
    
    if(!head || !head->next){
        return head;
    }
    
    struct Node *p = head;   
    struct Node *q = NULL;   
    struct Node *r = NULL;   
    
    while(p){
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    
    head = q;
    return head;
}

struct Node * revserListRecursion(struct Node * q , struct Node * p){
    if(p!=NULL){
        revserListRecursion(p , p->next);
        p->next = q;
    }else {
        first = q;
    }
    return first;
}

// Concatenating two list 
struct Node * concatenteList(struct Node *head , struct Node *second){
    struct Node * p = head;
    
    while(p->next){
        p = p->next;
    }
    
    p->next = second;
    second = NULL;
    
    return head;
}


// Merge Two sorted list into one sorted list
//Time complexity : O(m + n)
// It doesn't require extra space like in the case of array it requires extra space
struct Node * mergeSortedList(struct Node *f , struct Node *s){
    struct Node * t;
    struct Node * l;
    
    if(f->data < s->data){
        t = l = f;   
        f = f->next;
        l->next = NULL;
    }else {
        t = l = s;
        s = s->next;
        l->next = NULL;
    }
    
    while(f && s){
        if(f->data < s->data){
            l->next = f;
            l = f;
            f = f->next;
            l->next = NULL;
        }else {
            l->next = s;
            l= s;
            s = s->next;
            l->next = NULL;
        }
    }
    
    if(f){
        l->next = f;
    }else{
        l->next = s;
    }
    
    return t;
    
}


int isLoop(struct Node * head){
    struct Node * p, *q;
    p = q = head;
    
    do {
        p = p->next;
        q = q->next;
        q = q? q->next : q;
    }while(p && q && p !=q);
    
    return (p==q) ? 1 : 0;
}

// Time complexity : O(n);
int middleElement1(struct Node *p){
    int length = 0;
    while (p){
        length++;
        p = p->next;
    }
 
    int index = (int)ceil(length/2.0);
    struct Node* q = first;
    for (int i=0; i<index-1; i++){
        q = q->next;
    }
    return q->data;
}

// Time complexity : O(n);
int middleElement2(struct Node *p){
    struct Node *q = p;
    while (q){
        q = q->next;
        if (q){
            q = q->next;
        }
        if (q){
            p = p->next;
        }
    }
    return p->data;
}

int middleElement3(struct Node *head){
    // using stack;
}


int main()
{
    int A[] = {1 , 2 ,3 ,4 ,5 , 6 , 7 , 9   } ;
    int B[] = {4 , 7 , 11 , 12 };
    
    
    // Creation of LL
    create(A , sizeof(A)/sizeof(A[0]));
    createSecondList(B , 4);
    
    
    
    // LL traversing
    printf("TAIL RECURSION\n");
    traverseT(first);
    
    printf("\n");
    printf("TAIL RECURSION\n");
    traverseT(second);
    
    
    
    // printf("\n");
    
    // printf("HEAD RECURSION\n");
    // traverseH(first);
    
    // printf("\n");
    
    // printf("COUNT NODES IN LL\n");
    // printf("COUNT : %d" , countNodes(first));
    
    // printf("\n");
    
    // printf("COUNT NODES IN LL USING RECURSION\n");
    // printf("COUNT : %d" , countRecursive(first));
    
    // printf("\n");
    
    // printf("SUM NODE'S DATA LL\n");
    // printf("SUM : %d" , sumNodes(first));
    
    // printf("\n");
    
    // printf("SUM NODE'S DATA LL USING RECURSION\n");
    // printf("SUM : %d" , sumRecursive(first));
    
    // printf("\n");
    
    // printf("MAX NUMBER IN NODES\n");
    // printf("MAX NUMBER : %d" , maxNum(first));
    
    // printf("\n");
    
    // int n;
    // printf("Enter the No to search : ");
    // scanf("%d" , &n);
    // printf("%d" , searchElementRecursive(first , n));
    // searchElement(first , n);
    
    // printf("\n");
    // printf("Insertion At First.\n");
    
    
    // printf("\n");
    // first = insertAtFirst(first , 40);
    // traverseT(first);
    
    // printf("\n");
    // printf("Insertion At between.\n");
    
    // printf("\n");
    // first = insertAtBetween(first , 50 , 1);
    // traverseT(first);
    
    // printf("\n");
    // printf("Insertion At End.\n");
    
    // printf("\n");
    // first = insertAtEnd(first , 60 );
    // traverseT(first);
    
    // printf("\n");
    // printf("Delete First : \n");
    // first = deleteFirst(first);
    // traverseT(first);
    
    // printf("\n");
    // printf("Delete Between : \n");
    // first = deleteBetween(first , 2);
    // traverseT(first);
    
    // printf("\n");
    // printf("Delete End : \n");
    // first = deleteEnd(first);
    
    // traverseT(first);
    
    
    // printf("\n");
    // printf("Insert a node in sorted LL : \n");
    // first = insertNodeSortLL(first , 3);
    // traverseT(first);
    
    // printf("\n");
    // printf("Remove duplicates : \n");
    // first = removeDuplicates(first);
    // traverseT(first);
    
    // printf("\n");
    // printf("Reverse List : \n");
    // int size = countNodes(first);
    // first = reverseList(first , size);
    // traverseT(first);
    
    // printf("\n");
    // printf("Reverse List : \n");
    // first = revserListSlidingPointers(first);
    // traverseT(first);
    
    // printf("\n");
    // printf("Reverse List : \n");
    // first = revserListSlidingPointers(first);
    // traverseT(first);
    
    // printf("\n");
    // printf("Reverse List : \n");
    // first = revserListRecursion( NULL , first);
    // traverseT(first);
    
    // printf("\n");
    // printf("Concatenating List : \n");
    // first = concatenteList( first , second);
    // traverseT(first);
    
    // printf("\n");
    // printf("Merge Two Sorted List : \n");
    // first = mergeSortedList( first , second);
    // traverseT(first);
    
    
    // printf("\n");
    // printf(" Loop or Linear: \n");
    // printf("%d",isLoop(  first));
     
    printf("\n middleElement : %d" , middleElement1(first));
    printf("\n middleElement : %d" , middleElement2(first));
     
    return 0;
}